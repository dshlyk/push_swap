/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 09:31:59 by sbruen            #+#    #+#             */
/*   Updated: 2019/05/04 11:41:50 by sbruen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	apply_sa(t_stack *stack)
{
	int		tmp;

	if (stack->sz_a < 2)
		return ;
	tmp = stack->st_a[stack->sz_a - 1];
	stack->st_a[stack->sz_a - 1] = stack->st_a[stack->sz_a - 2];
	stack->st_a[stack->sz_a - 2] = tmp;
	stack->checker ? 0 : ft_putendl("sa");
	stack->v ? print_stacks(stack) : 0;
}

void	apply_sb(t_stack *stack)
{
	int		tmp;

	if (stack->sz_b < 2)
		return ;
	tmp = stack->st_b[stack->sz_b - 1];
	stack->st_b[stack->sz_b - 1] = stack->st_b[stack->sz_b - 2];
	stack->st_b[stack->sz_b - 2] = tmp;
	stack->checker ? 0 : ft_putendl("sb");
	stack->v ? print_stacks(stack) : 0;
}

void	apply_ss(t_stack *stack)
{
	apply_sa(stack);
	apply_sb(stack);
	stack->v ? print_stacks(stack) : 0;
}

void	apply_pa(t_stack *stack)
{
	if (!stack->sz_b)
		return ;
	stack->st_a[stack->sz_a] = stack->st_b[stack->sz_b - 1];
	stack->sz_a++;
	stack->sz_b--;
	stack->checker ? 0 : ft_putendl("pa");
	stack->v ? print_stacks(stack) : 0;
}

void	apply_pb(t_stack *stack)
{
	if (!stack->sz_a)
		return ;
	stack->st_b[stack->sz_b] = stack->st_a[stack->sz_a - 1];
	stack->sz_a--;
	stack->sz_b++;
	stack->checker ? 0 : ft_putendl("pb");
	stack->v ? print_stacks(stack) : 0;
}
