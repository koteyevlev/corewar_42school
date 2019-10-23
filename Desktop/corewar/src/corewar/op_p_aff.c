/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_p_aff.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 21:41:59 by nalexand          #+#    #+#             */
/*   Updated: 2019/08/14 22:38:25 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	16: aff {T_REG} DSIZE 4
**
**	Эта операция берет значение из регистра,
**	который был передан в качестве единственного аргумента.
**	Приводит его к типу char. И выводит на экран как ASCII-символ.
**
**	В оригинальной виртуальной машине corewar по умолчанию
**	режим отображения вывода операции aff выключен.
**	Чтобы его включить нужно воспользоваться флагом -a.
*/

static void	print_process(t_core *core, t_list *pc, t_arg *arg)
{
	print_process_header(core, pc);
	ft_printf("r%d\n", arg->value);
}

void		cw_aff(void *core, t_list *pc)
{
	t_arg	arg;

	init_args(&arg, pc, 1);
	if (((t_core *)core)->print_aff)
	{
		write(1, &PC->reg[arg.value - 1], 1);
		if (((t_core *)core)->out == 4 || ((t_core *)core)->out == 5)
			print_process((t_core *)core, pc, &arg);
	}
	mov_pc((t_core *)core, pc, adr(CURRENT + 2 + arg.size));
}
