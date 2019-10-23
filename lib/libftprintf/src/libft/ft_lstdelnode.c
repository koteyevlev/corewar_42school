/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelnode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 15:11:32 by nalexand          #+#    #+#             */
/*   Updated: 2019/08/13 15:11:46 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelnode(t_list **lst, t_list *node)
{
	t_list	*tmp;

	tmp = *lst;
	if (*lst == node)
	{
		*lst = node->next;
		free(node->content);
		free(node);
		return ;
	}
	while (tmp)
	{
		if (tmp->next == node)
		{
			tmp->next = node->next;
			free(node->content);
			free(node);
			return ;
		}
		tmp = tmp->next;
	}
}
