/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrystin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 13:34:39 by skrystin          #+#    #+#             */
/*   Updated: 2019/01/30 17:21:35 by skrystin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>


int ft_putchar(char c)
{
	write(1, &c, 1);
	return (0);
}

void ft_print_comb(void)
{
	char a = '0';
	char b = '1';
	char c = '2';
	ft_putchar(a);
	ft_putchar(b);
	ft_putchar(c);
	c++;
	while (a != '8')
	{
		while (b <= '9')
		{
			while (c <= '9')
			{
				if (a != b && b != c && a != c)
				{
					ft_putchar(',');
					ft_putchar(' ');
					ft_putchar(a);
					ft_putchar(b);
					ft_putchar(c);
				}
				c++;
			}
			b++;
			c = b;
		}
		a++;
		b = a;
		c = b;
	}	
}

int main()
{
	ft_print_comb();
	return (0);
}
