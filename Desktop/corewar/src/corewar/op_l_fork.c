/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_l_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 21:38:47 by nalexand          #+#    #+#             */
/*   Updated: 2019/08/16 05:02:04 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	12: fork {T_DIR} DSIZE 2
**
**	Операция fork делает копию каретки.
**	И эту копию размещает по адресу <ПЕРВЫЙ_АРГУМЕНТ> % IDX_MOD.
**		- Значения всех регистров
**		- Значение carry
**		- Номер цикла, в котором в последний раз выполнялась операция live
**		- И кое-что еще, но об этом позже.
*/

static void	fork_print_process(t_core *core, t_list *pc, t_arg *args, int pos)
{
	print_process_header(core, pc);
	ft_printf("%d", args->value);
	ft_printf(" (%d)\n", pos);
}

static void	set_params(t_core *core, t_pc *pc, int pos)
{
	pc->cycle_for_op = 0;
	pc->op_info = NULL;
	pc->op = 0;
	pc->position = pos;
	pc->nb = ++core->global_process_count;
	core->current_process_count++;
}

void		cw_fork(void *core, t_list *pc)
{
	t_arg		arg;
	t_list		*node;
	t_core		*ptr;
	int			new_pos;

	ptr = (t_core *)core;
	if (!(node = ft_lstnew(pc->content, sizeof(t_pc))))
		cw_clear_exit((t_core *)core, MEM_ERROR, 2);
	init_args(&arg, pc, 1);
	new_pos = adr(CURRENT + arg.value % IDX_MOD);
	set_params(ptr, ((t_pc *)node->content), new_pos);
	if (ptr->visu_mod)
		ptr->visual.attrs[new_pos].pc_here = 5;
	ft_lstadd(&((t_core *)core)->pcs, node);
	if (ptr->out == 4 || ptr->out == 5)
		fork_print_process(ptr, pc, &arg, new_pos);
	mov_pc((t_core *)core, pc, adr(CURRENT + 1 + arg.size));
}
