/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 01:58:50 by nalexand          #+#    #+#             */
/*   Updated: 2019/08/16 05:17:49 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	put_status(t_core *core)
{
	wattron(core->visual.win, COLOR_PAIR(INFO) | A_BOLD);
	if (core->visual.running)
		mvwprintw(core->visual.win, 2, WIN_INFO_POSX, "** RUNNING **");
	else
		mvwprintw(core->visual.win, 2, WIN_INFO_POSX, "** PAUSED ** ");
	mvwprintw(core->visual.win, 4, WIN_INFO_POSX,
	"Speed:            x%-5d", core->visual.speed);
	mvwprintw(core->visual.win, 6, WIN_INFO_POSX,
	"Cycle :           %d", core->cycle_after_start);
	mvwprintw(core->visual.win, 8, WIN_INFO_POSX,
	"Processes :       %-10d", core->current_process_count);
	mvwprintw(core->visual.win, 10, WIN_INFO_POSX,
	"CYCLE_TO_DIE :    %-4d", core->cycle_to_die);
	mvwprintw(core->visual.win, 11, WIN_INFO_POSX,
	"CYCLE_DELTA :     %d", CYCLE_DELTA);
	mvwprintw(core->visual.win, 12, WIN_INFO_POSX,
	"NBR_LIVE :        %d", NBR_LIVE);
	mvwprintw(core->visual.win, 13, WIN_INFO_POSX,
	"MAX_CHECKS :      %d", MAX_CHECKS);
}

void		render_info(t_core *core)
{
	int		i;

	put_status(core);
	i = 0;
	while (core->players[i])
	{
		mvwprintw(core->visual.win, core->players[i]->info_posy,
		WIN_INFO_POSX, "   Last life : %d", core->players[i]->last_live);
		mvwprintw(core->visual.win, core->players[i]->info_posy + 1,
		WIN_INFO_POSX, "   Lives in a current period : %-10d",
		core->players[i]->lives);
		i++;
	}
	wattroff(core->visual.win, COLOR_PAIR(INFO) | A_BOLD);
}
