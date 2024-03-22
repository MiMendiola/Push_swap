/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmendiol <mmendiol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 11:20:06 by mmendiol          #+#    #+#             */
/*   Updated: 2024/03/20 12:50:34 by mmendiol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate_node(t_stack **stack)
{
	t_stack	*next;
	t_stack	*last;
	
	next = (*stack)->next;
	last = last_node(*stack);
	if (*stack)
	{
		next->prev = NULL;
		last->next = *stack;
		(*stack)->next = NULL;
		(*stack)->prev = last;
		*stack = next;
	}
}

void	rotate(t_stack **stack_a, t_stack **stack_b, int move)
{
	if (move == MOVERA)
	{
		rotate_node(stack_a);
		ft_putstr(RA);
	}
	else if (move == MOVERB)
	{
		rotate_node(stack_b);
		ft_putstr(RB);
	}
	else if (move == MOVERR)
	{
		rotate_node(stack_a);
		rotate_node(stack_b);
		ft_putstr(RR);
	}
	stack_index(*stack_a);
	stack_index(*stack_b);
}
