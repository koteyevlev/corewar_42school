/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 21:12:57 by nalexand          #+#    #+#             */
/*   Updated: 2019/08/17 15:46:55 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "visual.h"

# define REG_OFSET			1
# define IND_OFSET			2
# define DIR_OFSET			op->t_dir_size

# define PC					((t_pc *)pc->content)
# define CURRENT			PC->position
# define ARG_BYTE			PC->position + 1
# define PROCESS			PC->op_info->process
# define ARG_TYPE			PC->op_info->arg_type
# define OPER_ARGS			PC->op_info->args
# define BYTE(pos)			(PC->map[adr(pos)])
# define GET_VAL(pos, size)	(ft_reverse_bytes(*((size *)(pos)), sizeof(size)))

typedef struct		s_arg
{
	int				type;
	int				size;
	int				value;
}					t_arg;

typedef struct		s_player
{
	int				code_size;
	int				nb;
	int				id;
	int				start_position;
	int				last_live;
	int				lives;
	int				info_posy;
	char			*name;
	char			*comment;
	char			*exec_code;
}					t_player;

typedef struct		s_pc
{
	char			carry;
	int				reg[REG_NUMBER];
	int				nb;
	int				cycle;
	int				cycle_for_op;
	int				position;
	unsigned char	*map;
	t_player		*owner;
	t_op			*op_info;
	char			op;
}					t_pc;

typedef struct		s_core
{
	unsigned char	map[MEM_SIZE];
	t_visual		visual;
	t_list			*input;
	t_list			*pcs;
	t_player		*players[MAX_PLAYERS + 1];
	t_player		*last_player;
	int				cycle_to_die;
	int				live_count;
	int				game_check_count;
	int				war_count;
	int				current_process_count;
	int				global_process_count;
	int				cycle_after_start;
	int				d;
	int				dump;
	int				out;
	int				print_pc;
	int				print_aff;
	int				death;
	int				arg_ofset;
	int				visu_mod;
}					t_core;

int					put_usage(int fd);
void				cw_clear_exit(t_core *core,
					const char *message, const int fd);
void				read_input(t_core *core, int ac, char **av);
void				init_players(t_core *core, int ac, char **av);
void				init_processes(t_core *core);
int					validate_operation(t_list *pc);
void				game_cycle(t_core *core);
void				game_check(t_core *core, int *cycle_to_die);

int					adr(int current_adr);
void				init_args(t_arg *args, t_list *pc, int count);
int					get_operand(t_arg arg, t_list *pc, int mod);
void				set_value(unsigned char *mem, int pos, int size, int value);
void				mov_pc(t_core *core, t_list *pc, int new_pos);
int					get_value(unsigned char *mem, int pos, int size);

void				cw_live(void *core, t_list *pc);
void				cw_ld(void *core, t_list *pc);
void				cw_st(void *core, t_list *pc);
void				cw_add(void *core, t_list *pc);
void				cw_sub(void *core, t_list *pc);
void				cw_and(void *core, t_list *pc);
void				cw_or(void *core, t_list *pc);
void				cw_xor(void *core, t_list *pc);
void				cw_zjmp(void *core, t_list *pc);
void				cw_ldi(void *core, t_list *pc);
void				cw_sti(void *core, t_list *pc);
void				cw_fork(void *core, t_list *pc);
void				cw_lld(void *core, t_list *pc);
void				cw_lldi(void *core, t_list *pc);
void				cw_lfork(void *core, t_list *pc);
void				cw_aff(void *core, t_list *pc);

void				print_info_header(t_list *pc);
void				print_warriros(t_core *core);
void				print_dump(t_core *core, int bar, int exit);
void				print_input(t_list *tmp);
void				print_mov(t_list *pc, int new);
void				print_processes(t_core *core, t_list *pc, int count);
int					print_process_header(t_core *core, t_list *pc);

void				init_visual(t_core *core);
void				show_fight_field(t_core *core);
void				colorize_mem(t_core *core, int pos, int color);
void				render_info(t_core *core);
void				display_winner(t_core *core);

#endif
