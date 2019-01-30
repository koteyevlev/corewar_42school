/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrystin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 11:16:12 by skrystin          #+#    #+#             */
/*   Updated: 2019/01/30 14:49:06 by skrystin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>


int ft_putchar(char c)
{
  write(1, &c, 1);
  return (0);
}

void ft_print_numbers(void)
{
  char c = '0';
  char t = '9';
  while (c <= t)
    {
      ft_putchar(c);
      c++;
    }
  ft_putchar('\n');
}

int main()
{
  ft_print_numbers();
  return (0);
}
