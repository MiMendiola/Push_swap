/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmendiol <mmendiol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 11:11:32 by mmendiol          #+#    #+#             */
/*   Updated: 2024/03/20 19:47:16 by mmendiol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap_node(t_stack **stack)
{
	t_stack	*aux;
	int		num;
	
	aux = *stack;
	if (*stack)
	{
		num = aux->next->num;
		aux->next->num = aux->num;
		aux->num = num;
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