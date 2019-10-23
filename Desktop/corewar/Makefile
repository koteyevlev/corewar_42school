# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/03 20:54:43 by nalexand          #+#    #+#              #
#    Updated: 2019/08/17 16:55:07 by nalexand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

VPATH = src/corewar:src/asm:src/common:includes:src/corewar/visual

CFLAGS = -Wall -Werror -Wextra

HEADER = -I includes -I lib/libftprintf/includes
INCLUDES = corewar.h op.h

CORE = corewar
ASM = asm

COM_LIB = lib/common.a
COR_LIB = lib/corewar.a
ASM_LIB = lib/asm.a
LIBFT = lib/libftprintf/libftprintf.a

OBJ_DIR = obj/
LIB_DIR = lib/

COM_SRC =	print_memory.c \
			byte_functions.c \

COR_SRC =	corewar.c \
			cw_op_tab.c \
			cw_clear_exit.c \
			read_input.c \
			init_players.c \
			init_processes.c \
			validate_operation.c \
			game_process.c \
			game_check.c \
			usage.c \
			init_visual.c \
			display_winner.c \
			render_info.c \
			render.c \
			op_a_live.c \
			op_b_ld.c \
			op_c_st.c \
			op_d_add.c \
			op_e_sub.c \
			op_f_and.c \
			op_g_or.c \
			op_h_xor.c \
			op_i_zjmp.c \
			op_j_ldi.c \
			op_k_sti.c \
			op_l_fork.c \
			op_m_lld.c \
			op_n_lldi.c \
			op_o_lfork.c \
			op_p_aff.c \
			op_a_functions.c \
			op_a_init_args.c \
			colorize_mem.c \
			cw_debug.c

ASM_SRC =	asm.c \
			asm_op_tab.c \
			first_validation.c \
			command_val.c \
			command_val2.c \
			command_val3.c \
			print_basic.c \
			printer_asm.c \
			deleter.c \
			error_parse.c \

COM_OBJ = $(addprefix $(OBJ_DIR), $(patsubst %.c, %.o, $(COM_SRC)))
COR_OBJ = $(addprefix $(OBJ_DIR), $(patsubst %.c, %.o, $(COR_SRC)))
ASM_OBJ = $(addprefix $(OBJ_DIR), $(patsubst %.c, %.o, $(ASM_SRC)))

all: $(CORE) $(ASM)

$(CORE): $(COM_LIB) $(COR_LIB) $(LIBFT)
	gcc $(CFLAGS) -o $@ $^ -lncurses
$(ASM): $(COM_LIB) $(ASM_LIB) $(LIBFT)
	gcc $(CFLAGS) -o $@ $^

$(COR_LIB):: $(OBJ_DIR) $(LIB_DIR)
$(COR_LIB):: $(COR_OBJ)
	@ar rc $@ $^
$(ASM_LIB):: $(OBJ_DIR) $(LIB_DIR)
$(ASM_LIB):: $(ASM_OBJ)
	@ar rc $@ $^
$(COM_LIB):: $(OBJ_DIR) $(LIB_DIR)
$(COM_LIB):: $(COM_OBJ)
	@ar rc $@ $^

$(LIBFT):
	make -C lib/libftprintf

$(OBJ_DIR):
	mkdir -p $@
$(LIB_DIR):
	mkdir -p $@

$(OBJ_DIR)%.o: %.c $(INCLUDES)
	gcc $(CFLAGS) -c $< -o $@ $(HEADER)

clean:
	@rm -rf $(OBJ_DIR)
	@rm -f $(COM_LIB)
	@rm -f $(COR_LIB)
	@rm -f $(ASM_LIB)
	@rm -rf *.dSYM
	@rm -f *.txt
	@rm -f *.diff

fclean: clean
	@rm -f $(CORE)
	@rm -f $(ASM)

re: fclean all

relib:
	make -C lib/libftprintf re
