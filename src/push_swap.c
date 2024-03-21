/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmendiol <mmendiol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 11:28:23 by mmendiol          #+#    #+#             */
/*   Updated: 2024/03/21 14:18:55 by mmendiol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/additional/free_matrix.c"
#include "../libft/lib/ft_bzero.c"
#include "../libft/lib/ft_calloc.c"
#include "../libft/lib/ft_isdigit.c"
#include "../libft/lib/ft_memset.c"
#include "../libft/lib/ft_putstr_fd.c"
#include "../libft/lib/ft_split.c"
#include "../libft/lib/ft_strdup.c"
#include "../libft/lib/ft_strlen.c"
#include "../libft/lib/ft_substr.c"

// #include "./stack_utils.c"
// #include "./shows.c"
// #include "./stack_creator.c"

#include "./includes/push_swap.h"

void	ft_leaks(void)
{
	system("leaks -q push_swap");
}

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

	stack_min = stack_min_cost(*stack_a);
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
	if (stack_min->median && stack_min->target->median)
		while (*stack_a != stack_min && *stack_b != stack_min->target)
			rotate(stack_a, stack_b, MOVERR);
	else
		while (*stack_a != stack_min && *stack_b != stack_min->target)
			reverse_rotate(stack_a, stack_b, MOVERRR);
	push(stack_a, stack_b, MOVEPB);
}

void	stack_move_node_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*target_b;

	if (!stack_b || !(*stack_b))
			return;
	target_b = (*stack_b)->target;
	if (!(target_b->median))
		while (*stack_a != target_b)
			reverse_rotate(stack_a, stack_b, MOVERRA);
	else
		while (*stack_a != target_b)
			rotate(stack_a, stack_b, MOVERA);
	push(stack_a, stack_b, MOVEPA);
}

int	main(int ac, char *av[])
{
	t_stack	**stack_a;
	t_stack	**stack_b;

	stack_a = ft_calloc(1, sizeof(t_stack *));
	stack_b = ft_calloc(1, sizeof(t_stack *));
	// atexit(ft_leaks);
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
		// show_lst(stack_a);
		free_list(stack_a);
		free_list(stack_b);
	}
	else
		show_error();
}
