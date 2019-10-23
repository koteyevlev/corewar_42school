/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 23:36:03 by nalexand          #+#    #+#             */
/*   Updated: 2019/08/16 19:32:19 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		put_usage(int fd)
{
	ft_putstr("usage:\t./corewar [-dump nbr_cycles]"\
	" [[-n number] champion1.cor] ...\n"\
	"\t-a        : Prints output from \"aff\" (Default is to hide it)\n"\
	"\t-d N      : Dumps memory after N cycles then exits in 64 octest\n"\
	"\t-dump N   : Dumps memory after N cycles then exits in 32 octest\n"\
	"\t-s        : Ncurses output mode\n"\
	"\t-v N      : Verbosity levels, can be added together to enable several\n"\
	"\t                - 1 : Show lives\n"\
	"\t                - 2 : Show cycles\n"\
	"\t                - 4 : Show operations (Params are NOT litteral ...)\n"\
	"\t                - 5 : Show operations widh cycle number\n"\
	"\t                - 8 : Show deaths\n"\
	"\t                - 16 : Show PC movements (Except for jumps)\n");
	return (fd);
}
