/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deleter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 16:39:44 by skrystin          #+#    #+#             */
/*   Updated: 2019/08/16 18:11:31 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	del_com(t_as **all, t_list *comm)
{
	comm = (*all)->comm;
	while (comm)
	{
		(*all)->comm = (*all)->comm->next;
		if (comm && ((t_comm *)comm->content) &&
		((t_comm *)comm->content)->label_f)
			free(((t_comm *)comm->content)->label_f);
		if (comm && ((t_comm *)comm->content) &&
		((t_comm *)comm->content)->label_s)
			free(((t_comm *)comm->content)->label_s);
		if (comm && ((t_comm *)comm->content) &&
		((t_comm *)comm->content)->label_t)
			free(((t_comm *)comm->content)->label_t);
		if (comm && ((t_comm *)comm->content))
			free((comm->content));
		if (comm)
			free(comm);
		comm = (*all)->comm;
	}
}

void	del_labels(t_as **all, t_list *lab)
{
	lab = (*all)->labels;
	while (lab)
	{
		(*all)->labels = (*all)->labels->next;
		free(((t_label *)lab->content)->name);
		free((t_label *)lab->content);
		free(lab);
		lab = (*all)->labels;
	}
}

void	delete_asm_all(t_as **all, char ***f)
{
	if (f && *f)
		ft_arraydel((void ***)f);
	if (all && *all)
	{
		del_com(all, (*all)->comm);
		del_labels(all, (*all)->labels);
		free(*all);
	}
}
