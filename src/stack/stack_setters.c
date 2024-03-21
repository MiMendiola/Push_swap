/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_setters.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmendiol <mmendiol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 11:28:23 by mmendiol          #+#    #+#             */
/*   Updated: 2024/03/20 19:45:41 by mmendiol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	stack_set_min_cost(t_stack *stack)
{
	t_stack	*min;
	long	min_cost;

	min_cost = INT_MAX;
	while (stack)
	{
		if (stack->cost < min_cost)
		{
			min_cost = stack->cost;
			min = stack;
		}
		stack = stack->next;
	}
	min->min_cost = true;
}

void	stack_set_above_half(t_stack *stack)
{
	int	half;
	int	median;

	half = stack_len(stack);
	median = half / 2;
	if (half % 2)
		median++;
	while (stack)
	{
		if (stack->id <= median)
			stack->median = true;
		else
			stack->median = false;
		stack = stack->next;
	}
}

void	stack_set_push_cost(t_stack *stack_main, t_stack *stack_node)
{
	int	len_stack_main;
	int	len_stack_node;

	len_stack_main = stack_len(stack_main);
	len_stack_node = stack_len(stack_node);
	while (stack_main)
	{
		stack_main->cost = stack_main->id;
		if (!stack_main->median)
			stack_main->cost += len_stack_main - stack_main->id;
		if (stack_main->target->median)
			stack_main->cost += stack_main->target->id;
		else
			stack_main->cost += len_stack_node - stack_main->target->id;
		stack_main = stack_main->next;
	}
}

void	stack_set_target_a(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*target_stack;
	long	target_num;

	while (stack_a)
	{
		target_num = LONG_MIN;
		target_stack = stack_b;
		while (target_stack)
		{
			if (target_stack->num < stack_a->num
				&& target_stack->num > target_num)
			{
				target_num = target_stack->num;
				stack_a->target = target_stack;
			}
			target_stack = target_stack->next;
		}
		if (target_num == LONG_MIN)
			stack_a->target = stack_max(stack_b);
		stack_a = stack_a->next;
	}
}

void	stack_set_target_b(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*target_stack;
	long	target_num;

	while (stack_b)
	{
		target_num = LONG_MAX;
		target_stack = stack_a;
		while (target_stack)
		{
			if (target_stack->num > stack_b->num
				&& target_stack->num < target_num)
			{
				target_num = target_stack->num;
				stack_b->target = target_stack;
			}
			target_stack = target_stack->next;
		}
		if (target_num == LONG_MAX)
			stack_b->target = stack_min(stack_a);
		stack_b = stack_b->next;
	}
}
