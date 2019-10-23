/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrystin <skrystin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 21:05:41 by skrystin          #+#    #+#             */
/*   Updated: 2019/08/05 13:58:32 by skrystin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

char			*ft_helpitoa(uintmax_t value, uintmax_t base,
uintmax_t len, uintmax_t nbr)
{
	char		*res;
	char		*basestr;

	value = value + 1 - 1;
	basestr = "0123456789abcdef";
	if (!(res = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	res[len] = '\0';
	if (nbr == ULLONG_MAX && base == 8)
		return (res = "1777777777777777777777");
	if (nbr == ULLONG_MAX && base == 16)
		return (res = "ffffffffffffffff");
	while (nbr)
	{
		res[--len] = basestr[nbr % base];
		nbr = nbr / base;
	}
	return (res);
}

char			*ft_itoa_base(uintmax_t value, long int base)
{
	uintmax_t		len;
	uintmax_t		nbr;

	if (!value)
		return ("0");
	nbr = value;
	len = 0;
	while (nbr)
	{
		nbr = nbr / base;
		len++;
	}
	nbr = value;
	return (ft_helpitoa(value, base, len, nbr));
}
