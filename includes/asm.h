/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrystin <skrystin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 05:20:53 by nalexand          #+#    #+#             */
/*   Updated: 2019/08/16 18:16:53 by skrystin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H
# include "common.h"

typedef unsigned char	t_arg_byte;

typedef	struct	s_as
{
	char		name[PROG_NAME_LENGTH + 1];
	char		comment[COMMENT_LENGTH + 1];
	t_list		*labels;
	t_list		*comm;
	int			name_i;
	int			com_i;
	int			comand_n;
	int			tmp_x;
	char		read;
}				t_as;

typedef	struct	s_comm
{
	char		*instr;
	char		*label_f;
	char		*label_s;
	char		*label_t;
	int			arg_f;
	int			arg_s;
	int			arg_t;
	int			len;
	t_arg_byte	arg_type;
}				t_comm;

typedef	struct	s_label
{
	char		*name;
	t_list		*link;
}				t_label;

int				to_ignore(char *str, int x);
void			ft_write_it(t_as **all, int *y, char **f, int x);
void			add_names(t_as **all, int *y, char **f, int x);
void			check_to_valid(char *str, int x, t_as **all, char **f);
int				check_command(char *str, char **f, t_as **all, int counter);
unsigned char	find_type_arg(t_as **all, char *str, t_op op_tb);
void			add_arg(t_comm *com, char *str, t_as **all, t_op op_tab);
int				check_arg(char *str, t_op op_tab, t_as **all);
void			label_to_com(t_as **all, t_list *comm, t_list *tmp);
void			add_command(t_as **all, t_list *tmp, char **f, char *str);
int				add_label(t_as **all, char **f, char *str, int y);
void			label_to_nbr(t_as **all,
				t_list *label, t_list *begin_c, t_list	*tmp);
int				len_to_label(t_list *dst,
				t_list *label, char *find, t_as **all);
int				print_basic(t_as *all, char *file, char *head, int size);
void			set_size_short(char *buf, int size, int i, int ofset);
void			write_operations(int s, char *str, t_comm *com, int counter);
void			print_to_bytecode(t_as *all, char *file, t_list *com, int size);
int				code_size(t_list *com, int res);
void			del_com(t_as **all, t_list *comm);
void			del_labels(t_as **all, t_list *lab);
void			delete_asm_all(t_as **all, char ***f);
void			first_error(char *str, char *file, char **todel);
void			valid_errors(char *line, char ***todel, t_as **all, int flag);
void			invalid_comm(t_as **all, char ***todel, char *str);
int				find_counter(char *str);
int				check_command(char *str, char **f, t_as **all, int counter);
int				find_c(char **tmp, int x);
void			add_arg_help(char **tmp, t_as **all, char *str, t_comm *com);
void			add_arg(t_comm *com, char *str, t_as **all, t_op op_tab);
int				check_arg(char *str, t_op op_tab, t_as **all);
void			label_to_com(t_as **all, t_list *comm, t_list *tmp);
void			create_lab(t_as **all, char *str, char **f, t_label **lab);

#endif
