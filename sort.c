/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 16:05:01 by sbruen            #+#    #+#             */
/*   Updated: 2019/05/04 09:33:27 by sbruen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_stack *stack, int argc, char *argv)
{
	if (argc > 2)
	{
		stack->sz_a = argc - 1;
		stack->st_a = (int *)ft_memalloc(4 * (argc - 1));
		stack->st_b = (int *)ft_memalloc(4 * (argc - 1));
	}
	else
	{
		stack->sz_a = ft_words_num(argv, ' ');
		stack->st_a = (int *)ft_memalloc(4 * stack->sz_a);
		stack->st_b = (int *)ft_memalloc(4 * stack->sz_a);
	}
	stack->sz_b = 0;
	stack->v = 0;
	stack->c = 0;
}

void	sort2(t_stack *stack)
{
	int		middle;
	int		bigg;
	int		small;

	while (stack->sz_a > 3)
	{
		bigg = big(stack->st_a, stack->sz_a);
		small = smallest_num(stack->st_a, stack->sz_a);
		middle = (small + bigg) / 2;
		if (stack->st_a[stack->sz_a - 1] < middle)
			apply_pb(stack);
		else
			apply_ra(stack);
	}
	if (stack->sz_a == 3)
		sort_3(stack);
	if (stack->sz_b == 2)
	{
		if (stack->st_b[1] < stack->st_b[0])
			apply_sb(stack);
		apply_pa(stack);
		apply_pa(stack);
		exit(1);
	}
}

void	sort3(t_stack *stack)
{
	int		middle;
	int		bigg;
	int		small;
	int		i;

	i = 0;
	while (stack->sz_b > 3)
	{
		bigg = big(stack->st_b, stack->sz_b);
		small = smallest_num(stack->st_b, stack->sz_b);
		middle = (small + bigg) / 2;
		if (stack->st_b[stack->sz_b - 1] > middle)
		{
			apply_pa(stack);
			i++;
		}
		else
			apply_rb(stack);
	}
	if (stack->sz_b == 3)
		sort_rev_3(stack);
	while (i-- >= 0)
		apply_pb(stack);
}

void	sort(t_stack *stack)
{
	int		middle;

	if (!is_sorted_a(stack) && stack->sz_a == 2)
		apply_sa(stack);
	if (stack->sz_a == 3)
		sort_3(stack);
	if (is_sorted_a(stack) && stack->sz_b == 0)
		return ;
	sort2(stack);
	middle = stack->sz_b / 2;
	while (stack->sz_b != 1)
	{
		if (stack->sz_b < middle && stack->sz_b > 100)
		{
			middle = stack->sz_b / 2;
			sort3(stack);
		}
		opt_direction(stack);
	}
	if (check_ra(stack) > check_rra(stack))
		push_rra(stack);
	else
		push_ra(stack);
	align_stack(stack);
}
