# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbruen <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/27 20:15:35 by sbruen            #+#    #+#              #
#    Updated: 2019/05/04 09:50:25 by sbruen           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1	= push_swap
NAME2	= checker

CFLAGS 	= -Wall -Wextra -Werror -g

SRC1 	= push_swap.c additional_funcs.c check_fill_args.c checkers.c \
		  get_next_line.c helpers.c helpers2.c instr.c instr2.c pushers.c \
		  printer.c sort.c 

SRC2 	= checker.c additional_funcs.c check_fill_args.c checkers.c \
		  get_next_line.c helpers.c helpers2.c instr.c instr2.c pushers.c \
		  printer.c sort.c 

.PHONY: all clean fclean re

RED		=	\033[0;31m
GREEN	=	\033[0;32m
NC		=	\033[0m

OBJSFD 	= objects

OBJS1 	= $(addprefix $(OBJSFD)/,$(SRC1:.c=.o))
OBJS2 	= $(addprefix $(OBJSFD)/,$(SRC2:.c=.o))

HDR 		= -I.
LIBFT_HDR 	= -I./libft/includes
LIB_BINARY	= -L./libft -lft
LIBFT		= libft/libft.a

$(LIBFT):
	@make -C libft re

all: $(LIBFT) $(NAME1) $(NAME2)

$(OBJSFD):
	@mkdir $@

$(OBJSFD)/%.o: %.c | $(OBJSFD)
	@$(CC) $(CFLAGS) $(HDR) $(LIBFT_HDR) -c $< -o $@

$(NAME1): $(OBJS1) $(LIBFT)
	@echo "$(GREEN)compiling $@...$(NC)"
	@gcc $(CFLAGS) $(OBJS1) $(LIB_BINARY) -o $@ 
	@echo "$(GREEN)$@ is ready to test$(NC)"

$(NAME2): $(OBJS2) $(LIBFT)
	@echo "$(GREEN)compiling $@...$(NC)"
	@gcc $(CFLAGS) $(OBJS2) $(LIB_BINARY) -o $@ 
	@echo "$(GREEN)$@ is ready to test$(NC)"

clean:
	@echo "$(RED)deleting object files...$(NC)"
	@/bin/rm -f $(OBJS)
	@rm -rf $(OBJSFD)
	@make -C ./libft clean

fclean: clean
	@echo "$(RED)deleting both executables...$(NC)"
	@/bin/rm -f $(NAME1)
	@/bin/rm -f $(NAME2)
	@make -C ./libft fclean

re: fclean all
