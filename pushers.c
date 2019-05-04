/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 09:33:58 by sbruen            #+#    #+#             */
/*   Updated: 2019/05/04 09:34:06 by sbruen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_ra(t_stack *s)
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
		apply_ra(s);
	}
	apply_pa(s);
}

void	push_rb(t_stack *s)
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
		apply_rb(s);
	}
	apply_pa(s);
}

void	push_rr(t_stack *s)
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
		apply_rr(s);
	}
	apply_pa(s);
}

void	push_rra(t_stack *s)
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
		apply_rra(s);
	}
	apply_pa(s);
}

void	push_rrb(t_stack *s)
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
		apply_rrb(s);
	}
	apply_pa(s);
}
