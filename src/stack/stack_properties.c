/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_properties.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmendiol <mmendiol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 19:46:58 by mmendiol          #+#    #+#             */
/*   Updated: 2024/03/22 12:18:31 by mmendiol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	stack_index(t_stack *stack)
{
	int	i;

	i = 1;
	while (stack)
	{
		stack->id = i++;
		stack = stack->next;
	}
}

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

t_stack	*stack_min_cost(t_stack *stack)
{
	t_stack	*min;

	while (stack)
	{
		if (stack->min_cost == true)
			min = stack;
		stack = stack->next;
	}
	return (min);
}
