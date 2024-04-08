/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_properties.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmendiol <mmendiol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 19:46:58 by mmendiol          #+#    #+#             */
/*   Updated: 2024/04/08 12:27:43 by mmendiol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*stack_max(t_stack *stack)
{
	t_stack	*max;
	long	num_max;

	num_max = INT_MIN;
	while (stack)
	{
		if (stack->num > num_max)
		{
			max = stack;
			num_max = stack->num;
		}
		stack = stack->next;
	}
	return (max);
}

t_stack	*stack_min(t_stack *stack)
{
	t_stack	*min;
	long	num_min;

	num_min = INT_MAX;
	while (stack)
	{
		if (stack->num < num_min)
		{
			min = stack;
			num_min = stack->num;
		}
		stack = stack->next;
	}
	return (min);
}

int	stack_len(t_stack *stack)
{
	int	counter;

	counter = 0;
	while (stack)
	{
		counter++;
		stack = stack->next;
	}
	return (counter);
}

int	stack_sorted(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->num > stack->next->num)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	stack_above_half(t_stack *stack)
{
	int	half;
	int	median;
	int	i;

	i = 1;
	half = stack_len(stack);
	median = half / 2;
	if (half % 2)
		median++;
	while (stack)
	{
		stack->id = i++;
		if (stack->id <= median)
			stack->median = true;
		else
			stack->median = false;
		stack = stack->next;
	}
}
