/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 19:12:39 by nalexand          #+#    #+#             */
/*   Updated: 2019/08/16 18:01:05 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	validate_op_code(t_core *core, t_list *pc)
{
	PC->op = BYTE(CURRENT);
	if (PC->op > 0 && PC->op < 17)
	{
		PC->op_info = &g_op_tab[PC->op - 1];
		PC->cycle_for_op = PC->op_info->cycle;
	}
	else
	{
		mov_pc(core, pc, adr(CURRENT + 1));
		PC->op = 0;
	}
}

static void	solve_operation(t_core *core, t_list *pc)
{
	int		ofset;

	PC->cycle_for_op--;
	if (PC->cycle_for_op == 0)
	{
		if ((ofset = validate_operation(pc)))
			mov_pc(core, pc, adr(CURRENT + ofset));
		else
			PC->op_info->process(core, pc);
		PC->op_info = NULL;
		PC->op = 0;
	}
}

static void	pc_process(t_core *core)
{
	t_list	*pc;

	pc = core->pcs;
	while (pc)
	{
		PC->cycle++;
		if (!PC->op)
			validate_op_code(core, pc);
		if (PC->op_info)
			solve_operation(core, pc);
		if (PC->nb == core->print_pc)
			print_processes(core, pc, 1);
		pc = pc->next;
	}
}

void		game_cycle(t_core *core)
{
	int		cycle_to_die;

	core->cycle_to_die = CYCLE_TO_DIE;
	cycle_to_die = core->cycle_to_die;
	while (core->pcs)
	{
		if (core->cycle_after_start == core->dump
		|| core->cycle_after_start == core->d)
			print_dump(core, 1, 1);
		if (cycle_to_die <= 0)
			game_check(core, &cycle_to_die);
		if (core->visu_mod)
			show_fight_field(core);
		pc_process(core);
		core->cycle_after_start++;
		cycle_to_die--;
		if (core->out == 2)
			ft_printf("It is now cycle %d\n", core->cycle_after_start);
	}
}
