/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_asm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 22:05:51 by skrystin          #+#    #+#             */
/*   Updated: 2019/08/16 05:27:29 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	set_size_short(char *buf, int size, int i, int ofset)
{
	int		magic;

	magic = size;
	while (ofset)
		buf[i++] = magic >> (ofset -= 8);
}

void	write_operations(int s, char *str, t_comm *com, int counter)
{
	while (counter < 16)
	{
		if (!ft_strcmp(com->instr, g_op_tab[counter].op_name))
			break ;
		counter++;
	}
	str[s++] = g_op_tab[counter].op_code;
	if (g_op_tab[counter].arg_type)
		str[s++] = com->arg_type;
	while (com->arg_type)
	{
		if ((com->arg_type >= 192 || (com->arg_type >= 128 &&
		g_op_tab[counter].t_dir_size == 2)))
		{
			s = s + 2;
			set_size_short(str, com->arg_f, s - 2, 16);
		}
		else if (com->arg_type >= 128 && (s = s + 4) != -1)
			set_size_short(str, com->arg_f, s - 4, 32);
		else if (com->arg_type >= 64)
			set_size_short(str, com->arg_f, s++, 8);
		com->arg_type <<= 2;
		com->arg_f = com->arg_s;
		com->arg_s = com->arg_t;
	}
}

void	print_to_bytecode(t_as *all, char *file, t_list *com, int size)
{
	int		fd;
	int		start;
	char	code_str[EXEC_CODE_OFSET + size + 1];

	if (!*all->name || !*all->comment)
	{
		ft_printf("Invalid name or comment\n");
		return ;
	}
	fd = print_basic(all, file, code_str, size);
	start = EXEC_CODE_OFSET;
	while (com)
	{
		write_operations(start, code_str, ((t_comm *)com->content), 0);
		start += ((t_comm *)com->content)->len;
		com = com->next;
	}
	write(fd, code_str, EXEC_CODE_OFSET + size);
	close(fd);
}

int		code_size(t_list *com, int res)
{
	while (com)
	{
		res += ((t_comm *)com->content)->len;
		com = com->next;
	}
	return (res);
}
