/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmendiol <mmendiol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 17:14:40 by mmendiol          #+#    #+#             */
/*   Updated: 2024/03/18 17:00:21 by mmendiol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void	push_move(t_stack **stack, t_stack **node)
{
	t_stack *aux;

	aux = *node;
	*node = (*node)->next;
	if (!(*stack))
	{
		*stack = aux;
		(*stack)->next = NULL;
		(*node)->prev = NULL;
	}
	else
	{
		aux->next = *stack;
		aux->prev = NULL;
		(*node)->prev = NULL;
		(*stack)->prev = aux;
		*stack = aux;
	}
}

void	push(t_stack **stack_a, t_stack **stack_b, int move)
{
	if (move == MOVEPA)
	{
		push_move(stack_a, stack_b);
		ft_putstr(PA);
	}
	else if (move == MOVEPB)
	{
		push_move(stack_b, stack_a);
		ft_putstr(PB);
	}
}