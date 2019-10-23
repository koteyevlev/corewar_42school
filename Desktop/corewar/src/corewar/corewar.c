/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 21:19:35 by nalexand          #+#    #+#             */
/*   Updated: 2019/08/17 15:57:15 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	get_flag(t_core *core, int *flag, int value, int arg_ofset)
{
	core->arg_ofset += arg_ofset;
	*flag = value;
}

void		parce_flags(t_core *core, int ac, char **av)
{
	int		i;

	i = 1;
	core->d = -1;
	core->dump = -1;
	while (i < ac)
	{
		if (ft_strequ("-d", av[i]) && i + 1 < ac)
			get_flag(core, &core->d, ft_atoi(av[++i]), 2);
		if (ft_strequ("-dump", av[i]) && i + 1 < ac)
			get_flag(core, &core->dump, ft_atoi(av[++i]), 2);
		else if (ft_strequ("-v", av[i]) && i + 1 < ac)
			get_flag(core, &core->out, ft_atoi(av[++i]), 2);
		else if (ft_strequ("-c", av[i]) && i + 1 < ac)
			get_flag(core, &core->print_pc, ft_atoi(av[++i]), 2);
		else if (ft_strequ("-a", av[i]) && i + 1 < ac)
			get_flag(core, &core->print_aff, 1, 1);
		else if (ft_strequ("-s", av[i]))
			get_flag(core, &core->visu_mod, 1, 1);
		i++;
	}
}

static void	print_winner(t_core *core)
{
	if (core->last_player)
	{
		ft_printf("Contestant %d, \"%s\", has won !\n",
		core->last_player->nb, core->last_player->name);
	}
	else
	{
		ft_printf("Contestant %d, \"%s\", has won !\n",
		core->players[0]->nb, core->players[0]->name);
	}
	cw_clear_exit(core, NULL, 1);
}

static void	introduce(t_core *core)
{
	int		i;

	i = 0;
	ft_printf("Introducing contestants...\n");
	while (core->players[i])
	{
		ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n",
		core->players[i]->nb, core->players[i]->code_size,
		core->players[i]->name, core->players[i]->comment);
		i++;
	}
}

int			main(int ac, char **av)
{
	t_core	core;

	ft_bzero(&core, sizeof(t_core));
	parce_flags(&core, ac, av);
	read_input(&core, ac, av);
	init_players(&core, ac, av);
	init_processes(&core);
	introduce(&core);
	if (core.visu_mod)
		init_visual(&core);
	if (core.print_pc)
		ft_printf(" g_cycle | number | position | live_cycle |"\
		" op_cycle | carry | operation | registers\n");
	game_cycle(&core);
	if (core.visu_mod)
		display_winner(&core);
	else
		print_winner(&core);
	cw_clear_exit(&core, NULL, 1);
	return (0);
}
