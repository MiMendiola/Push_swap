/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_properties.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmendiol <mmendiol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 19:46:58 by mmendiol          #+#    #+#             */
/*   Updated: 2024/03/18 20:11:45 by mmendiol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_list(t_stack **stack)
{
	t_stack	*aux;

	while (*stack)
	{
		aux = (*stack)->next;
		free(*stack);
		*stack = aux;
	}
	free(stack);
}

int	stack_len(t_stack *stack)
{
	int counter;

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

void	stack_index(t_stack *stack)
{
	int	i;

	i = 1;
	while(stack)
	{
		stack->id = i++;
		stack = stack->next;
	}
}

t_stack	*stack_max(t_stack *stack)
{
	t_stack *max;
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
