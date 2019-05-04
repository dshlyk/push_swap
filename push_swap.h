/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 16:33:43 by sbruen            #+#    #+#             */
/*   Updated: 2019/05/04 12:11:24 by sbruen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <wchar.h>
# include <locale.h>
# include "libft/includes/libft.h"
# define BUFF_SIZE 1
# define GREEN "\033[0;32m"
# define RED "\033[0;31m"

typedef struct	s_stack
{
	int			*st_a;
	int			*st_b;
	int			sz_a;
	int			sz_b;
	int			v;
	int			c;
	int			checker;
	int			size;
}				t_stack;

void			align_stack(t_stack *stack);
int				apply_inst(t_stack *stack, char *str);
void			apply_sa(t_stack *stack);
void			apply_sb(t_stack *stack);
void			apply_ss(t_stack *stack);
void			apply_pa(t_stack *stack);
void			apply_pb(t_stack *stack);
void			apply_ra(t_stack *stack);
void			apply_rb(t_stack *stack);
void			apply_rr(t_stack *stack);
void			apply_rra(t_stack *stack);
void			apply_rrb(t_stack *stack);
void			apply_rrr(t_stack *stack);
int				best_opt(int *opts);
int				big(int *stack, int size);
void			check(t_stack *stack);
void			check_doubles(t_stack *stack);
void			check_input(char **str);
int				check_ra(t_stack *stack);
int				check_rb(t_stack *stack);
int				check_rr(t_stack *stack);
int				check_rra(t_stack *stack);
int				check_rrb(t_stack *stack);
int				check_rrr(t_stack *stack);
void			color(t_stack *stack);
void			fill_stack(char **str, int size, t_stack *stack);
void			free_stack(t_stack *stack);
int				ft_line_fill(char **save, char **line, int fd);
int				get_next_line(const int fd, char **line);
void			init_stack(t_stack *stack, int argc, char *argv);
int				is_sorted_a(t_stack *stack);
void			opt_direction(t_stack *stack);
void			print_stacks(t_stack *stack);
void			print_a(t_stack *stack, int a, int b, int c);
void			print_b(t_stack *stack, int a, int b, int c);
void			print_ab(t_stack *stack, int a, int b, int c);
void			push_ra(t_stack *stack);
void			push_rb(t_stack *stack);
void			push_rr(t_stack *stack);
void			push_rra(t_stack *stack);
void			push_rrb(t_stack *stack);
void			push_rrr(t_stack *stack);
void			push(t_stack *stack, int *opts, int best);
void			set_flags(t_stack *stack, char *av);
int				smallest_num(int *stack, int size);
int				smallest_ind(int *stack, int size);
void			sort(t_stack *stack);
void			sort_3(t_stack *stack);
void			sort_rev_3(t_stack *stack);
void			sort2(t_stack *stack);
void			sort3(t_stack *stack);
void			split_input(char **argv, t_stack *stack);

#endif
