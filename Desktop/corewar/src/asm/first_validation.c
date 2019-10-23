/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 15:04:16 by skrystin          #+#    #+#             */
/*   Updated: 2019/08/16 18:03:04 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#define KOSTYL (*all)->comment[0]

int		to_ignore(char *str, int x)
{
	while (str[x] == '\t' || str[x] == ' ')
		x++;
	if (str[x] == '#' || str[x] == '\0')
		return (1);
	return (0);
}

void	ft_write_it(t_as **all, int *y, char **f, int x)
{
	while (f[*y][x])
	{
		if ((*all)->read == 'N' && f[*y][x] != '"')
		{
			(*all)->name[(*all)->name_i] = f[*y][x];
			(*all)->name_i++;
		}
		if ((*all)->read == 'C' && f[*y][x] != '"')
		{
			(*all)->comment[(*all)->com_i] = f[*y][x];
			(*all)->com_i++;
		}
		if (f[*y][x] == '"' && to_ignore(f[*y] + x + 1, 0))
		{
			(*all)->read = '\0';
			break ;
		}
		if ((*all)->name_i > PROG_NAME_LENGTH ||
		(*all)->com_i > COMMENT_LENGTH || f[*y][x] == '"')
			valid_errors(0, &f, all, (*all)->read);
		x++;
	}
}

void	add_names(t_as **all, int *y, char **f, int x)
{
	while (f[*y][x] == '\t' || f[*y][x] == ' ')
		x++;
	if (ft_strstr(f[*y], NAME_CMD_STRING) == f[*y] + x &&
	!(*all)->read && !(*all)->name[0] && (x = x + 5) != -1)
		(*all)->read = 'n';
	if (ft_strstr(f[*y], COMMENT_CMD_STRING) == f[*y] + x &&
	!(*all)->read && !(*all)->comment[0] && (x = x + 8) != -1)
		(*all)->read = 'c';
	while (f[*y][x] == '\t' || f[*y][x] == ' ')
		x++;
	if ((*all)->read == 'n' && f[*y][x] == '"' && (x = x + 1) != -1)
		(*all)->read = 'N';
	if ((*all)->read == 'c' && f[*y][x] == '"' && (x = x + 1) != -1)
		(*all)->read = 'C';
	if ((*all)->read == 'C' || (*all)->read == 'N')
		ft_write_it(all, y, f, x);
	if ((*all)->read == 'c' || (*all)->read == 'n')
		valid_errors(0, &f, all, (*all)->read);
}

void	check_to_valid(char *str, int x, t_as **all, char **f)
{
	int		flag;
	int		c;

	flag = 0;
	c = 0;
	while (str[x] == '\t' || str[x] == ' ')
		x++;
	if (str[x] == COMMENT_CHAR || str[x] == '\0')
		return ;
	if (!((ft_strstr(str, ".name") && !(*all)->name[0]) || (ft_strstr(str,
	COMMENT_CMD_STRING) && !(*all)->comment[0]) || (*all)->read))
		flag = 1;
	while (c < 16 && !(*all)->read && (*all)->comment[0] && (*all)->name[0])
	{
		if (ft_strstr(str, g_op_tab[c].op_name) == str + x)
			return ;
		c++;
	}
	if (flag != 1)
		return ;
	while (str[x] && ft_strindex(LABEL_CHARS, str[x]) != -1)
		x++;
	if (str[x] == ':' && !(*all)->read && KOSTYL && (*all)->name[0])
		return ;
	valid_errors(str, &f, all, 0);
}
