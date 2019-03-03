/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 16:05:01 by sbruen            #+#    #+#             */
/*   Updated: 2019/03/03 18:38:23 by sbruen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	init_stack(t_stack *stack, int argc)
{
	if (argc > 2)
	{
		stack->stack_a = (int *)ft_memalloc(4 * (argc - 1));
		stack->size_a = argc - 1;
		stack->stack_b = (int *)ft_memalloc(4 * (argc - 1));
	}
	stack->size_b = 0;
}

void	apply_sa(t_stack *stack)
{
	int		tmp;

	if (stack->size_a < 2)
		return ;
	tmp = stack->stack_a[stack->size_a - 1]; 
	stack->stack_a[stack->size_a - 1] = stack->stack_a[stack->size_a - 2];
	stack->stack_a[stack->size_a - 2] = tmp; 
}

void	apply_sb(t_stack *stack)
{
	int		tmp;

	if (stack->size_b < 2)
		return ;
	tmp = stack->stack_b[stack->size_b - 1]; 
	stack->stack_b[stack->size_b - 1] = stack->stack_b[stack->size_b - 2];
	stack->stack_b[stack->size_b - 2] = tmp; 
}

void	apply_ss(t_stack *stack)
{
	apply_sa(stack);
	apply_sb(stack);
}

void	apply_pa(t_stack *stack)
{
	if (!stack->size_b)
		return ;
	stack->size_a++;
	stack->stack_a[stack->size_a] = stack->stack_b[stack->size_b];
	stack->size_b--;
}

void	apply_pb(t_stack *stack)
{
	if (!stack->size_a)
		return ;
	stack->stack_b[stack->size_b] = stack->stack_a[stack->size_a - 1];
	stack->size_a--;
	stack->size_b++;
}

void	apply_ra(t_stack *stack)
{
	int		i;
	int		tmp;

	i = stack->size_a - 1;
	tmp = stack->stack_a[stack->size_a - 1];
	while (i > 0)
	{
		stack->stack_a[i] = stack->stack_a[i - 1];
		i--;
	}
	stack->stack_a[i] = tmp;
}

void	apply_rb(t_stack *stack)
{
	int		i;
	int		tmp;

	i = stack->size_b - 1;
	tmp = stack->stack_b[stack->size_b - 1];
	while (i > 0)
	{
		stack->stack_b[i] = stack->stack_b[i - 1];
		i--;
	}
	stack->stack_b[i] = tmp;
}

void	apply_rr(t_stack *stack)
{
	apply_ra(stack);
	apply_rb(stack);
}

void	apply_rra(t_stack *stack)
{
	int		i;
	int		tmp;

	i = 0;
	tmp = stack->stack_a[i];
	while (i < stack->size_a - 1)
	{
		stack->stack_a[i] = stack->stack_a[i + 1];
		i++;
	}
	stack->stack_a[i] = tmp;
}

void	apply_rrb(t_stack *stack)
{
	int		i;
	int		tmp;

	i = 0;
	tmp = stack->stack_b[i];
	while (i < stack->size_b - 1)
	{
		stack->stack_b[i] = stack->stack_b[i + 1];
		i++;
	}
	stack->stack_b[i] = tmp;
}

void	apply_rrr(t_stack *stack)
{
	apply_rra(stack);
	apply_rrb(stack);
}

void	check_input(char **str)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i][j])
		{
			if (ft_isdigit(str[i][j]) || str[i][j] == '-' ||
				   str[i][j] == '+' || str[i][j] == ' ')
				j++;
			else
			{
				ft_putstr("error\n");
				exit(1);
			}
		}
		j = 0;
		i++;
	}
}

void	check_doubles(t_stack *stack)
{
	int		i;
	int		j;

	i = 0;
	j = 1;
	while (i < stack->size_a)
	{
		while (j < stack->size_a)
		{
			if (stack->stack_a[i] == stack->stack_a[j])
			{
				ft_putstr("error\n");
				exit(1);
			}
			else
				j++;
		}
		i++;
		j = i + 1;
	}
}

void	fill_stack(char **str, int size, t_stack *stack)
{
	check_input(str);
	while (*str)
	{
		stack->stack_a[size] = ft_atoi(*str);
		size--;
		str++;
	}
	check_doubles(stack);
}

void	split_input(int argc, char **argv, t_stack *stack)
{
	char	**str;
	int		num;
	
	num = ft_words_num(argv[1], ' ');
	stack->size_a = num;
	stack->stack_a = (int *)ft_memalloc(4 * num);
	stack->stack_b = (int *)ft_memalloc(4 * num);
	str = ft_strsplit(argv[1], ' ');
	fill_stack(str, stack->size_a - 1, stack);
}

void	print_stack(int *stack, int size)
{
	while (size)
	{
		printf("%d\n", stack[size - 1]);
		size--;
	}
}

void	print_res(t_stack *stack)
{
	print_stack(stack->stack_a, stack->size_a);
	printf("--\n");
	printf("A\n\n");
	print_stack(stack->stack_b, stack->size_b);
	printf("--\n");
	printf("B\n\n");
}

void	sort(t_stack *stack)
{
	int		i;
	int		bot;

	i = stack->size_a - 1;
	bot = stack->stack_a[0];
	while (i > 0)
	{
		if (bot > stack->stack_a[stack->size_a - 1])
			apply_ra(stack);
		else
			apply_pb(stack);
		print_res(stack);
		i--;
	}

}

int		main(int argc, char **argv)
{
	t_stack	*stack;
	int		i;
	char	**str;

	i = 1;
	stack = (t_stack*)malloc(sizeof(t_stack));
	init_stack(stack, argc);
	if (argc == 2)
		split_input(argc, argv, stack);
	else
		fill_stack(argv + 1, stack->size_a - 1, stack);
	sort(stack);
	print_res(stack);
}
