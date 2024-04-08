/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_setters.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: mmendiol <mmendiol@student.42.fr>          +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2024/03/08 11:28:23 by mmendiol          #+#    #+#             */
/*   Updated: 2024/03/20 19:45:41 by mmendiol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*stack_set_min_cost(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*node_a;
	t_stack	*min_cost;
	int		count;
	int		min_moves;

	node_a = *stack_a;
	min_moves = INT_MAX;
	while (node_a)
	{
		stack_set_push_cost(*stack_a, *stack_b, node_a, &count);
		if (count == 0)
			return (node_a);
		if (count < min_moves)
		{
			min_moves = count;
			min_cost = node_a;
		}
		node_a = node_a->next;
	}
	return (min_cost);
}

void	stack_set_push_cost(t_stack *stack_a, t_stack *stack_b, t_stack *node_a,
		int *count)
{
	int	less_half;

	stack_set_target_a(node_a, stack_b);
	less_half = stack_len(stack_b) - node_a->target->id;
	if (node_a->median)
		*count = node_a->id;
	else
		*count = stack_len(stack_a) - node_a->id;
	if (node_a->median && node_a->target->median)
	{
		if (node_a->target->id > *count)
			*count += (node_a->target->id - *count);
	}
	else if (!node_a->median && !node_a->target->median)
	{
		if (*count < less_half)
			*count += (less_half - *count);
	}
	else if (node_a->target->median)
		*count += node_a->target->id;
	else
		*count += less_half;
}

void	stack_set_target_a(t_stack *main_stack, t_stack *stack_b)
{
	t_stack	*target_stack;
	long	target_num;

	target_num = LONG_MIN;
	target_stack = stack_b;
	while (target_stack)
	{
		if (target_stack->num < main_stack->num
			&& target_stack->num > target_num)
		{
			target_num = target_stack->num;
			main_stack->target = target_stack;
		}
		target_stack = target_stack->next;
	}
	if (target_num == LONG_MIN)
		main_stack->target = stack_max(stack_b);
}

t_stack	*stack_set_target_b(t_stack *node, t_stack *stack_a)
{
	t_stack	*target_stack;
	long	target_num;

	target_num = LONG_MAX;
	target_stack = stack_a;
	while (target_stack)
	{
		if (target_stack->num > node->num && target_stack->num < target_num)
		{
			target_num = target_stack->num;
			node->target = target_stack;
		}
		target_stack = target_stack->next;
	}
	if (target_num == LONG_MAX)
		node->target = stack_min(stack_a);
	return (node->target);
}

void	stack_set_top_node(t_stack **stack_a, t_stack **stack_b,
		t_stack *min_cost)
{
	if (min_cost->median && min_cost->target->median)
		while (*stack_a != min_cost && *stack_b != min_cost->target)
			rotate(stack_a, stack_b, MOVERR);
	else if (!min_cost->median && !min_cost->target->median)
		while (*stack_a != min_cost && *stack_b != min_cost->target)
			reverse_rotate(stack_a, stack_b, MOVERRR);
	if (min_cost->median)
		while (*stack_a != min_cost)
			rotate(stack_a, stack_b, MOVERA);
	else
		while (*stack_a != min_cost)
			reverse_rotate(stack_a, stack_b, MOVERRA);
	if (min_cost->target->median)
		while (*stack_b != min_cost->target)
			rotate(stack_a, stack_b, MOVERB);
	else
		while (*stack_b != min_cost->target)
			reverse_rotate(stack_a, stack_b, MOVERRB);
}
