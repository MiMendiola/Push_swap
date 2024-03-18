/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmendiol <mmendiol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 11:11:32 by mmendiol          #+#    #+#             */
/*   Updated: 2024/03/18 11:13:33 by mmendiol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void	swap_node(t_stack **stack)
{
	t_stack	*aux;
	t_stack	*next;
	
	next = (*stack)->next;
	aux = (*stack)->next->next;
	if ((*stack))
	{
		next->prev = NULL;
		next->next = *stack;
		aux->prev = next->next;
		(*stack)->next = aux;
		(*stack)->prev = next;
		*stack = next;
	}
}

void	swap(t_stack **stack_a, t_stack **stack_b, int move)
{
	if (move == MOVESA)
	{
		swap_node(stack_a);
		ft_putstr(SA);
	}
	else if (move == MOVESB)
	{
		swap_node(stack_b);
		ft_putstr(SB);
	}
	else if (move == MOVESS)
	{
		swap_node(stack_a);
		swap_node(stack_b);
		ft_putstr(SS);
	}
}