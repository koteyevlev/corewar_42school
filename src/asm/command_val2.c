/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_val2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 17:37:02 by skrystin          #+#    #+#             */
/*   Updated: 2019/08/16 18:09:41 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#define COM ((t_comm *)tmp->content)
#define COM2 &((t_comm *)tmp->content)
#define KOS tmp[op_tab.arg_count - 1]
#define KOS2 ((t_label *)label->content)->name
#define KOS3 begin_c->content

int				find_counter(char *str)
{
	int		counter;

	counter = 0;
	while (counter < 16)
	{
		if (ft_strstr(str, g_op_tab[counter].op_name) == str
		&& ((*(str + ft_strlen(g_op_tab[counter].op_name))) <= 32
		|| (*(str + ft_strlen(g_op_tab[counter].op_name))) <= '%'))
			break ;
		counter++;
	}
	return (counter);
}

int				check_command(char *str, char **f, t_as **all, int counter)
{
	int		after;

	if (counter == 16)
		invalid_comm(all, &f, str);
	if (ft_strstr(str = str + ft_strlen(g_op_tab[counter].op_name), "#"))
		*ft_strstr(str, "#") = '\0';
	if ((after = ft_strccount(str, SEPARATOR_CHAR))
	+ 1 != g_op_tab[counter].arg_count)
		invalid_comm(all, &f, str);
	while (after--)
		str = str + ft_strindex(str, SEPARATOR_CHAR) + 1;
	while (*str == ' ' || *str == '\t')
		str++;
	if (*str == 'r' || *str == '-' || *str == '%')
	{
		str++;
		if (*str == '-' && *(str - 1) == '%')
			str++;
	}
	while (ft_isdigit(*str))
		str++;
	if (!to_ignore(str, 0) && *str != LABEL_CHAR)
		invalid_comm(all, &f, str);
	return (counter);
}

unsigned char	find_type_arg(t_as **all, char *str, t_op op_tb)
{
	unsigned char	res;
	int				arg;

	arg = 0;
	res = 0;
	while (str && arg < op_tb.arg_count)
	{
		if (*str == 'r' && (op_tb.args[arg] & T_REG) == T_REG)
			res = res | REG_CODE;
		else if (*str == '%' && (op_tb.args[arg] & T_DIR) == T_DIR)
			res = res | DIR_CODE;
		else if ((ft_isdigit(*str) || *str == '-'
		|| *str == ':') && (op_tb.args[arg] & T_IND) == T_IND)
			res = res | IND_CODE;
		else
			invalid_comm(all, 0, str);
		res <<= 2;
		arg++;
		str += ft_strindex(str, SEPARATOR_CHAR) + 1;
		while (*str == ' ' || *str == '\t')
			str++;
	}
	res <<= ((3 - op_tb.arg_count) * 2);
	return (res);
}

int				find_c(char **tmp, int x)
{
	int	c;

	c = 0;
	while (tmp[x][c] == ' ' || tmp[x][c] == '\t')
		c++;
	if (tmp[x][c] == 'r' || tmp[x][c] == '%')
		c++;
	return (c);
}

void			add_arg_help(char **tmp, t_as **all, char *str, t_comm *com)
{
	char	*label;
	int		c;
	int		x;

	x = (*all)->tmp_x;
	c = find_c(tmp, x);
	if (ft_isint(tmp[x] + c) && x == 1)
		(com)->arg_s = ft_atoi(tmp[x] + c);
	if (ft_isint(tmp[x] + c) && x == 2)
		(com)->arg_t = ft_atoi(tmp[x] + c);
	if (!ft_isint(tmp[x] + c) && *(tmp[x] + c) != LABEL_CHAR)
		invalid_comm(all, &tmp, str + c);
	if (!ft_isint(tmp[x] + c) && *(tmp[x] + c) == LABEL_CHAR)
	{
		if (!(label = ft_strnew(ft_strlen(tmp[x] + c))))
			invalid_comm(all, &tmp, str);
		ft_strcpy(label, tmp[x] + c);
		if (x == 0)
			(com)->label_f = label;
		if (x == 1)
			(com)->label_s = label;
		if (x == 2)
			(com)->label_t = label;
	}
}
