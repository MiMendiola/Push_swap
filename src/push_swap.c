/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmendiol <mmendiol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 11:28:23 by mmendiol          #+#    #+#             */
/*   Updated: 2024/03/22 12:34:18 by mmendiol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

// void	ft_leaks(void)
// {
// 	system("leaks -q push_swap");
// }
// atexit(ft_leaks);

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

void	stack_move_node_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*stack_min;

	stack_set_target_a(*stack_a, *stack_b);
	stack_set_push_cost(*stack_a, *stack_b);
	stack_set_min_cost(*stack_a);
	stack_min = stack_min_cost(*stack_a);
	if (stack_min->median && stack_min->target->median)
		while (*stack_a != stack_min && *stack_b != stack_min->target)
			rotate(stack_a, stack_b, MOVERR);
	else if (!stack_min->median && !stack_min->target->median)
		while (*stack_a != stack_min && *stack_b != stack_min->target)
			reverse_rotate(stack_a, stack_b, MOVERRR);
	if (stack_min->median)
		while (*stack_a != stack_min)
			rotate(stack_a, stack_b, MOVERA);
	else
		while (*stack_a != stack_min)
			reverse_rotate(stack_a, stack_b, MOVERRA);
	if (stack_min->target->median)
		while (*stack_b != stack_min->target)
			rotate(stack_a, stack_b, MOVERB);
	else
		while (*stack_b != stack_min->target)
			reverse_rotate(stack_a, stack_b, MOVERRB);
	push(stack_a, stack_b, MOVEPB);
}

void	stack_move_node_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*target_b;

	if (!stack_b)
		return ;
	stack_set_target_b(*stack_a, *stack_b);
	stack_set_push_cost(*stack_b, *stack_a);
	stack_set_min_cost(*stack_b);
	target_b = *stack_b;
	if (target_b->median && target_b->target->median)
		while (*stack_a != target_b->target && *stack_b != target_b)
			rotate(stack_a, stack_b, MOVERR);
	else if (!target_b->median && !target_b->target->median)
		while (*stack_a != target_b->target && *stack_b != target_b)
			reverse_rotate(stack_a, stack_b, MOVERRR);
	if (target_b->target->median)
		while (*stack_a != target_b->target)
			rotate(stack_a, stack_b, MOVERA);
	else
		while (*stack_a != target_b->target)
			reverse_rotate(stack_a, stack_b, MOVERRA);
	push(stack_a, stack_b, MOVEPA);
}

int	main(int ac, char *av[])
{
	t_stack	**stack_a;
	t_stack	**stack_b;

	stack_a = ft_calloc(1, sizeof(t_stack *));
	stack_b = ft_calloc(1, sizeof(t_stack *));
	if (ac > 1)
	{
		stack_creator(av, stack_a);
		if (!sorted_stack(*stack_a))
		{
			if (stack_len(*stack_a) == 2)
				swap(stack_a, stack_b, MOVESA);
			else if (stack_len(*stack_a) == 3)
				sort_stack_three(stack_a);
			else
				sort_stack(stack_a, stack_b);
		}
		free_list(stack_a);
		free_list(stack_b);
	}
	else
		show_error();
}
