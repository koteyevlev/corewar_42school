/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_basic.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrystin <skrystin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 17:51:19 by skrystin          #+#    #+#             */
/*   Updated: 2019/08/17 17:05:51 by skrystin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	set_magic(char *buf)
{
	int		magic;
	int		i;
	int		ofset;

	magic = COREWAR_EXEC_MAGIC;
	i = 0;
	ofset = 32;
	while (ofset)
		buf[i++] = magic >> (ofset -= 8);
}

void	set_name(char *buf, char *name)
{
	int		i;

	i = 0;
	while (name[i])
	{
		(buf + 4)[i] = name[i];
		i++;
	}
}

void	set_comment(char *buf, char *com)
{
	int		i;

	i = 0;
	while (com[i])
	{
		(buf + 140)[i] = com[i];
		i++;
	}
}

void	set_size_a(char *buf, int size)
{
	int		magic;
	int		i;
	int		ofset;

	magic = size;
	i = 136;
	ofset = 32;
	while (ofset)
		buf[i++] = magic >> (ofset -= 8);
}

int		print_basic(t_as *all, char *file, char *head, int size)
{
	int		fd;
	char	new_f[ft_strlen(file) + 3];

	ft_bzero(head, EXEC_CODE_OFSET + size + 1);
	set_magic(head);
	set_name(head, all->name);
	set_size_a(head, size);
	set_comment(head, all->comment);
	ft_strcpy(new_f, file);
	new_f[ft_strlen(file) + 2] = '\0';
	new_f[ft_strlen(file) + 1] = 'r';
	new_f[ft_strlen(file)] = 'o';
	new_f[ft_strlen(file) - 1] = 'c';
	fd = open(new_f, O_CREAT | O_TRUNC | O_RDWR, S_IWRITE | S_IREAD);
	ft_printf("Writing output program to %s\n", new_f);
	return (fd);
}
