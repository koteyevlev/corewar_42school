/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_a_init_args.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 21:38:37 by nalexand          #+#    #+#             */
/*   Updated: 2019/08/13 21:38:52 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	init_args(t_arg *args, t_list *pc, int count)
{
	int		position;
	char	arg_byte;

	arg_byte = (ARG_TYPE) ? BYTE(ARG_BYTE) : (get_arg_code(OPER_ARGS[0]) << 6);
	args[0].type = get_arg_type(arg_byte);
	args[0].size = get_arg_ofset(args[0].type, PC->op_info);
	position = CURRENT + 1 + ARG_TYPE;
	args[0].value = get_value(PC->map, adr(position), args[0].size);
	if (count > 1)
	{
		args[1].type = get_arg_type(arg_byte << 2);
		args[1].size = get_arg_ofset(args[1].type, PC->op_info);
		position += args[0].size;
		args[1].value = get_value(PC->map, adr(position), args[1].size);
	}
	if (count > 2)
	{
		args[2].type = get_arg_type(arg_byte << 4);
		args[2].size = get_arg_ofset(args[2].type, PC->op_info);
		position += args[1].size;
		args[2].value = get_value(PC->map, adr(position), args[2].size);
	}
}
