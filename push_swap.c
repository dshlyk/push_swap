/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 17:58:31 by sbruen            #+#    #+#             */
/*   Updated: 2019/04/25 15:46:20 by sbruen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int argc, char **argv)
{
	t_stack	*stack;
	
	stack = (t_stack*)malloc(sizeof(t_stack));
	init_stack(stack, argc, argv[1]);
	if (argc == 2)
		split_input(argv, stack);
	else
		fill_stack(argv + 1, stack->sz_a - 1, stack);
	sort(stack);
	free_stack(stack);
}
