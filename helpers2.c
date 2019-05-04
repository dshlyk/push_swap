/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 09:28:54 by sbruen            #+#    #+#             */
/*   Updated: 2019/05/04 09:29:04 by sbruen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		best_opt(int *opts)
{
	int		i;

	i = smallest_ind(opts, 6);
	return (i);
}

void	opt_direction(t_stack *stack)
{
	int		*opts;
	int		best;

	if (stack->st_a[stack->sz_a - 1] > stack->st_b[stack->sz_b - 1] &&
		stack->st_a[0] == big(stack->st_a, stack->sz_a))
	{
		apply_pa(stack);
		return ;
	}
	opts = (int *)malloc(sizeof(int) * 6);
	opts[0] = check_ra(stack);
	opts[1] = check_rb(stack);
	opts[2] = check_rr(stack);
	opts[3] = check_rra(stack);
	opts[4] = check_rrb(stack);
	opts[5] = check_rrr(stack);
	best = best_opt(opts);
	push(stack, opts, best);
	free(opts);
	opts = NULL;
}

void	sort_3(t_stack *stack)
{
	if (stack->st_a[2] == big(stack->st_a, stack->sz_a))
		apply_ra(stack);
	if (stack->st_a[1] == big(stack->st_a, stack->sz_a))
		apply_rra(stack);
	if (stack->st_a[2] > stack->st_a[1])
		apply_sa(stack);
}

void	sort_rev_3(t_stack *stack)
{
	if (stack->st_b[2] == smallest_num(stack->st_b, stack->sz_b))
		apply_rb(stack);
	if (stack->st_b[1] == smallest_num(stack->st_b, stack->sz_b))
		apply_rrb(stack);
	if (stack->st_b[2] < stack->st_b[1])
		apply_sb(stack);
}

void	free_stack(t_stack *stack)
{
	free(stack->st_a);
	free(stack->st_b);
	free(stack);
}
