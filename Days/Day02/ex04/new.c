/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrystin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 18:29:33 by skrystin          #+#    #+#             */
/*   Updated: 2019/01/30 19:22:21 by skrystin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>


int ft_putchar(char c)
{
	write(1, &c, 1);
	return (0);
}

void ft_print_comb2(void)
{
   	char a = '0';
	char b = '0';
	char c = '0';
	char d = '1';
	ft_putchar(a);
	ft_putchar(b);
	ft_putchar(' ');
	ft_putchar(c);
	ft_putchar(d);
	d++;
	while (a <= '9' && b <= '8')
	{
		while (a <= '9')
		{
			while (b <= '9')
			{
				while (c <= '9')
				{
					while (d <= '9')
					{
						if ((a == c && b < d) ||  (a < c))
						{
							ft_putchar(',');
							ft_putchar(' ');
							ft_putchar(a);
							ft_putchar(b);
							ft_putchar(' ');
							ft_putchar(c);
							ft_putchar(d);
						}
						d++;
					}
					c++;
					d = '0';
				}
				b++;
				d = b;
				c = a;
			}
			a++;
			b = '0';
		}
	}
}

int main()
{
	    ft_print_comb2();
		    return (0);
}
