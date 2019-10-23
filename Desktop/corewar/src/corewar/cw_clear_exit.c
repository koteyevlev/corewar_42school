/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_clear_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 18:01:23 by nalexand          #+#    #+#             */
/*   Updated: 2019/08/15 19:15:31 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	Функция выхода из программы.
*/

static void	clear_players(t_core *core)
{
	int		i;

	i = MAX_PLAYERS - 1;
	while (i >= 0)
		free(core->players[--i]);
}

void		cw_clear_exit(t_core *core, const char *message, const int fd)
{
	if (core->visu_mod)
	{
		clear();
		endwin();
	}
	ft_lstdel(&core->input, ft_lstclear);
	ft_lstdel(&core->pcs, ft_lstclear);
	clear_players(core);
	if (message)
		ft_putendl_fd(message, fd);
	if (fd == 2)
		exit(EXIT_FAILURE);
	exit(EXIT_SUCCESS);
}
