/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmendiol <mmendiol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 11:28:23 by mmendiol          #+#    #+#             */
/*   Updated: 2024/03/30 15:44:44 by mmendiol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

// void	ft_leaks(void)
// {
// 	system("leaks -q push_swap");
// }
// atexit(ft_leaks);

void	sort_push_a(t_stack **stack_a, t_stack **stack_b)
{
	int		proxy_a;
	int		len_stack_b;
	t_stack	*target_b;

	len_stack_b = stack_len(*stack_b);
	while (len_stack_b > 0)
	{
		stack_above_half(*stack_a);
		stack_above_half(*stack_b);
		target_b = stack_set_target_b(*stack_b, *stack_a);
		proxy_a = stack_len(*stack_a) / 2;
		while (*stack_a != target_b)
		{
			if (target_b->median)
				rotate(stack_a, stack_b, MOVERA);
			else
				reverse_rotate(stack_a, stack_b, MOVERRA);
		}
		push(stack_a, stack_b, MOVEPA);
		len_stack_b--;
	}
}

void	sort_push_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*min_cost;
	int		len_stack_a;

	len_stack_a = stack_len(*stack_a);
	while (len_stack_a-- > 3 && !sorted_stack(*stack_a))
	{
		stack_above_half(*stack_a);
		stack_above_half(*stack_b);
		min_cost = stack_set_min_cost(stack_a, stack_b);
		stack_set_top_node(stack_a, stack_b, min_cost);
		push(stack_a, stack_b, MOVEPB);
	}
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
