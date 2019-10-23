/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_val.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrystin <skrystin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 17:10:00 by skrystin          #+#    #+#             */
/*   Updated: 2019/08/16 18:05:42 by skrystin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#define COM ((t_comm *)tmp->content)
#define COM2 &((t_comm *)tmp->content)
#define KOS tmp[op_tab.arg_count - 1]
#define KOS2 ((t_label *)label->content)->name
#define KOS3 begin_c->content
#define KOS4 COM->label_f
#define KOS5 COM->label_s
#define KOS6 COM->label_t

int				add_label(t_as **all, char **f, char *str, int y)
{
	t_list	*tmp;
	int		i;
	t_label	*lab;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	while (ft_strindex(LABEL_CHARS, str[i]) != -1)
		i++;
	if (str[i] != LABEL_CHAR)
		return (1);
	lab = 0;
	create_lab(all, str, f, &lab);
	if (!(tmp = ft_lstnew(lab, sizeof(t_label))))
	{
		free(lab);
		invalid_comm(all, 0, str);
	}
	free(lab);
	ft_lstpushback(&((*all)->labels), tmp);
	while (i >= 0)
		f[y][i--] = ' ';
	return (1);
}

char			*fit_str(char *find)
{
	if (ft_strstr(find, " "))
		find[ft_strindex(find, ' ')] = '\0';
	if (ft_strstr(find, "\t"))
		find[ft_strindex(find, '\t')] = '\0';
	return (find);
}

int				len_to_label(t_list *dst, t_list *label, char *find, t_as **all)
{
	t_list	*src;
	int		flag;
	int		res;
	t_list	*begin_c;

	begin_c = (*all)->comm;
	flag = 0;
	res = 0;
	while (label && (ft_strncmp(KOS2, find + 1, ft_strlen(find + 1))
	|| ft_strlen(find) != ft_strlen(KOS2)))
		label = label->next;
	if (!label || (src = ((t_label *)label->content)->link) == label)
		invalid_comm(all, 0, find);
	while (begin_c)
	{
		if (begin_c == src && flag == 0)
			flag = -1;
		else if (begin_c->content == dst->content && flag == 0)
			flag = 1;
		else if ((begin_c == src || KOS3 == dst->content) && flag != 0)
			flag = 0;
		res += flag * (((t_comm *)begin_c->content)->len);
		begin_c = begin_c->next;
	}
	return (res);
}

void			str_del_null(char **str)
{
	if (str && *str)
	{
		free(*str);
		*str = 0;
	}
}

void			label_to_nbr(t_as **all, t_list *label,
t_list *begin_c, t_list *tmp)
{
	tmp = (*all)->comm;
	while (tmp)
	{
		if (COM->label_f || COM->label_s || COM->label_t)
		{
			if (COM->label_f)
			{
				COM->arg_f = len_to_label(tmp, label, fit_str(KOS4), all);
				str_del_null(&COM->label_f);
			}
			if (COM->label_s)
			{
				COM->arg_s = len_to_label(tmp, label, fit_str(KOS5), all);
				str_del_null(&COM->label_s);
			}
			if (COM->label_t)
			{
				COM->arg_t = len_to_label(tmp, label, fit_str(KOS6), all);
				str_del_null(&COM->label_t);
			}
		}
		else
			tmp = tmp->next;
	}
	(*all)->comm = begin_c;
}
