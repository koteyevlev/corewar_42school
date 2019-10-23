/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_bytes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 16:26:45 by nalexand          #+#    #+#             */
/*   Updated: 2019/08/07 16:27:05 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_reverse_bytes(long bytes, size_t size)
{
	long	res;

	res = 0;
	while (size--)
	{
		res = (res << 8) | (bytes & 0xFF);
		bytes >>= 8;
	}
	return (res);
}
