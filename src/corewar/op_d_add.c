/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_d_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 21:31:08 by nalexand          #+#    #+#             */
/*   Updated: 2019/08/16 05:00:43 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	4: add {T_REG}, {T_REG}, {T_REG} DSIZE 4
**
**	Задача операции add:
**	Просуммировать значение из регистра,
**	который был передан как первый аргумент,
**	с значением регистра, который был передан как второй аргумент.
**	Записать полученный результат в регистр,
**	который был передан как третий аргумент.
**	Если полученная сумма, которую мы записали
**	в третий аргумент была равна нулю,
**	то устанавливаем carry в 1. А если сумма была не нулевой — в 0.
*/

static void	print_process(t_core *core, t_list *pc, t_arg *args)
{
	print_process_header(core, pc);
	ft_printf("r%d r%d r%d\n", args[0].value, args[1].value, args[2].value);
}

void		cw_add(void *core, t_list *pc)
{
	t_arg	args[3];

	init_args((t_arg *)args, pc, 3);
	PC->reg[args[2].value - 1] = PC->reg[args[0].value - 1]
	+ PC->reg[args[1].value - 1];
	if (PC->reg[args[2].value - 1] == 0)
		PC->carry = TRUE;
	else
		PC->carry = FALSE;
	if (((t_core *)core)->out == 4 || ((t_core *)core)->out == 5)
		print_process((t_core *)core, pc, (t_arg *)args);
	mov_pc((t_core *)core, pc, adr(CURRENT + 2
	+ args[0].size + args[1].size + args[2].size));
}
