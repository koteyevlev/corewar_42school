/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_a_live.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 20:01:46 by nalexand          #+#    #+#             */
/*   Updated: 2019/08/16 05:00:25 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	1: live {T_DIR} DSIZE 4
**
**	Засчитывает, что каретка, которая выполняет операцию live, жива.
**	Если указанный в качестве аргумента операции
**	live номер совпадает с номером игрока,
**	то она засчитывает, что это игрок жив.
**	Например, если значение аргумента равно -2, значит игрок с номером 2 жив.
*/

static void	print_process(t_core *core, t_list *pc, t_arg *arg)
{
	print_process_header(core, pc);
	ft_printf("%d", arg->value);
	ft_putchar('\n');
}

static void	find_player(t_core *core, int value, int pos)
{
	t_player	**players;
	int			i;

	players = core->players;
	i = 0;
	while (players[i])
	{
		if (value == -players[i]->nb)
		{
			core->last_player = players[i];
			if (core->out == 1)
				ft_printf("Player %d (%s) is said to be alive\n",
				players[i]->nb, players[i]->name);
			if (core->visu_mod)
			{
				core->visual.attrs[pos].live_player_id =
				players[i]->id + CYAN_CURSOR;
				players[i]->last_live = core->cycle_after_start;
				players[i]->lives++;
			}
			break ;
		}
		i++;
	}
}

void		cw_live(void *core, t_list *pc)
{
	t_arg		arg;

	init_args(&arg, pc, 1);
	find_player((t_core *)core, arg.value, CURRENT);
	if (((t_core *)core)->out == 4 || ((t_core *)core)->out == 5)
		print_process((t_core *)core, pc, &arg);
	PC->cycle = 0;
	((t_core *)core)->live_count++;
	mov_pc((t_core *)core, pc, adr(CURRENT + 1 + arg.size));
}
