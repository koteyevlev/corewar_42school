/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_to_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrystin <skrystin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 21:48:03 by nalexand          #+#    #+#             */
/*   Updated: 2019/08/16 18:17:31 by skrystin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static ssize_t	list_to_str(t_list **lst, ssize_t size, char **str)
{
	t_list	*tmp;
	ssize_t	ofset;

	*str = NULL;
	ofset = size;
	if (!size || !(*str = (char *)malloc(sizeof(char) * (size + 1))))
	{
		ft_lstdel(lst, ft_lstclear);
		return (-1);
	}
	(*str)[size] = '\0';
	while (ofset)
	{
		ofset -= (*lst)->content_size;
		ft_memcpy(*str + ofset, (*lst)->content, (*lst)->content_size);
		tmp = (*lst)->next;
		free((*lst)->content);
		free(*lst);
		*lst = tmp;
	}
	return (size);
}

ssize_t			ft_read_to_str(int fd, char **str, size_t b_size)
{
	char	buf[b_size];
	ssize_t	ret;
	ssize_t	size;
	t_list	*lst;
	t_list	*elem;

	size = 0;
	lst = NULL;
	while ((ret = read(fd, buf, b_size)) > 0)
	{
		if (!(elem = ft_lstnew(buf, ret)))
		{
			ft_lstdel(&lst, ft_lstclear);
			return (-1);
		}
		ft_lstadd(&lst, elem);
		size += ret;
	}
	return (list_to_str(&lst, size, str));
}
