/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 17:58:31 by sbruen            #+#    #+#             */
/*   Updated: 2019/05/04 09:05:43 by sbruen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int argc, char **argv)
{
	t_stack	*stack;

	(argc == 1) ? exit(0) : 0;
	stack = (t_stack*)malloc(sizeof(t_stack));
	if (argv[1][0] == '-')
	{
		argv++;
		argc--;
		init_stack(stack, argc, argv[1]);
		set_flags(stack, argv[0]);
	}
	else
		init_stack(stack, argc, argv[1]);
	if (argc == 2)
		split_input(argv, stack);
	else
		fill_stack(argv + 1, stack->sz_a - 1, stack);
	stack->size = big(stack->st_a, stack->sz_a);
	if (stack->v)
		print_stacks(stack);
	sort(stack);
	free_stack(stack);
}
