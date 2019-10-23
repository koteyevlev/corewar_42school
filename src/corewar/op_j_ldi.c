/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_j_ldi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 21:35:52 by nalexand          #+#    #+#             */
/*   Updated: 2019/08/16 05:01:42 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	10: ldi {T_REG | T_DIR | T_IND}, {T_REG | T_DIR}, {T_REG} DSIZE 2
**
**	Данная операция записывает значение в регистр,
**	который был ей передан как третий параметр.
**	Значением, которая она записывает, являются 4 байта.
**	Эти 4 байта она считывает по адресу,
**	который формируется по следующему принципу:
**	текущая позиция + (<ЗНАЧЕНИЕ_ПЕРВОГО_АРГУМЕНТА>
**	+ <ЗНАЧЕНИЕ_ВТОРОГО_АРГУМЕНТА>) % IDX_MOD.
**
**	Поскольку операция может принимать разные типы
**	первого и второго аргументов,
**	рассмотрим способ получения значения для каждого типа:
**
**		Аргумент #1 / Аргумент #2 — T_REG
**		- Значение содержится в регистре,
**		который был передан в качестве параметра.
**
**		Аргумент #1 / Аргумент #2 — T_DIR
**		- В данном случае у нас аргумент уже содержит свое значение.
**
**		Аргумент #1 — T_IND
**		- Чтобы получить значение этого аргумента,
**		нужно считать 4 байта по адресу
**		— текущая позиция + <ПЕРВЫЙ_АРГУМЕНТ> % IDX_MOD.
*/

static void	ldi_print_process(t_core *core, t_list *pc, t_arg *args)
{
	int		ofset;

	ofset = print_process_header(core, pc);
	ft_printf("%d %d r%d\n", args[0].value, args[1].value, args[2].value);
	while (--ofset)
		ft_putchar(' ');
	ft_printf("| -> load from %d + %d = %d (with pc and mod %d)\n",
	args[0].value, args[1].value,
	args[0].value + args[1].value,
	CURRENT + (args[0].value + args[1].value) % IDX_MOD);
}

void		cw_ldi(void *core, t_list *pc)
{
	t_arg	args[3];

	init_args((t_arg *)args, pc, 3);
	args[0].value = get_operand(args[0], pc, IDX_MOD);
	args[1].value = get_operand(args[1], pc, IDX_MOD);
	PC->reg[args[2].value - 1] =
	get_value(PC->map, adr(CURRENT
	+ (args[0].value + args[1].value) % IDX_MOD), sizeof(int));
	if (((t_core *)core)->out == 4 || ((t_core *)core)->out == 5)
		ldi_print_process((t_core *)core, pc, (t_arg *)args);
	mov_pc((t_core *)core, pc, adr(CURRENT + 2
	+ args[0].size + args[1].size + args[2].size));
}
