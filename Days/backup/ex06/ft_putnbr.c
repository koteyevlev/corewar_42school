/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrystin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 19:43:46 by skrystin          #+#    #+#             */
/*   Updated: 2019/01/31 22:41:26 by skrystin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	mainworker(int desyatki, int nb, char l, int numbr)
{
	while (nb / desyatki != 0)
	{
		desyatki = desyatki * 10;
	}
	desyatki = desyatki / 10;
	while (desyatki != 1)
	{
		numbr = nb / desyatki;
		numbr = numbr % 10;
		l = '0' + numbr;
		ft_putchar(l);
		desyatki = desyatki / 10;
	}
	numbr = nb % 10;
	l = '0' + numbr;
	ft_putchar(l);
	ft_putchar('\n');
}

void	ft_putnbr(int nb)
{
	char	l;
	int		desyatki;
	int		numbr;

	l = ' ';
	desyatki = 0;
	numbr = 0;
	if (nb < 0)
	{
		ft_putchar('-');
		nb = nb * (-1);
	}
	desyatki = 1;
	mainworker(desyatki, nb, l, numbr);
}
