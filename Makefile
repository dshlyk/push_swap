# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbruen <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/27 20:15:35 by sbruen            #+#    #+#              #
#    Updated: 2019/05/04 12:21:55 by sbruen           ###   ########.fr        #
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
	@gcc $(CFLAGS) $(OBJS1) $(LIB_BINARY) -o $@ 

$(NAME2): $(OBJS2) $(LIBFT)
	@gcc $(CFLAGS) $(OBJS2) $(LIB_BINARY) -o $@ 

clean:
	@/bin/rm -f $(OBJS)
	@rm -rf $(OBJSFD)
	@make -C ./libft clean

fclean: clean
	@/bin/rm -f $(NAME1)
	@/bin/rm -f $(NAME2)
	@make -C ./libft fclean

re: fclean all
