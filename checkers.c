/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 09:32:47 by sbruen            #+#    #+#             */
/*   Updated: 2019/05/08 12:07:41 by sbruen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_ra(t_stack *s)
{
	int		i;
	int		a;
	int		b;

	i = 0;
	a = s->sz_a - 1;
	b = s->sz_b - 1;
	if (!(s->st_a[a] > s->st_b[b] && s->st_a[0] < s->st_b[b]))
	{
		a--;
		i++;
	}
	while (!(s->st_a[a] > s->st_b[b] && s->st_a[a + 1] < s->st_b[b]) && a)
	{
		if (s->st_a[a] > s->st_b[b] && s->st_a[a + 1] == big(s->st_a, s->sz_a))
			return (i);
		a--;
		i++;
	}
	if (!(s->st_a[a] > s->st_b[b] && s->st_a[0] < s->st_b[b]) && !a)
		return (9999);
	return (i);
}

int		check_rb(t_stack *s)
{
	int		i;
	int		a;
	int		b;

	i = 0;
	a = s->sz_a - 1;
	b = s->sz_b - 1;
	if (!(s->st_a[a] > s->st_b[b] && s->st_a[0] < s->st_b[b]))
	{
		b--;
		i++;
	}
	while (!(s->st_a[a] > s->st_b[b] && s->st_a[0] < s->st_b[b]) && b)
	{
		if (s->st_a[a] > s->st_b[b] && s->st_a[a + 1] == big(s->st_a, s->sz_a))
			return (i);
		b--;
		i++;
	}
	if (!(s->st_a[a] > s->st_b[b] && s->st_a[0] < s->st_b[b]) && !b)
		return (9999);
	return (i);
}

int		check_rr(t_stack *s)
{
	int		i;
	int		a;
	int		b;

	i = 0;
	a = s->sz_a - 1;
	b = s->sz_b - 1;
	if (!(s->st_a[a] > s->st_b[b] && s->st_a[0] < s->st_b[b]))
	{
		a--;
		b--;
		i++;
	}
	while (a && b && !(s->st_a[a] > s->st_b[b] && s->st_a[a + 1] < s->st_b[b]))
	{
		if (s->st_a[a] > s->st_b[b] && s->st_a[a + 1] == big(s->st_a, s->sz_a))
			return (i);
		a--;
		b--;
		i++;
	}
	if (!(s->st_a[a] > s->st_b[b] && s->st_a[a + 1] < s->st_b[b]) && (!b || !a))
		return (9999);
	return (i);
}

int		check_rra(t_stack *s)
{
	int		i;
	int		a;
	int		b;

	i = 0;
	a = s->sz_a - 1;
	b = s->sz_b - 1;
	if (!(s->st_a[a] > s->st_b[b] && s->st_a[0] < s->st_b[b]))
	{
		a = 0;
		i++;
	}
	while (!(s->st_a[a] > s->st_b[b] && s->st_a[a + 1] < s->st_b[b]) &&
			a < s->sz_a)
	{
		if (s->st_a[a] > s->st_b[b] && s->st_a[a + 1] == big(s->st_a, s->sz_a))
			return (i);
		a++;
		i++;
	}
	if (!(s->st_a[a] > s->st_b[b] && s->st_a[0] < s->st_b[b]) && b == s->sz_b)
		return (9999);
	return (i);
}

int		check_rrb(t_stack *s)
{
	int		i;
	int		a;
	int		b;

	i = 0;
	a = s->sz_a - 1;
	b = s->sz_b - 1;
	if (!(s->st_a[a] > s->st_b[b] && s->st_a[0] < s->st_b[b]))
	{
		b = 0;
		i++;
	}
	while (!(s->st_a[a] > s->st_b[b] && s->st_a[0] < s->st_b[b]) && b < s->sz_b)
	{
		if (s->st_a[a] > s->st_b[b] && s->st_a[a + 1] == big(s->st_a, s->sz_a))
			return (i);
		b++;
		i++;
	}
	if (!(s->st_a[a] > s->st_b[b] && s->st_a[0] < s->st_b[b]) && b == s->sz_b)
		return (9999);
	return (i);
}
