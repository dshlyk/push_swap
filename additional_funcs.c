/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_funcs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 09:26:37 by sbruen            #+#    #+#             */
/*   Updated: 2019/05/04 09:27:26 by sbruen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	apply_rrr(t_stack *stack)
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
	i = 0;
	tmp = stack->st_b[i];
	while (i < stack->sz_b - 1)
	{
		stack->st_b[i] = stack->st_b[i + 1];
		i++;
	}
	stack->st_b[i] = tmp;
	printf("rrr\n");
	if (stack->v)
		print_stacks(stack);
}

int		check_rrr(t_stack *s)
{
	int		i;
	int		a;
	int		b;

	a = s->sz_a - 1;
	b = s->sz_b - 1;
	i = (!(s->st_a[a] > s->st_b[b] && s->st_a[0] < s->st_b[b])) ? 1 : 0;
	a = (!(s->st_a[a] > s->st_b[b] && s->st_a[0] < s->st_b[b])) ? 0 : a;
	b = (!(s->st_a[a] > s->st_b[b] && s->st_a[0] < s->st_b[b])) ? 0 : b;
	while (!(s->st_a[a] > s->st_b[b] && s->st_a[a + 1] < s->st_b[b]) &&
			(a < s->sz_a || b < s->sz_b))
	{
		if (s->st_a[a] > s->st_b[b] && s->st_a[a + 1] == big(s->st_a, s->sz_a))
			return (i);
		a++;
		b++;
		i++;
	}
	if (!(s->st_a[a] > s->st_b[b] && s->st_a[0] < s->st_b[b]) &&
		(b >= s->sz_b || a >= s->sz_a))
		return (9999);
	return (i);
}

void	push_rrr(t_stack *s)
{
	int		tmp_a;
	int		tmp_b;

	tmp_a = s->sz_a - 1;
	tmp_b = s->sz_b - 1;
	while (!(s->st_a[tmp_a] > s->st_b[tmp_b] && s->st_a[0] < s->st_b[tmp_b]))
	{
		if (s->st_a[tmp_a] > s->st_b[tmp_b] &&
			s->st_a[0] == big(s->st_a, s->sz_a))
		{
			apply_pa(s);
			return ;
		}
		apply_rrr(s);
	}
	apply_pa(s);
}

void	push(t_stack *stack, int *opts, int best)
{
	if (opts[best] == 0)
		apply_pa(stack);
	else if (best == 0)
		push_ra(stack);
	else if (best == 1)
		push_rb(stack);
	else if (best == 2)
		push_rr(stack);
	else if (best == 3)
		push_rra(stack);
	else if (best == 4)
		push_rrb(stack);
	else if (best == 5)
		push_rrr(stack);
}
