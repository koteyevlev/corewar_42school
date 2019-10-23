/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_debug.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 18:45:18 by nalexand          #+#    #+#             */
/*   Updated: 2019/08/16 18:01:36 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	print_dump(t_core *core, int bar, int exit)
{
	int		i;
	int		j;
	int		line_size;
	int		delim;

	line_size = MEM_SIZE / ((core->dump >= 0) ? 128 : 64);
	i = 0;
	j = line_size;
	delim = (core->dump >= 0) ? 32 : 64;
	while (i < MEM_SIZE / bar)
	{
		if (!i || (i >= delim && !(i % delim)))
			ft_printf("%#.4p : ", i);
		ft_printf("%.2hhx ", core->map[i++]);
		if (!--j)
		{
			ft_putchar('\n');
			j = line_size;
		}
	}
	if (exit)
		cw_clear_exit(core, NULL, 1);
}

void	print_warriros(t_core *core)
{
	int		i;

	i = 0;
	while (core->players[i])
	{
		ft_printf("number: %d\n", core->players[i]->nb);
		ft_printf("name: %s\n", core->players[i]->name);
		ft_printf("comment: %s\n", core->players[i]->comment);
		ft_printf("start_position: %d\n", core->players[i]->start_position);
		ft_printf("code_size: %d\n", core->players[i]->code_size);
		print_memory(core->players[i]->exec_code, core->players[i]->code_size);
		ft_printf("--------------------------------------\n");
		++i;
	}
}

void	print_processes(t_core *core, t_list *pc, int count)
{
	int		i;

	while (pc && count)
	{
		ft_printf("%9d|%8d|%10d|%12d|%10d|%7d|%11s| ", core->cycle_after_start,
		PC->nb, PC->position, PC->cycle, PC->cycle_for_op,
		PC->carry, (PC->op_info) ? PC->op_info->op_name : "NULL");
		i = 0;
		while (i < REG_NUMBER)
			ft_printf("%.*x ", REG_SIZE, PC->reg[i++]);
		ft_putchar('\n');
		pc = pc->next;
		--count;
	}
}

int		print_process_header(t_core *core, t_list *pc)
{
	int		ret;

	ret = 0;
	if (core->out == 5)
		ret += ft_printf("%-5d ", core->cycle_after_start);
	ret += ft_printf("P%5d |", PC->nb);
	ft_printf(" %s ", PC->op_info->op_name);
	return (ret);
}

void	print_mov(t_list *pc, int new)
{
	int		i;
	int		size;

	if (PC->op_info)
	{
		size = get_function_size(BYTE(ARG_BYTE), PC->op_info);
		ft_printf("ADV %d (%.4p -> %.4p) ", size, CURRENT, new);
		i = 0;
		while (i < size)
			ft_printf("%.2hhx ", BYTE(CURRENT + i++));
		ft_putchar('\n');
	}
}
