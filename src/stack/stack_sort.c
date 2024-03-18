/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmendiol <mmendiol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 19:44:08 by mmendiol          #+#    #+#             */
/*   Updated: 2024/03/18 20:11:48 by mmendiol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_stack_three(t_stack **stack)
{
	t_stack *max;
	
	max = stack_max(*stack);
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

// void	sort_stack(t_stack **stack_a, t_stack **stack_b)
// {
	
// }