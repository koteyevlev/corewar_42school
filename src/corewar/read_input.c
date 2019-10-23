/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 18:45:02 by nalexand          #+#    #+#             */
/*   Updated: 2019/08/16 18:13:12 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int	put_size_error(const int size, const char *file)
{
	char	*tmp;

	tmp = NULL;
	ft_putstr_fd("Error: File ", 2);
	ft_putstr_fd(file, 2);
	ft_putstr_fd(" has too large a code (", 2);
	ft_putnbr_fd(size, 2);
	ft_putstr_fd(" bytes > ", 2);
	ft_putnbr_fd(CHAMP_MAX_SIZE, 2);
	ft_putstr_fd(" bytes)\n", 2);
	return (0);
}

static int	puterr(const char *file, const char *error)
{
	ft_putstr_fd("Error: File ", 2);
	ft_putstr_fd(file, 2);
	ft_putendl_fd(error, 2);
	return (0);
}

static int	validate_input(char *input, ssize_t size, char *file)
{
	if (size < (ssize_t)EXEC_CODE_OFSET)
		return (puterr(file, " is too small to be a champion"));
	else if (size - (ssize_t)EXEC_CODE_OFSET > (ssize_t)CHAMP_MAX_SIZE)
		return (put_size_error(size - EXEC_CODE_OFSET, file));
	if (GET_VAL(input, int) != COREWAR_EXEC_MAGIC)
		return (puterr(file, " has an invalid header"));
	if (GET_VAL(input + CODE_SIZE_OFSET, int)
	!= size - (ssize_t)EXEC_CODE_OFSET)
		return (puterr(file, " has a code size that differ"\
		" from what its header says"));
	return (1);
}

static void	fd_error_exit(t_core *core, const char *file)
{
	ft_putstr_fd("Can't read source file ", 2);
	ft_printf("%s\n", file);
	cw_clear_exit(core, NULL, 2);
}

void		read_input(t_core *core, int ac, char **av)
{
	int		fd;
	int		i;
	t_list	*node;
	ssize_t	ret;

	i = core->arg_ofset;
	if (ac < 2 || core->arg_ofset == ac - 1)
		cw_clear_exit(core, NULL, put_usage(1));
	while (++i < ac)
		if (ft_strequ("-n", av[i]) && i + 1 < ac)
			i++;
		else
		{
			if ((fd = open(av[i], O_RDONLY)) < 3)
				fd_error_exit(core, av[i]);
			if (!(node = ft_lstnew(NULL, 0))
			|| (ret = ft_read_to_str(fd, (char **)&node->content, 10)) < 0)
				cw_clear_exit(core, MEM_ERROR, 2);
			if (!(validate_input(node->content, ret, av[i])))
				cw_clear_exit(core, NULL, 2);
			core->war_count++;
			if (core->war_count > MAX_PLAYERS)
				cw_clear_exit(core, "Too many champions", 1);
			ft_lstadd(&core->input, node);
		}
}
