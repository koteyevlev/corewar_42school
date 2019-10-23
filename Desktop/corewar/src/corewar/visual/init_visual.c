/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_visual.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 18:47:35 by nalexand          #+#    #+#             */
/*   Updated: 2019/08/16 22:46:05 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	init_attr(t_core *core)
{
	int			i;
	int			j;
	t_player	*player;

	i = 0;
	while (i < MEM_SIZE)
		core->visual.attrs[i++].index = GRAY;
	i = 0;
	while (i < core->war_count)
	{
		player = core->players[i];
		j = player->start_position;
		while (j < player->start_position + player->code_size)
			core->visual.attrs[j++].index = GRAY + player->id;
		core->visual.attrs[player->start_position].pc_here = 5;
		i++;
	}
}

static void	init_colors(void)
{
	init_color(COLOR_GRAY, 355, 355, 355);
	init_pair(INFO, COLOR_WHITE, COLOR_BLACK);
	init_pair(BACKGROUND, COLOR_BLACK, COLOR_BLACK);
	init_pair(BORDER, 0, COLOR_GRAY);
	init_pair(GRAY, COLOR_GRAY, 0);
	init_pair(GREEN, COLOR_GREEN, 0);
	init_pair(YELLOW, COLOR_YELLOW, 0);
	init_pair(REDD, COLOR_RED, 0);
	init_pair(CYAN, COLOR_CYAN, 0);
	init_pair(GRAY_CURSOR, COLOR_BLACK, COLOR_GRAY);
	init_pair(GREEN_CURSOR, COLOR_BLACK, COLOR_GREEN);
	init_pair(YELLOW_CURSOR, COLOR_BLACK, COLOR_YELLOW);
	init_pair(RED_CURSOR, COLOR_BLACK, COLOR_RED);
	init_pair(CYAN_CURSOR, COLOR_BLACK, COLOR_CYAN);
	init_pair(LIVE_GREEN_CURSOR, COLOR_GREEN, COLOR_GREEN);
	init_pair(LIVE_YELLOW_CURSOR, COLOR_YELLOW, COLOR_YELLOW);
	init_pair(LIVE_RED_CURSOR, COLOR_RED, COLOR_RED);
	init_pair(LIVE_CYAN_CURSOR, COLOR_CYAN, COLOR_CYAN);
	init_pair(LIVE_GREEN, COLOR_GREEN, 0);
	init_pair(LIVE_YELLOW, COLOR_YELLOW, 0);
	init_pair(LIVE_RED, COLOR_RED, 0);
	init_pair(LIVE_CYAN, COLOR_CYAN, 0);
}

static void	draw_border(t_core *core)
{
	int		y;
	int		x;

	wattron(core->visual.win, COLOR_PAIR(BACKGROUND));
	y = WIN_POSY;
	while (y < WIN_HEIGHT)
	{
		x = WIN_POSX - 1;
		while (x < WIN_WIDTH)
			mvwprintw(core->visual.win, y, x++, " ");
		y++;
	}
	wattron(core->visual.win, COLOR_PAIR(BORDER));
	wborder(core->visual.win, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
	y = WIN_POSY;
	while (y < WIN_HEIGHT)
		mvwprintw(core->visual.win, y++, WIN_INFO_BORDER, " ");
	wattroff(core->visual.win, COLOR_PAIR(BORDER));
}

static void	draw_players(t_core *core)
{
	int		i;
	int		x;
	int		y;

	i = 0;
	y = 15;
	x = WIN_INFO_POSX;
	while (core->players[i])
	{
		wattron(core->visual.win,
		COLOR_PAIR(GRAY + core->players[i]->id) | A_BOLD);
		mvwprintw(core->visual.win, y++, x, "Player %d: %.20s",
		core->players[i]->nb, core->players[i]->name);
		core->players[i++]->info_posy = y++;
		y += 2;
	}
	core->visual.y_ofset = y;
	wattroff(core->visual.win,
	COLOR_PAIR(GRAY + core->players[i - 1]->id) | A_BOLD);
}

void		init_visual(t_core *core)
{
	core->visual.speed = 1;
	initscr();
	core->visual.win = newwin(WIN_HEIGHT, WIN_WIDTH, WIN_POSY, WIN_POSX);
	nodelay(core->visual.win, true);
	curs_set(false);
	noecho();
	use_default_colors();
	start_color();
	init_colors();
	core->visual.button = SPACE;
	init_attr(core);
	draw_border(core);
	draw_players(core);
}
