/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 09:32:23 by sbruen            #+#    #+#             */
/*   Updated: 2019/05/04 09:33:16 by sbruen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	apply_ra(t_stack *stack)
{
	int		i;
	int		tmp;

	i = stack->sz_a - 1;
	tmp = stack->st_a[stack->sz_a - 1];
	while (i > 0)
	{
		stack->st_a[i] = stack->st_a[i - 1];
		i--;
	}
	stack->st_a[i] = tmp;
	printf("ra\n");
	if (stack->v)
		print_stacks(stack);
}

void	apply_rb(t_stack *stack)
{
	int		i;
	int		tmp;

	i = stack->sz_b - 1;
	tmp = stack->st_b[stack->sz_b - 1];
	while (i > 0)
	{
		stack->st_b[i] = stack->st_b[i - 1];
		i--;
	}
	stack->st_b[i] = tmp;
	printf("rb\n");
	if (stack->v)
		print_stacks(stack);
}

void	apply_rr(t_stack *stack)
{
	int		i;
	int		tmp;

	i = stack->sz_a - 1;
	tmp = stack->st_a[stack->sz_a - 1];
	while (i > 0)
	{
		stack->st_a[i] = stack->st_a[i - 1];
		i--;
	}
	stack->st_a[i] = tmp;
	i = stack->sz_b - 1;
	tmp = stack->st_b[stack->sz_b - 1];
	while (i > 0)
	{
		stack->st_b[i] = stack->st_b[i - 1];
		i--;
	}
	stack->st_b[i] = tmp;
	printf("rr\n");
	if (stack->v)
		print_stacks(stack);
}

void	apply_rra(t_stack *stack)
{
	int		i;
	int		tmp;

	i = 0;
	tmp = stack->st_a[i];
	while (i < stack->sz_a - 1)
	{
		stack->st_a[i] = stack->st_a[i + 1];
		i++;
	}
	stack->st_a[i] = tmp;
	printf("rra\n");
	if (stack->v)
		print_stacks(stack);
}

void	apply_rrb(t_stack *stack)
{
	int		i;
	int		tmp;

	i = 0;
	tmp = stack->st_b[i];
	while (i < stack->sz_b - 1)
	{
		stack->st_b[i] = stack->st_b[i + 1];
		i++;
	}
	stack->st_b[i] = tmp;
	printf("rrb\n");
	if (stack->v)
		print_stacks(stack);
}
