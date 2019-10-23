/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 18:12:29 by nalexand          #+#    #+#             */
/*   Updated: 2019/08/07 16:28:37 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	if (str[len] && len < 1)
		len++;
	while (str[len])
	{
		if (str[len + 1] && str[len + 2]
		&& str[len + 3] && str[len + 4]
		&& str[len + 5] && str[len + 6]
		&& str[len + 7])
			len += 8;
		else
			len++;
	}
	return (len);
}
