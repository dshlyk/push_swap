/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 09:50:44 by sbruen            #+#    #+#             */
/*   Updated: 2019/05/16 13:15:25 by sbruen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	color(t_stack *stack)
{
	if (stack->c)
	{
		if (is_sorted_a(stack))
			ft_putstr(GREEN);
		else
			ft_putstr(RED);
	}
}

void	print_a(t_stack *stack, int a, int b, int c)
{
	int		tmp;

	tmp = stack->st_a[a];
	while (tmp--)
		printf("%lc", c);
	if (b >= 0)
	{
		printf("%*c", (stack->size + 1 - stack->st_a[a]), ' ');
		tmp = stack->st_b[b];
		while (tmp--)
			printf("%lc", c);
	}
}

void	print_b(t_stack *stack, int a, int b, int c)
{
	int		tmp;

	if (a >= 0)
	{
		tmp = stack->st_a[a];
		while (tmp--)
			printf("%lc", c);
		printf("%*c", (stack->size + 1 - stack->st_a[a]), ' ');
	}
	else
		printf("%*c", stack->size + 1, ' ');
	tmp = stack->st_b[b];
	while (tmp--)
		printf("%lc", c);
}

void	print_ab(t_stack *stack, int a, int b, int c)
{
	int		tmp;

	tmp = stack->st_a[a];
	while (tmp--)
		printf("%lc", c);
	printf("%*c", (stack->size + 1 - stack->st_a[a]), ' ');
	tmp = stack->st_b[b];
	while (tmp--)
		printf("%lc", c);
}

void	print_stacks(t_stack *stack)
{
	int		a;
	int		b;
	char	*l;

	stack->sym = 0x2593;
	a = stack->sz_a;
	b = stack->sz_b;
	setlocale(LC_CTYPE, "UTF-8");
	color(stack);
	print_space();
	printf("%*s %*s\n", (stack->size / 2), "STACK A", stack->size, "STACK B");
	while ((a > b) ? (a > 0) : (b > 0))
	{
		a--;
		b--;
		if (a > b)
			print_a(stack, a, b, stack->sym);
		else if (b > a)
			print_b(stack, a, b, stack->sym);
		else
			print_ab(stack, a, b, stack->sym);
		printf("\n");
	}
	get_next_line(0, &l);
	free(l);
}
