/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrystin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 16:49:33 by skrystin          #+#    #+#             */
/*   Updated: 2019/01/30 21:50:23 by skrystin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>


int ft_putchar(char c)
{
		write(1, &c, 1);
			return (0);
}

void ft_putnbr_reverse(long long nb)
{
	long long desyatki = 1;
	while (nb / desyatki != 0)
	{
		char l;
		long long numbr;
		numbr = nb / desyatki;
		numbr = numbr % 10;
		l = '0' +  numbr;
		ft_putchar(l);
		desyatki = desyatki * 10;
	}
	ft_putchar('\n');
}

long long ft_first_number(int n)
{	
	n = 10 - n;
	long long first = 9876543210;
	long long del = 10;
	while (n != 9)
	{
		del = del * 10;
		n++;
	}
	first = first % del;
	return first;
}

long long stepenb(long long number, long long stepen)
{
	long long truenum = 1;
	while (stepen != 0)
	{
		truenum = truenum * number;
		stepen--;
	}
	return truenum;
}

void checker(long long first, int n)
{
	int length = n;
  	int points = 0;
	int flag = 1;
	long long desyatki = 1;
	if (length != 1)
	{
		while (length != 1) 
		{
			desyatki = stepenb(10, n - length);
			long long firstn;
			long long secondn;
			firstn = first / desyatki;
			firstn = firstn % 10;
			secondn = first / (desyatki * 10) ;
			secondn = secondn % 10;
			if (firstn >= secondn)
			{
				flag = 0;
			}
			length--;
		}
	}
	if (flag == 1)
	{
		ft_putnbr_reverse(first);
	}	
}

void ft_print_combn(int n)
{
	long long first = ft_first_number(n);
	int desyatki = 1;
	while (first /desyatki != 0)
	{
	 	desyatki = desyatki * 10;
	}
	while (first < desyatki - 1)
	{
		checker(first, n);
		if (first / (desyatki / 10) != 9)
		{
			first = first + desyatki / 10;
		}
		else{
			first = first - (9 * desyatki / 10) + 1;
		}

	}
}

int main()
{
		ft_print_combn(1);
		return (0);
}
