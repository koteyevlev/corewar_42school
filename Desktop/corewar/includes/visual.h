/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 05:25:42 by nalexand          #+#    #+#             */
/*   Updated: 2019/08/16 05:57:46 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUAL_H
# define VISUAL_H

# include <ncurses.h>
# include "common.h"
# define ESC 					27
# define SPACE 					32
# define S_BTN 					's'
# define R_BTN 					'r'
# define F_BTN 					'f'

# define INFO					5
# define BACKGROUND				6
# define BORDER 				7
# define COLOR_GRAY				8
# define GRAY					9
# define GREEN					10
# define YELLOW					11
# define REDD					12
# define CYAN					13
# define GRAY_CURSOR			14
# define GREEN_CURSOR			15
# define YELLOW_CURSOR			16
# define RED_CURSOR				17
# define CYAN_CURSOR			18
# define LIVE_GREEN				19
# define LIVE_YELLOW			20
# define LIVE_RED				21
# define LIVE_CYAN				22
# define LIVE_GREEN_CURSOR		24
# define LIVE_YELLOW_CURSOR		25
# define LIVE_RED_CURSOR		26
# define LIVE_CYAN_CURSOR		27

# define WIN_WIDTH				244
# define WIN_HEIGHT 			68
# define WIN_POSX 				2
# define WIN_POSY 				1
# define WIN_INFO_BORDER 		198
# define WIN_INFO_POSX 			(WIN_INFO_BORDER + 4)
# define START_SLEEP 			65536
# define LIGHT_TIME 			100

typedef struct		s_attr
{
	int				index;
	int				light;
	int				live_player_id;
	int				pc_here;
}					t_attr;

typedef struct		s_visual
{
	t_attr			attrs[MEM_SIZE];
	WINDOW			*win;
	int				y_ofset;
	int				running;
	int				row;
	int				col;
	int				speed;
	char			button;
}					t_visual;

#endif
