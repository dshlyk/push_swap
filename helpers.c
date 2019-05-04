/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 09:28:31 by sbruen            #+#    #+#             */
/*   Updated: 2019/05/04 09:28:50 by sbruen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		big(int *stack, int size)
{
	int		i;
	int		num;

	i = 1;
	num = stack[0];
	while (size-- > 1)
	{
		if (stack[i] > num)
			num = stack[i];
		i++;
	}
	return (num);
}

int		smallest_num(int *stack, int size)
{
	int		i;
	int		num;

	i = 1;
	num = stack[0];
	while (size-- > 1)
	{
		if (stack[i] < num)
			num = stack[i];
		i++;
	}
	return (num);
}

int		smallest_ind(int *stack, int size)
{
	int		i;
	int		num;
	int		tmp;

	i = 1;
	num = stack[0];
	while (size-- > 1)
	{
		if (stack[i] < num)
		{
			num = stack[i];
			tmp = i;
		}
		i++;
	}
	if (num == stack[0])
		return (0);
	return (tmp);
}

void	align_stack(t_stack *stack)
{
	if (smallest_ind(stack->st_a, stack->sz_a) > (stack->sz_a / 2))
		while (stack->st_a[0] != big(stack->st_a, stack->sz_a))
			apply_ra(stack);
	else
		while (stack->st_a[0] != big(stack->st_a, stack->sz_a))
			apply_rra(stack);
}

int		is_sorted_a(t_stack *stack)
{
	int		i;

	i = stack->sz_a - 1;
	while (i > 0)
	{
		if (stack->st_a[i] < stack->st_a[i - 1])
			i--;
		else
			return (0);
	}
	return (1);
}
