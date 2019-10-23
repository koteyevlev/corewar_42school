/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_players.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 21:35:29 by nalexand          #+#    #+#             */
/*   Updated: 2019/08/16 18:00:45 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	set_exec_code(t_core *core)
{
	int		i;

	i = 0;
	while (core->players[i])
	{
		ft_memcpy(core->map + core->players[i]->start_position,
		core->players[i]->exec_code,
		core->players[i]->code_size);
		i++;
	}
}

static void	set_start_position(t_core *core)
{
	int			start;
	int			i;

	i = 0;
	start = 0;
	while (core->players[i])
	{
		core->players[i++]->start_position = start;
		start += MEM_SIZE / core->war_count;
	}
}

static void	check_new_numbers(t_core *core, int ac, char **av)
{
	int		i;
	int		j;

	i = core->arg_ofset;
	j = core->war_count - 1;
	while (i < ac && core->players[j])
	{
		if (ft_strequ("-n", av[i]) && i + 1 < ac && ft_isint(av[i + 1]))
		{
			core->players[j]->nb = ft_atoi(av[++i]);
			j--;
		}
		i++;
	}
}

static void	set_params(t_player *player, t_list *input)
{
	player->last_live = 0;
	player->lives = 0;
	player->name = STR(input) + NAME_OFSET;
	player->comment = STR(input) + COMMENT_OFSET;
	player->code_size = GET_VAL(input->content + CODE_SIZE_OFSET, int);
	player->exec_code = STR(input) + EXEC_CODE_OFSET;
}

void		init_players(t_core *core, int ac, char **av)
{
	t_list		*input;
	t_player	*new;
	int			nb;
	int			i;

	input = core->input;
	nb = core->war_count;
	i = nb;
	while (input)
	{
		if (!(new = (t_player *)malloc(sizeof(t_player))))
			cw_clear_exit(core, MEM_ERROR, 2);
		new->nb = nb;
		new->id = nb--;
		set_params(new, input);
		core->players[--i] = new;
		input = input->next;
	}
	set_start_position(core);
	check_new_numbers(core, ac, av);
	set_exec_code(core);
}
