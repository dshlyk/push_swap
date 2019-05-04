/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 12:50:22 by sbruen            #+#    #+#             */
/*   Updated: 2019/05/04 08:39:16 by sbruen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		apply_inst(t_stack *stack, char *str)
{
	if (ft_strequ(str, "pa"))
		apply_pa(stack);
	else if (ft_strequ(str, "pb"))
		apply_pb(stack);
	else if (ft_strequ(str, "ra"))
		apply_ra(stack);
	else if (ft_strequ(str, "rb"))
		apply_rb(stack);
	else if (ft_strequ(str, "rr"))
		apply_rr(stack);
	else if (ft_strequ(str, "rra"))
		apply_rra(stack);
	else if (ft_strequ(str, "rrb"))
		apply_rrb(stack);
	else if (ft_strequ(str, "rrr"))
		apply_rrr(stack);
	else if (ft_strequ(str, "sa"))
		apply_sa(stack);
	else if (ft_strequ(str, "sb"))
		apply_sb(stack);
	else
		return (1);
	return (0);
}

void	check(t_stack *stack)
{
	char	*inst;

	while (get_next_line(0, &inst) > 0)
	{
		if (!inst)
			break ;
		if (apply_inst(stack, inst))
		{
			ft_putstr_fd("Error\n", 2);
			free_stack(stack);
			free(inst);
			exit(1);
		}
		free(inst);
		inst = NULL;
	}
	free(inst);
}

int		main(int argc, char **argv)
{
	t_stack	*stack;

	(argc == 1) ? exit(0) : 0;
	stack = (t_stack*)malloc(sizeof(t_stack));
	init_stack(stack, argc, argv[1]);
	if (argc == 2)
		split_input(argv, stack);
	else
		fill_stack(argv + 1, stack->sz_a - 1, stack);
	if (!(is_sorted_a(stack)))
		check(stack);
	if (is_sorted_a(stack))
		ft_putendl("OK");
	else
		ft_putendl("KO");
	free_stack(stack);
}
