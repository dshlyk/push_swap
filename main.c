/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 16:05:01 by sbruen            #+#    #+#             */
/*   Updated: 2019/04/11 17:46:36 by sbruen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	sort(t_stack *stack);

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
	i = stack->size_b - 1;
	tmp = stack->stack_b[stack->size_b - 1];
	while (i > 0)
	{
		stack->stack_b[i] = stack->stack_b[i - 1];
		i--;
	}
	stack->stack_b[i] = tmp;
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
	i = 0;
	tmp = stack->stack_b[i];
	while (i < stack->size_b - 1)
	{
		stack->stack_b[i] = stack->stack_b[i + 1];
		i++;
	}
	stack->stack_b[i] = tmp;
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

int		smallest_ind(int *stack, int size)
{
	int		i;
	int		num;
	int		tmp;

	i = 1;
	num = stack[0];
	while (size-- > 1)
	{
		if (stack[i] < num)
		{
			num = stack[i];
			tmp = i;
		}
		i++;
	}
	if (num == stack[0])
		return (0);
	return (tmp);
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

int		check_ra(t_stack *stack)
{
	int		i;
	int		tmp_a;
	int		tmp_b;

	i = 0;
	tmp_a = stack->size_a - 1;
	tmp_b = stack->size_b - 1;
	if (stack->stack_a[tmp_a] > stack->stack_b[tmp_b] && stack->stack_a[0] == biggest_num(stack->stack_a, stack->size_a))
		return (0);
	else if (!(stack->stack_a[tmp_a] > stack->stack_b[tmp_b] && stack->stack_a[0] < stack->stack_b[tmp_b]))
	{
		tmp_a--;
		i++;
	}
	while (!(stack->stack_a[tmp_a] > stack->stack_b[tmp_b] && stack->stack_a[tmp_a + 1] < stack->stack_b[tmp_b]) && tmp_a)
	{
		if (stack->stack_a[tmp_a] > stack->stack_b[tmp_b] && stack->stack_a[tmp_a + 1] == biggest_num(stack->stack_a, stack->size_a))
			return (i);
		tmp_a--;
		i++;
	}
	if (!(stack->stack_a[tmp_a] > stack->stack_b[tmp_b] && stack->stack_a[0] < stack->stack_b[tmp_b]) && !tmp_b)
		return (9999);
	return (i);
}

int		check_rb(t_stack *stack)
{
	int		i;
	int		tmp_a;
	int		tmp_b;

	i = 0;
	tmp_a = stack->size_a - 1;
	tmp_b = stack->size_b - 1;
	if (stack->stack_a[tmp_a] > stack->stack_b[tmp_b] && stack->stack_a[0] == biggest_num(stack->stack_a, stack->size_a))
		return (0);
	else if (!(stack->stack_a[tmp_a] > stack->stack_b[tmp_b] && stack->stack_a[0] < stack->stack_b[tmp_b]))
	{
		tmp_b--;
		i++;
	}
	while (!(stack->stack_a[tmp_a] > stack->stack_b[tmp_b] && stack->stack_a[0] < stack->stack_b[tmp_b]) && tmp_b)
	{
		if (stack->stack_a[tmp_a] > stack->stack_b[tmp_b] && stack->stack_a[tmp_a + 1] == biggest_num(stack->stack_a, stack->size_a))
			return (i);
		tmp_b--;
		i++;
	}
	if (!(stack->stack_a[tmp_a] > stack->stack_b[tmp_b] && stack->stack_a[0] < stack->stack_b[tmp_b]) && !tmp_b)
		return (9999);
	return (i);
}

int		check_rr(t_stack *stack)
{
	int		i;
	int		tmp_a;
	int		tmp_b;

	i = 0;
	tmp_a = stack->size_a - 1;
	tmp_b = stack->size_b - 1;
	if (stack->stack_a[tmp_a] > stack->stack_b[tmp_b] && stack->stack_a[0] == biggest_num(stack->stack_a, stack->size_a))
		return (0);
	else if (!(stack->stack_a[tmp_a] > stack->stack_b[tmp_b] && stack->stack_a[0] < stack->stack_b[tmp_b]))
	{
		tmp_a--;
		tmp_b--;
		i++;
	}
	while (tmp_a && tmp_b && !(stack->stack_a[tmp_a] > stack->stack_b[tmp_b] && stack->stack_a[tmp_a + 1] < stack->stack_b[tmp_b])) 
	{
		if (stack->stack_a[tmp_a] > stack->stack_b[tmp_b] && stack->stack_a[tmp_a + 1] == biggest_num(stack->stack_a, stack->size_a))
			return (i);
		tmp_a--;
		tmp_b--;
		i++;
	}
	if (!(stack->stack_a[tmp_a] > stack->stack_b[tmp_b] && stack->stack_a[tmp_a + 1] < stack->stack_b[tmp_b]) && !tmp_b)
		return (9999);
	return (i);
}

int		check_rra(t_stack *stack)
{
	int		i;
	int		tmp_a;
	int		tmp_b;

	i = 0;
	tmp_a = stack->size_a - 1;
	tmp_b = stack->size_b - 1;
	if (stack->stack_a[tmp_a] > stack->stack_b[tmp_b] && stack->stack_a[0] == biggest_num(stack->stack_a, stack->size_a))
		return (0);
	else if (!(stack->stack_a[tmp_a] > stack->stack_b[tmp_b] && stack->stack_a[0] < stack->stack_b[tmp_b]))
	{
		tmp_a = 0;
		i++;
	}
	while (!(stack->stack_a[tmp_a] > stack->stack_b[tmp_b] && stack->stack_a[tmp_a + 1] < stack->stack_b[tmp_b]) && tmp_a < stack->size_a)
	{
		if (stack->stack_a[tmp_a] > stack->stack_b[tmp_b] && stack->stack_a[tmp_a + 1] == biggest_num(stack->stack_a, stack->size_a))
			return (i);
		tmp_a++;
		i++;
	}
	if (!(stack->stack_a[tmp_a] > stack->stack_b[tmp_b] && stack->stack_a[0] < stack->stack_b[tmp_b]) && tmp_b == stack->size_b)
		return (9999);
	return (i);
}

int		check_rrb(t_stack *stack)
{
	int		i;
	int		tmp_a;
	int		tmp_b;

	i = 0;
	tmp_a = stack->size_a - 1;
	tmp_b = stack->size_b - 1;
	if (stack->stack_a[tmp_a] > stack->stack_b[tmp_b] && stack->stack_a[0] == biggest_num(stack->stack_a, stack->size_a))
		return (0);
	else if (!(stack->stack_a[tmp_a] > stack->stack_b[tmp_b] && stack->stack_a[0] < stack->stack_b[tmp_b]))
	{
		tmp_b = 0;
		i++;
	}
	while (!(stack->stack_a[tmp_a] > stack->stack_b[tmp_b] && stack->stack_a[0] < stack->stack_b[tmp_b]) && tmp_b < stack->size_b)
	{
		if (stack->stack_a[tmp_a] > stack->stack_b[tmp_b] && stack->stack_a[tmp_a + 1] == biggest_num(stack->stack_a, stack->size_a))
			return (i);
		tmp_b++;
		i++;
	}
	if (!(stack->stack_a[tmp_a] > stack->stack_b[tmp_b] && stack->stack_a[0] < stack->stack_b[tmp_b]) && tmp_b == stack->size_b)
		return (9999);
	return (i);
}

int		check_rrr(t_stack *stack)
{
	int		i;
	int		tmp_a;
	int		tmp_b;

	i = 0;
	tmp_a = stack->size_a - 1;
	tmp_b = stack->size_b - 1;	
	if (stack->stack_a[tmp_a] > stack->stack_b[tmp_b] && stack->stack_a[0] == biggest_num(stack->stack_a, stack->size_a))
		return (0);
	else if (!(stack->stack_a[tmp_a] > stack->stack_b[tmp_b] && stack->stack_a[0] < stack->stack_b[tmp_b]))
	{
		tmp_a = 0;
		tmp_b = 0;
		i++;
	}
	while (!(stack->stack_a[tmp_a] > stack->stack_b[tmp_b] && stack->stack_a[tmp_a + 1] < stack->stack_b[tmp_b]) && (tmp_a < stack->size_a || tmp_b < stack->size_b))
	{
		if (stack->stack_a[tmp_a] > stack->stack_b[tmp_b] && stack->stack_a[tmp_a + 1] == biggest_num(stack->stack_a, stack->size_a))
			return (i);
		tmp_a++;
		tmp_b++;
		i++;
	}
	if (!(stack->stack_a[tmp_a] > stack->stack_b[tmp_b] && stack->stack_a[0] < stack->stack_b[tmp_b]) && (tmp_b >= stack->size_b || tmp_a >= stack->size_a))
		return (9999);
	return (i);
}

void	push_ra(t_stack *stack)
{
	int		tmp_a;
	int		tmp_b;

	tmp_a = stack->size_a - 1;
	tmp_b = stack->size_b - 1;
	while (!(stack->stack_a[tmp_a] > stack->stack_b[tmp_b] && stack->stack_a[0] < stack->stack_b[tmp_b]))
	{
		if (stack->stack_a[tmp_a] > stack->stack_b[tmp_b] && stack->stack_a[0] == biggest_num(stack->stack_a, stack->size_a))
		{
			apply_pa(stack);
			return ;
		}
		apply_ra(stack);
	}
	apply_pa(stack);
}

void	push_rb(t_stack *stack)
{
	int		tmp_a;
	int		tmp_b;
	int		i;

	tmp_a = stack->size_a - 1;
	tmp_b = stack->size_b - 1;
	i = stack->size_b;
	while (!(stack->stack_a[tmp_a] > stack->stack_b[tmp_b] && stack->stack_a[0] < stack->stack_b[tmp_b]))
	{
		if (stack->stack_a[tmp_a] > stack->stack_b[tmp_b] && stack->stack_a[0] == biggest_num(stack->stack_a, stack->size_a))
		{
			apply_pa(stack);
			return ;
		}
		apply_rb(stack);
	}
	apply_pa(stack);
}

void	push_rr(t_stack *stack)
{
	int		tmp_a;
	int		tmp_b;

	tmp_a = stack->size_a - 1;
	tmp_b = stack->size_b - 1;
	while (!(stack->stack_a[tmp_a] > stack->stack_b[tmp_b] && stack->stack_a[0] < stack->stack_b[tmp_b]))
	{
		if (stack->stack_a[tmp_a] > stack->stack_b[tmp_b] && stack->stack_a[0] == biggest_num(stack->stack_a, stack->size_a))
		{
			apply_pa(stack);
			return ;
		}
		apply_rr(stack);
	}
	apply_pa(stack);
}

void	push_rra(t_stack *stack)
{
	int		tmp_a;
	int		tmp_b;

	tmp_a = stack->size_a - 1;
	tmp_b = stack->size_b - 1;
	while (!(stack->stack_a[tmp_a] > stack->stack_b[tmp_b] && stack->stack_a[0] < stack->stack_b[tmp_b]))
	{
		if (stack->stack_a[tmp_a] > stack->stack_b[tmp_b] && stack->stack_a[0] == biggest_num(stack->stack_a, stack->size_a))
		{
			apply_pa(stack);
			return ;
		}
		apply_rra(stack);
	}
	apply_pa(stack);
}

void	push_rrb(t_stack *stack)
{
	int		tmp_a;
	int		tmp_b;
	int		i;

	tmp_a = stack->size_a - 1;
	tmp_b = stack->size_b - 1;
	while (!(stack->stack_a[tmp_a] > stack->stack_b[tmp_b] && stack->stack_a[0] < stack->stack_b[tmp_b]))
	{
		if (stack->stack_a[tmp_a] > stack->stack_b[tmp_b] && stack->stack_a[0] == biggest_num(stack->stack_a, stack->size_a))
		{
			apply_pa(stack);
			return ;
		}
		apply_rrb(stack);
	}
	apply_pa(stack);
}

void	push_rrr(t_stack *stack)
{
	int		tmp_a;
	int		tmp_b;

	tmp_a = stack->size_a - 1;
	tmp_b = stack->size_b - 1;
	while (!(stack->stack_a[tmp_a] > stack->stack_b[tmp_b] && stack->stack_a[0] < stack->stack_b[tmp_b]))
	{
		if (stack->stack_a[tmp_a] > stack->stack_b[tmp_b] && stack->stack_a[0] == biggest_num(stack->stack_a, stack->size_a))
		{
			apply_pa(stack);
			return ;
		}
		apply_rrr(stack);
	}
	apply_pa(stack);
}


int		best_opt(int *opts)
{
	int		i;

	i = smallest_ind(opts, 6);
	return (i);
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

void	opt_direction(t_stack *stack)
{
	int		*opts;
	int		best;

	opts = (int *)malloc(sizeof(int) * 6);
	opts[0] = check_ra(stack);
	opts[1] = check_rb(stack);
	opts[2] = check_rr(stack);
	opts[3] = check_rra(stack);
	opts[4] = check_rrb(stack);
	opts[5] = check_rrr(stack);
//	print_arr(stack->stack_a, stack->size_a);
//	printf("------------------\n");
//	print_arr(stack->stack_b, stack->size_b);
//	printf("------------------\n");
//	printf("------------------\n");
//	printf("\033[1;31m");
//	print_arr(opts, 6);
//	printf("\033[0m;\n");
	best = best_opt(opts);
//	printf("\033[1;32m");
//	printf("%d\n", best);
//	printf("\033[0m;");
	push(stack, opts, best);
}

void	align_stack(t_stack *stack)
{
	if (smallest_ind(stack->stack_a, stack->size_a) > (stack->size_a / 2))
		while (stack->stack_a[0] != biggest_num(stack->stack_a, stack->size_a))
			apply_ra(stack);
	else
		while (stack->stack_a[0] != biggest_num(stack->stack_a, stack->size_a))
			apply_rra(stack);
}

/*void	sort2(t_stack *stack)
{
	int		middle;
	int		big;
	int		small;
	
	if (stack->size_a == 3)
	{
		if (stack->stack_a[2] == biggest_num(stack->stack_a, stack->size_a))
			apply_ra(stack);
		if (stack->stack_a[1] == biggest_num(stack->stack_a, stack->size_a))
			apply_rra(stack);
		if (stack->stack_a[2] > stack->stack_a[1])
			apply_sa(stack);	
		return ;
	}
	big = biggest_num(stack->stack_a, stack->size_a);
	small = smallest_num(stack->stack_a, stack->size_a);
	middle = (small + big) / 2;
	if (stack->stack_a[stack->size_a - 1] < middle)
		apply_pb(stack);
	else
		apply_ra(stack);
	sort2(stack);
}NORM*/

void	sort2(t_stack *stack)
{
	int		middle;
	int		big;
	int		small;
	
	while (stack->size_a > 3)
	{
		big = biggest_num(stack->stack_a, stack->size_a);
		small = smallest_num(stack->stack_a, stack->size_a);
		middle = (small + big) / 2;
		if (stack->stack_a[stack->size_a - 1] < middle)
			apply_pb(stack);
		else
			apply_ra(stack);
	}
	if (stack->size_a == 3)
	{
		if (stack->stack_a[2] == biggest_num(stack->stack_a, stack->size_a))
			apply_ra(stack);
		if (stack->stack_a[1] == biggest_num(stack->stack_a, stack->size_a))
			apply_rra(stack);
		if (stack->stack_a[2] > stack->stack_a[1])
			apply_sa(stack);	
	}
}

/*void	sort3(t_stack *stack)
{
	int		middle;
	int		big;
	int		small;
	int		i;


	i = 0;
	big = biggest_num(stack->stack_b, stack->size_b);
	small = smallest_num(stack->stack_b, stack->size_b);
	middle = (small + big) / 2;
	while (biggest_num(stack->stack_b, stack->size_b) > middle)
	{

		if (stack->stack_b[stack->size_b - 1] > middle)
		{
			apply_pa(stack);
			i++;
		}
		else
			apply_rb(stack);
	}
	if (stack->size_b == 3)
	{
		if (stack->stack_b[2] == biggest_num(stack->stack_b, stack->size_b))
			apply_rb(stack);
		if (stack->stack_b[1] == biggest_num(stack->stack_b, stack->size_b))
			apply_rrb(stack);
		if (stack->stack_b[2] > stack->stack_b[1])
			apply_sb(stack);
	}
	while (i-- >= 0)
		apply_pb(stack);
}*/

void	sort3(t_stack *stack)
{
	int		middle;
	int		big;
	int		small;
	int		i;


	i = 0;
	while (stack->size_b > 3)
	{
		big = biggest_num(stack->stack_b, stack->size_b);
		small = smallest_num(stack->stack_b, stack->size_b);
		middle = (small + big) / 2;
		if (stack->stack_b[stack->size_b - 1] > middle)
		{
			apply_pa(stack);
			i++;
		}
		else
			apply_rb(stack);
	}
	if (stack->size_b == 3)
	{
		if (stack->stack_b[2] == biggest_num(stack->stack_b, stack->size_b))
			apply_rb(stack);
		if (stack->stack_b[1] == biggest_num(stack->stack_b, stack->size_b))
			apply_rrb(stack);
		if (stack->stack_b[2] > stack->stack_b[1])
			apply_sb(stack);
	}
	while (i-- >= 0)
		apply_pb(stack);
}

void	sort(t_stack *stack)
{	
	int		middle;
	int		i;

	sort2(stack);
	if (stack->size_a == 3 && !stack->size_b)
		return ;
	middle = stack->size_b / 2;
	while (stack->size_b != 1)
	{
		if (stack->size_b < middle && stack->size_b > 10)
		{
			middle = stack->size_b / 2;
			sort3(stack);
		}
		opt_direction(stack);
		/*print_arr(stack->stack_a, stack->size_a);
		printf("------------------\n");
		print_arr(stack->stack_b, stack->size_b);
		printf("------------------\n");
		printf("------------------\n");*/
	}
	if (check_ra(stack) > check_rra(stack))
		push_rra(stack);
	else
		push_ra(stack);
	align_stack(stack);
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
	/*print_arr(stack->stack_a, stack->size_a);
	printf("------------------\n");
	print_arr(stack->stack_b, stack->size_b);*/
}
