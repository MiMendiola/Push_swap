/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmendiol <mmendiol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 16:51:43 by mmendiol          #+#    #+#             */
/*   Updated: 2024/03/18 20:11:33 by mmendiol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	reverse_rotate_node(t_stack **stack)
{
	t_stack	*last;
	t_stack	*prev_last;

	prev_last = last_node(*stack)->prev;
	last = last_node(*stack);
	if (*stack)
	{
		last->prev = NULL;
		last->next = *stack;
		last->next->prev = last;
		prev_last->next = NULL;
		*stack = last;
	}
}

void	reverse_rotate(t_stack **stack_a, t_stack **stack_b, int move)
{
	if (move == MOVERRA)
	{
		reverse_rotate_node(stack_a);
		ft_putstr(RRA);
	}
	else if (move == MOVERRB)
	{
		reverse_rotate_node(stack_b);
		ft_putstr(RRB);
	}
	else if (move == MOVERRR)
	{
		reverse_rotate_node(stack_a);
		reverse_rotate_node(stack_b);
		ft_putstr(RRR);
	}
	stack_index(*stack_a);
	stack_index(*stack_b);
}
