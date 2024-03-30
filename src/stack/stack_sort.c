/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmendiol <mmendiol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 19:44:08 by mmendiol          #+#    #+#             */
/*   Updated: 2024/03/30 14:38:41 by mmendiol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	sorted_stack(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->num > stack->next->num)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	sort_stack_three(t_stack **stack)
{
	t_stack	*max;

	max = stack_max(*stack);
	if (!sorted_stack(*stack))
	{
		if (*stack == max)
		{
			rotate_node(stack);
			ft_putstr(RA);
		}
		else if ((*stack)->next == max)
		{
			reverse_rotate_node(stack);
			ft_putstr(RRA);
		}
		if ((*stack)->num > (*stack)->next->num)
		{
			swap_node(stack);
			ft_putstr(SA);
		}
	}
}

void	sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	int	len_stack_a;

	len_stack_a = stack_len(*stack_a);
	if (len_stack_a-- > 3 && !sorted_stack(*stack_a))
		push(stack_a, stack_b, MOVEPB);
	if (len_stack_a-- > 3 && !sorted_stack(*stack_a))
		push(stack_a, stack_b, MOVEPB);
	sort_push_b(stack_a, stack_b);
	sort_stack_three(stack_a);
	sort_push_a(stack_a, stack_b);
	stack_above_half(*stack_a);
	sort_end(stack_a, stack_b);
}

void	sort_end(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*min_node;

	min_node = stack_min(*stack_a);
	while (*stack_a != min_node)
	{
		if (min_node->median)
			rotate(stack_a, stack_b, MOVERA);
		else
			reverse_rotate(stack_a, stack_b, MOVERRA);
	}
}
