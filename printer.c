/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 09:50:44 by sbruen            #+#    #+#             */
/*   Updated: 2019/05/04 10:09:25 by sbruen           ###   ########.fr       */
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

void	print_stacks(t_stack *stack)
{
	int		a;
	int		b;
	int		tmp;
	int		tmp1;
	char	*l;

	a = stack->sz_a;
	b = stack->sz_b;
	setlocale(LC_ALL, "");
	color(stack);
	printf("%*s %*s\n", (stack->size / 2), "STACK A", stack->size, "STACK B");
	while ((a > b) ? (a > 0) : (b > 0))
	{
		a--;
		b--;
		if (a > b)
		{
			tmp = stack->st_a[a];
			while (tmp--)
				printf("%lc", (wint_t)9619);
			if (b >= 0)
			{
				printf("%*c", (stack->size + 1 - stack->st_a[a]), ' ');
				tmp1 = stack->st_b[b];
				while (tmp1--)
					printf("%lc", (wint_t)9619);
			}
		}
		else if (b > a)
		{
			if (a >= 0)
			{
				tmp = stack->st_a[a];
				while (tmp--)
					printf("%lc", (wint_t)9619);
				printf("%*c", (stack->size + 1 - stack->st_a[a]), ' ');
			}
			else
				printf("%*c", stack->size + 1, ' ');
			tmp1 = stack->st_b[b];
			while (tmp1--)
				printf("%lc", (wint_t)9619);
		}
		else
		{
			tmp = stack->st_a[a];
			while (tmp--)
				printf("%lc", (wint_t)9619);
			printf("%*c", (stack->size + 1 - stack->st_a[a]), ' ');
			tmp1 = stack->st_b[b];
			while (tmp1--)
				printf("%lc", (wint_t)9619);
		}
		printf("\n");
	}
	printf("\n");
	get_next_line(0, &l);
	free(l);
}

void	set_flags(t_stack *stack, char *av)
{
	if (ft_strequ(av, "-c"))
	{
		stack->c = 1;
		stack->v = 1;
	}
	else if (ft_strequ(av, "-v"))
		stack->v = 1;
	else
	{
		ft_putstr("push_swap: invalid option -- ");
		ft_putendl(av + 1);
		ft_putendl("usage: ./push_swap [-v -c] [numbers ...]");
		exit(1);
	}
}
