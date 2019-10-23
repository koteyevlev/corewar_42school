/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_g_or.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 21:33:43 by nalexand          #+#    #+#             */
/*   Updated: 2019/08/16 05:01:07 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	7: or {T_REG | T_DIR | T_IND}, {T_REG | T_DIR | T_IND}, {T_REG} DSIZE 4
**
**	По своей сути эта операция полностью аналогична операции and.
**	Только в данном случае «побитовое И» заменяется на «побитовое ИЛИ».
*/

static void	or_print_process(t_core *core, t_list *pc, t_arg *args)
{
	print_process_header(core, pc);
	ft_printf("%d %d r%d\n", args[0].value, args[1].value, args[2].value);
}

void		cw_or(void *core, t_list *pc)
{
	t_arg	args[3];

	init_args((t_arg *)args, pc, 3);
	args[0].value = get_operand(args[0], pc, IDX_MOD);
	args[1].value = get_operand(args[1], pc, IDX_MOD);
	PC->reg[args[2].value - 1] = args[0].value | args[1].value;
	if (PC->reg[args[2].value - 1] == 0)
		PC->carry = TRUE;
	else
		PC->carry = FALSE;
	if (((t_core *)core)->out == 4 || ((t_core *)core)->out == 5)
		or_print_process((t_core *)core, pc, (t_arg *)args);
	mov_pc((t_core *)core, pc, adr(CURRENT + 2
	+ args[0].size + args[1].size + args[2].size));
}
