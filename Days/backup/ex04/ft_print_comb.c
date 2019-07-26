/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrystin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 13:34:39 by skrystin          #+#    #+#             */
/*   Updated: 2019/01/31 22:30:14 by skrystin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	print1(char a, char b, char c)
{
	ft_putchar(a);
	ft_putchar(b);
	ft_putchar(c);
	c++;
}

void	print2(char a, char b, char c)
{
	ft_putchar(',');
	ft_putchar(' ');
	ft_putchar(a);
	ft_putchar(b);
	ft_putchar(c);
}

void	checker(char a, char b, char c)
{
	while (a != '8')
	{
		while (b <= '9')
		{
			while (c <= '9')
			{
				if (a != b && b != c && a != c)
				{
					print2(a, b, c);
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

void	ft_print_comb(void)
{
	char a;
	char b;
	char c;

	a = '0';
	b = '1';
	c = '2';
	print1(a, b, c);
	checker(a, b, c);
}
