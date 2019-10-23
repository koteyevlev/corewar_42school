/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 05:21:07 by nalexand          #+#    #+#             */
/*   Updated: 2019/08/16 05:48:14 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H
# include "libft.h"
# include "ft_printf.h"
# include "op.h"
# define MEM_ERROR "Error: mem alloc error!"
# define STR(var) ((char *)var->content)
# define MAGIC_SIZE sizeof(int)
# define NAME_OFSET MAGIC_SIZE
# define CODE_SIZE_OFSET (NAME_OFSET + PROG_NAME_LENGTH + sizeof(int))
# define COMMENT_OFSET (CODE_SIZE_OFSET + sizeof(int))
# define EXEC_CODE_OFSET (COMMENT_OFSET + COMMENT_LENGTH + sizeof(int))

typedef struct		s_op
{
	char			*op_name;
	char			arg_count;
	char			args[3];
	char			op_code;
	int				cycle;
	char			*description;
	char			arg_type;
	char			t_dir_size;
	char			carry;
	void			(*process)(void *, t_list *);
}					t_op;

t_op				g_op_tab[17];

t_op				*get_cmd(char *cmd);
void				print_memory(const char *mem, ssize_t size);
int					get_arg_type(char arg_byte);
int					get_arg_code(char arg_type);
int					get_arg_ofset(int arg_type, t_op *op);
int					get_function_size(char arg_byte, t_op *op);
void				print_operation_info(char *position);

#endif
