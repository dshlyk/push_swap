/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fill_args.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 09:25:51 by sbruen            #+#    #+#             */
/*   Updated: 2019/05/04 16:24:26 by sbruen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
				ft_putstr_fd("Error\n", 2);
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
	while (i < stack->sz_a)
	{
		while (j < stack->sz_a)
		{
			if (stack->st_a[i] == stack->st_a[j])
			{
				ft_putstr_fd("Error\n", 2);
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
		stack->st_a[size] = ft_atoi(*str);
		size--;
		str++;
	}
	check_doubles(stack);
}

void	split_input(char **argv, t_stack *stack)
{
	char	**str;
	int		i;

	i = ft_words_num(argv[1], ' ');
	str = ft_strsplit(argv[1], ' ');
	fill_stack(str, stack->sz_a - 1, stack);
	while (i >= 0)
	{
		free(str[i]);
		i--;
	}
	free(str);
	str = NULL;
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
