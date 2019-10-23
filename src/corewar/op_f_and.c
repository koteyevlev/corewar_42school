/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_f_and.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 21:32:36 by nalexand          #+#    #+#             */
/*   Updated: 2019/08/16 05:01:01 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	6: and {T_REG | T_DIR | T_IND}, {T_REG | T_DIR | T_IND}, {T_REG} DSIZE 4
**
**	Выполняет операцию «побитовое И» для значений первых двух аргументов
**	и записывает полученный результат в регистр,
**	переданный в качестве третьего аргумента.
**	Если записанный результат был равен нулю,
**	то значение carry нужно установить равным 1.
**	Если результат был не нулевой, то — равным 0.
**
**		Аргумент #1 / Аргумент #2 — T_REG
**		- Значение берется из регистра, переданного в качестве аргумента.
**
**		Аргумент #1 / Аргумент #2 — T_DIR
**		- В этом случае используется переданное
**		в качестве аргумента числовое значение.
**
**		Аргумент #1 / Аргумент #2 — T_IND
**		- Если тип аргумента T_IND, то необходимо установить адрес,
**		с которого будет считано 4 байта.
**		Адрес определяется следующим образом:
**		текущая позиция + <АРГУМЕНТ> % IDX_MOD.
**		Считанное по этому адресу 4-байтовое число и будет требуемым значением.
*/

static void	and_print_process(t_core *core, t_list *pc, t_arg *args)
{
	print_process_header(core, pc);
	ft_printf("%d %d r%d\n", args[0].value, args[1].value, args[2].value);
}

void		cw_and(void *core, t_list *pc)
{
	t_arg	args[3];

	init_args((t_arg *)args, pc, 3);
	args[0].value = get_operand(args[0], pc, IDX_MOD);
	args[1].value = get_operand(args[1], pc, IDX_MOD);
	PC->reg[args[2].value - 1] = args[0].value & args[1].value;
	if (PC->reg[args[2].value - 1] == 0)
		PC->carry = TRUE;
	else
		PC->carry = FALSE;
	if (((t_core *)core)->out == 4 || ((t_core *)core)->out == 5)
		and_print_process((t_core *)core, pc, (t_arg *)args);
	mov_pc((t_core *)core, pc, adr(CURRENT + 2
	+ args[0].size + args[1].size + args[2].size));
}
