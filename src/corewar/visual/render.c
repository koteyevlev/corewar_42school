/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 18:57:50 by nalexand          #+#    #+#             */
/*   Updated: 2019/08/16 05:16:35 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	print_arena_content(t_core *core, int i, int y, int x)
{
	t_attr	*attr;
	int		currnet_attr;

	attr = &core->visual.attrs[i];
	if (attr->live_player_id)
		currnet_attr = COLOR_PAIR(attr->live_player_id
		+ attr->pc_here) | A_BOLD;
	else
	{
		if (attr->light)
		{
			currnet_attr = COLOR_PAIR(attr->index + attr->pc_here) | A_BOLD;
			attr->light--;
		}
		else
			currnet_attr = COLOR_PAIR(attr->index + attr->pc_here);
	}
	wattron(core->visual.win, currnet_attr);
	mvwprintw(core->visual.win, y, x, "%02x", core->map[i]);
	wattroff(core->visual.win, currnet_attr);
}

static void	render_arena(t_core *core)
{
	int		i;
	int		x;
	int		y;

	i = 0;
	x = 4;
	y = 2;
	while (i < MEM_SIZE)
	{
		print_arena_content(core, i, y, x);
		x += 3;
		if (i && (i + 1) % 64 == 0)
		{
			y++;
			x = 4;
		}
		i++;
	}
}

static void	handle_buttons(t_core *core)
{
	core->visual.button = wgetch(core->visual.win);
	if (core->visual.button == ESC)
		cw_clear_exit(core, NULL, 1);
	else if (core->visual.button == SPACE)
		core->visual.running = !core->visual.running;
	else if (core->visual.button == S_BTN)
		core->visual.running = 1;
	else if (core->visual.button == R_BTN && core->visual.speed < START_SLEEP)
		core->visual.speed <<= 1;
	else if (core->visual.button == F_BTN && core->visual.speed > 1)
		core->visual.speed >>= 1;
	render_info(core);
}

void		show_fight_field(t_core *core)
{
	render_arena(core);
	render_info(core);
	wrefresh(core->visual.win);
	usleep(START_SLEEP / core->visual.speed);
	if (core->visual.button == S_BTN)
		core->visual.running = 0;
	if (!core->visual.running)
		while (!core->visual.running)
			handle_buttons(core);
	else
		handle_buttons(core);
}
