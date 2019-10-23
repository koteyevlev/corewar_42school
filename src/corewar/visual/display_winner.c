/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_winner.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 22:05:54 by nalexand          #+#    #+#             */
/*   Updated: 2019/08/16 05:13:51 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void			display_winner(t_core *core)
{
	t_player	*winner;

	if (core->last_player)
		winner = core->last_player;
	else
		winner = core->players[0];
	wattron(core->visual.win, COLOR_PAIR(INFO) | A_BOLD);
	mvwprintw(core->visual.win, core->visual.y_ofset,
	WIN_INFO_POSX, "THE WINNER IS: ");
	wattron(core->visual.win, COLOR_PAIR(GRAY + winner->id) | A_BOLD);
	mvwprintw(core->visual.win, core->visual.y_ofset,
	WIN_INFO_POSX + 15, "%.20s!!!", winner->name);
	wrefresh(core->visual.win);
	while (core->visual.button != ESC)
		core->visual.button = wgetch(core->visual.win);
	cw_clear_exit(core, NULL, 0);
}
