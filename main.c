/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 16:05:01 by sbruen            #+#    #+#             */
/*   Updated: 2019/03/24 18:01:26 by sbruen           ###   ########.fr       */
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
	printf("sa\n");
}

void	apply_sb(t_stack *stack)
{
	int		tmp;

	if (stack->size_b < 2)
		return ;
	tmp = stack->stack_b[stack->size_b - 1]; 
	stack->stack_b[stack->size_b - 1] = stack->stack_b[stack->size_b - 2];
	stack->stack_b[stack->size_b - 2] = tmp; 
	printf("sb\n");
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
	stack->stack_a[stack->size_a] = stack->stack_b[stack->size_b - 1];
	stack->size_a++;
	stack->size_b--;
	printf("pa\n");
}

void	apply_pb(t_stack *stack)
{
	if (!stack->size_a)
		return ;
	stack->stack_b[stack->size_b] = stack->stack_a[stack->size_a - 1];
	stack->size_a--;
	stack->size_b++;
	printf("pb\n");
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
	printf("ra\n");
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
	printf("rb\n");
}

void	apply_rr(t_stack *stack)
{
	apply_ra(stack);
	apply_rb(stack);
	printf("rr\n");
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
	printf("rra\n");
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
	printf("rrb\n");
}

void	apply_rrr(t_stack *stack)
{
	apply_rra(stack);
	apply_rrb(stack);
	printf("rrr\n");
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

void	print_stack(t_stack *stack)
{
	int		size;
	int		size_a;
	int		size_b;

	size = (stack->size_a > stack->size_b ? stack->size_a : stack->size_b);
	size_a = stack->size_a - 1;
	size_b = stack->size_b - 1;
	while (size)
	{
		if (size_a > size_b)
		{
			printf("%3d\n", stack->stack_a[size_a]);
			size_a--;
		}
		if (size_a < size_b)
		{
			printf("%9d\n", stack->stack_b[size_b]);
			size_b--;
		}
		else
		{
			printf("%3d", stack->stack_a[size_a]);
			printf("%6d\n", stack->stack_b[size_b]);
			size_a--;
			size_b--;
		}
		size--;
	}
}

void	print_res(t_stack *stack)
{
	print_stack(stack);
	printf("%3s %6s\n", "__", "__");
	printf("%3s %6s\n", "A", "B");
}

int		biggest_num(int *stack, int size)
{
	int		i;
	int		num;

	i = 1;
	num = stack[0];
	while (size-- > 1)
	{
		if (stack[i] > num)
			num = stack[i];
		i++;
	}
	return (num);
}

int		smallest_num(int *stack, int size)
{
	int		i;
	int		num;

	i = 1;
	num = stack[0];
	while (size-- > 1)
	{
		if (stack[i] < num)
			num = stack[i];
		i++;
	}
	return (num);
}

void	print_arr(int *arr, int size)
{
	int		i;

	i = size - 1;
	while (size--)
	{
		printf("%d\n", arr[i]);
		i--;
	}
}

void	sort(t_stack *stack)
{
	int		middle;
	int		tmp;
	int		big;
	int		small;
	int		j;

	big = biggest_num(stack->stack_a, stack->size_a);
	small = smallest_num(stack->stack_a, stack->size_a);
	middle = (small + big) / 2;
	tmp = stack->size_a - 1;
	j = 0;
	if (stack->stack_a[stack->size_a - 1] < middle)
	{
		apply_pb(stack);
		j++;
	}
	else
		apply_ra(stack);
	if (stack->stack_a[0] != big || stack->size_a > 2)
	{
		/*printf("A:\n");
		print_arr(stack->stack_a, stack->size_a);
		printf("------------------\n");
		printf("B:\n");
		print_arr(stack->stack_b, stack->size_b);
		printf("------------------\n");*/
		big = biggest_num(stack->stack_b, stack->size_b);
		if (stack->size_b == 2 && stack->stack_b[stack->size_b - 1] < stack->stack_b[0])
			apply_sb(stack);
		if (stack->size_b == 3)
		{
			if (stack->stack_b[stack->size_b - 1] < stack->stack_b[stack->size_b - 2])
				apply_sb(stack);
			if (stack->stack_b[stack->size_b - 2] < stack->stack_b[0])
			{
				apply_rrb(stack);
				apply_sb(stack);
			}
			if (stack->stack_b[stack->size_b - 1] < stack->stack_b[stack->size_b - 2])
				apply_sb(stack);
		}
		if (stack->stack_b[stack->size_b - 1] < stack->stack_b[0] && stack->size_b > 3)
			apply_rb(stack);
		else if (stack->stack_b[stack->size_b - 1] < stack->stack_b[stack->size_b - 2] && stack->size_b > 3)
		{
			while (stack->stack_b[stack->size_b - 1] < stack->stack_b[stack->size_b - 2])
			{
				apply_sb(stack);
				apply_rb(stack);
			}
		}
		else if (stack->stack_b[stack->size_b - 1] > stack->stack_b[0] && stack->stack_b[stack->size_b - 1] != big && stack->size_b > 3)
		{
			while (stack->stack_b[stack->size_b - 1] > stack->stack_b[0] && stack->stack_b[stack->size_b - 1] != big)
			{
				apply_rrb(stack);
				apply_sb(stack);
			}
		}
		while (stack->stack_b[stack->size_b - 1] != big && stack->size_b > 3)
			apply_rrb(stack);
		sort(stack);
	}
	apply_pa(stack);
	/*while (j--)
	{
		while (stack->stack_b[stack->size_b - 1] != big)
		{
			apply_rb(stack);
			i++;
		}
		if (stack->stack_b[stack->size_b - 1] == big)
			apply_pa(stack);
		while (i--)
			apply_rrb(stack);
	}*/
}

int		main(int argc, char **argv)
{
	t_stack	*stack;
	int		i;

	stack = (t_stack*)malloc(sizeof(t_stack));
	i = 0;
	init_stack(stack, argc);
	if (argc == 2)
		split_input(argc, argv, stack);
	else
		fill_stack(argv + 1, stack->size_a - 1, stack);
	sort(stack);
	print_arr(stack->stack_a, stack->size_a);
	//printf("------------------\n");
	//print_arr(stack->stack_b, stack->size_b);
	//print_res(stack);*/
}
