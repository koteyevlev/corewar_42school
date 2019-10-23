/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrystin <skrystin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 21:10:58 by nalexand          #+#    #+#             */
/*   Updated: 2019/08/17 17:14:10 by skrystin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	translator(char **f, int y, char *file, t_as *all)
{
	if (!(all = (t_as *)malloc(sizeof(t_as))))
	{
		ft_arraydel((void ***)&f);
		first_error("Can't read source file ", file, 0);
	}
	ft_bzero(all, sizeof(t_as));
	while (f[y])
	{
		check_to_valid(f[y], 0, &all, f);
		if (to_ignore(f[y], 0) && y++ != -2)
			continue;
		if (ft_strstr(f[y], NAME_CMD_STRING) || ft_strstr(f[y],
		COMMENT_CMD_STRING) || all->read)
			add_names(&all, &y, f, 0);
		else if (add_label(&all, f, f[y], y) && !to_ignore(f[y], 0))
			add_command(&all, 0, f, f[y]);
		y++;
	}
	label_to_nbr(&all, all->labels, all->comm, 0);
	print_to_bytecode(all, file, all->comm, code_size(all->comm, 0));
	delete_asm_all(&all, &f);
}

int		main(int ac, char **av)
{
	char	*file;
	char	**per_str;
	int		fd;

	if (ac == 1)
	{
		ft_printf("Usage: ./asm <sourcefile.s>\n");
		return (0);
	}
	if ((fd = open(av[ac - 1], O_RDONLY)) < 3)
		first_error("Can't read source file ", av[ac - 1], 0);
	if (ft_read_to_str(fd, &file, 10) == -1 || !ft_strlen(file)
	|| file[ft_strlen(file) - 1] != '\n')
		first_error("Can't read source file ", av[ac - 1], &file);
	if (!(per_str = ft_strsplit(file, '\n')))
		first_error("Can't read source file ", av[ac - 1], &file);
	free(file);
	close(fd);
	translator(per_str, 0, av[ac - 1], 0);
	return (0);
}
