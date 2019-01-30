/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrystin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 13:21:45 by skrystin          #+#    #+#             */
/*   Updated: 2019/01/30 17:54:41 by skrystin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_putchar(char c)
{
	  write(1, &c, 1);
	  return (0);
}

void ft_is_negative(int n)
{
	char c = 'P';
	char t = 'N';
	if (n < 0)
	{
		ft_putchar(t);
	}
	else 
	{
	ft_putchar(c);
	}
	ft_putchar('\n');
}

int main()
{
	ft_is_negative(NULL);
	return (0);
}
