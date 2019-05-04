/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 09:31:59 by sbruen            #+#    #+#             */
/*   Updated: 2019/05/04 09:32:13 by sbruen           ###   ########.fr       */
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
	printf("sa\n");
	if (stack->v)
		print_stacks(stack);
}

void	apply_sb(t_stack *stack)
{
	int		tmp;

	if (stack->sz_b < 2)
		return ;
	tmp = stack->st_b[stack->sz_b - 1];
	stack->st_b[stack->sz_b - 1] = stack->st_b[stack->sz_b - 2];
	stack->st_b[stack->sz_b - 2] = tmp;
	printf("sb\n");
	if (stack->v)
		print_stacks(stack);
}

void	apply_ss(t_stack *stack)
{
	apply_sa(stack);
	apply_sb(stack);
	if (stack->v)
		print_stacks(stack);
}

void	apply_pa(t_stack *stack)
{
	if (!stack->sz_b)
		return ;
	stack->st_a[stack->sz_a] = stack->st_b[stack->sz_b - 1];
	stack->sz_a++;
	stack->sz_b--;
	printf("pa\n");
	if (stack->v)
		print_stacks(stack);
}

void	apply_pb(t_stack *stack)
{
	if (!stack->sz_a)
		return ;
	stack->st_b[stack->sz_b] = stack->st_a[stack->sz_a - 1];
	stack->sz_a--;
	stack->sz_b++;
	printf("pb\n");
	if (stack->v)
		print_stacks(stack);
}
