/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 16:33:43 by sbruen            #+#    #+#             */
/*   Updated: 2019/04/15 20:08:00 by sbruen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft/libft.h"

typedef struct	s_stack
{
	int			*stack_a;
	int			*stack_b;
	int			mid;
	size_t		size_a;
	size_t		size_b;
}				t_stack;
