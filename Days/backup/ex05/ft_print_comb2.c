/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrystin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 18:29:33 by skrystin          #+#    #+#             */
/*   Updated: 2019/01/31 22:35:13 by skrystin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	print1(char a, char b, char c, char d)
{
	ft_putchar(a);
	ft_putchar(b);
	ft_putchar(' ');
	ft_putchar(c);
	ft_putchar(d);
	d++;
}

void	print2(char a, char b, char c, char d)
{
	ft_putchar(',');
	ft_putchar(' ');
	ft_putchar(a);
	ft_putchar(b);
	ft_putchar(' ');
	ft_putchar(c);
	ft_putchar(d);
}

void	whileall(char a, char b, char c, char d)
{
	while (a <= '9')
	{
		while (b <= '9')
		{
			while (c <= '9')
			{
				while (d <= '9')
				{
					if ((a == c && b < d) || (a < c))
					{
						print2(a, b, c, d);
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

void	ft_print_comb2(void)
{
	char a;
	char b;
	char c;
	char d;

	a = '0';
	b = '0';
	c = '0';
	d = '1';
	print1(a, b, c, d);
	whileall(a, b, c, d);
}
