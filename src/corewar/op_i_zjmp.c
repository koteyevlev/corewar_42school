/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_i_zjmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 21:35:06 by nalexand          #+#    #+#             */
/*   Updated: 2019/08/16 18:01:12 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	9: zjmp {T_DIR} DSIZE 2
**
**	Эта та самая функция, на работу которой влияет значение флага carry.
**	Если оно равно 1, то функция обновляет значение PC на
**	адрес — текущая позиция + <ПЕРВЫЙ_АРГУМЕНТ> % IDX_MOD.
**
**	То есть zjmp устанавливает куда должна переместиться каретка
**	для выполнения следующей операции.
**
**	Это позволяет нам перепрыгивать в памяти на нужную позицию,
**	а не выполнять всё по порядку.
**	Если значение carry равно нулю, перемещение не выполняется.
*/

static void	zjmp_print_process(t_core *core, t_list *pc, t_arg *args)
{
	print_process_header(core, pc);
	ft_printf("%d", args->value);
	if (PC->carry == 1)
		ft_printf(" OK\n");
	else
		ft_printf(" FAILED\n");
}

void		cw_zjmp(void *core, t_list *pc)
{
	t_arg	arg;

	init_args(&arg, pc, 1);
	if (PC->carry)
		mov_pc((t_core *)core, pc, adr(CURRENT + arg.value % IDX_MOD));
	else
		mov_pc((t_core *)core, pc, adr(CURRENT + 1 + arg.size));
	if (((t_core *)core)->out == 4 || ((t_core *)core)->out == 5)
		zjmp_print_process((t_core *)core, pc, &arg);
}
