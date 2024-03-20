/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmendiol <mmendiol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 11:28:23 by mmendiol          #+#    #+#             */
/*   Updated: 2024/03/20 19:45:41 by mmendiol         ###   ########.fr       */
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

void	stack_set_min_cost(t_stack *stack)
{
	t_stack	*min;
	long	min_cost;

	min_cost = INT_MAX;
	while (stack)
	{
		if (stack->cost < min_cost)
		{
			min_cost = stack->cost;
			min = stack;
		}
		stack = stack->next;
	}
	min->min_cost = true;
}

void	stack_above_half(t_stack *stack)
{
	int	half;
	int	median;

	half = stack_len(stack);
	median = half / 2;
	if (half % 2)
		median++;
	while (stack)
	{
		if (stack->id <= median)
			stack->median = true;
		else
			stack->median = false;
		stack = stack->next;
	}
}

void	stack_set_target_a(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*target_stack;
	long	target_num;

	while (stack_a)
	{
		target_num = LONG_MIN;
		target_stack = stack_b;
		while (target_stack)
		{
			if (target_stack->num < stack_a->num
				&& target_stack->num > target_num)
			{
				target_num = target_stack->num;
				stack_a->target = target_stack;
			}
			target_stack = target_stack->next;
		}
		if (target_num == LONG_MIN)
			stack_a->target = stack_max(stack_b);
		stack_a = stack_a->next;
	}
}

void	stack_set_target_b(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*target_stack;
	long	target_num;

	while (stack_b)
	{
		target_num = LONG_MAX;
		target_stack = stack_a;
		while (target_stack)
		{
			if (target_stack->num > stack_b->num
				&& target_stack->num < target_num)
			{
				target_num = target_stack->num;
				stack_b->target = target_stack;
			}
			target_stack = target_stack->next;
		}
		if (target_num == LONG_MAX)
			stack_b->target = stack_min(stack_a);
		stack_b = stack_b->next;
	}
}

void	stack_push_cost(t_stack *stack_a, t_stack *stack_b)
{
	int	len_stack_a;
	int	len_stack_b;

	len_stack_a = stack_len(stack_a);
	len_stack_b = stack_len(stack_b);
	while (stack_a)
	{
		stack_a->cost = stack_a->id;
		if (!stack_a->median)
			stack_a->cost += len_stack_a - stack_a->id;
		if (stack_a->target->median)
			stack_a->cost += stack_a->target->id;
		else
			stack_a->cost += len_stack_b - stack_a->target->id;
		stack_a = stack_a->next;
	}
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
	if (stack_min->median && stack_min->target->median)
		while (*stack_a != stack_min && *stack_b != stack_min->target)
			rotate(stack_a, stack_b, MOVERR);
	else
		while (*stack_a != stack_min && *stack_b != stack_min->target)
			reverse_rotate(stack_a, stack_b, MOVERRR);
	if (stack_min->target->median)
		while (*stack_b != stack_min->target)
			rotate(stack_a, stack_b, MOVERB);
	else
		while (*stack_b != stack_min->target)
			reverse_rotate(stack_a, stack_b, MOVERRB);
	push(stack_a, stack_b, MOVEPB);
	stack_index(*stack_a);
	stack_index(*stack_b);
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

void	stack_final_sort(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *min_node;

	min_node = stack_min(*stack_a);
	while (*stack_a != min_node)
	{
		if (min_node->median)
			rotate(stack_a, stack_b, MOVERA);
		else
			reverse_rotate(stack_a, stack_b, MOVERRA);
	}
}

void	sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	int	len_stack;

	len_stack = stack_len(*stack_a);
	if (len_stack-- > 3 && !stack_sorted(*stack_a))
		push(stack_a, stack_b, MOVEPB);
	if (len_stack-- > 3 && !stack_sorted(*stack_a))
		push(stack_a, stack_b, MOVEPB);
	while (len_stack-- > 3 && !stack_sorted(*stack_a))
	{
		stack_above_half(*stack_a);
		stack_above_half(*stack_b);
		stack_set_target_a(*stack_a, *stack_b);
		stack_push_cost(*stack_a, *stack_b);
		stack_set_min_cost(*stack_a);
		stack_move_node_a(stack_a, stack_b);
	}
	sort_stack_three(stack_a);
	while (*stack_b)
	{
		stack_above_half(*stack_a);
		stack_set_target_b(*stack_a, *stack_b);
		stack_set_min_cost(*stack_b);
		stack_move_node_b(stack_a, stack_b);
	}
	stack_final_sort(stack_a, stack_b);
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
		if (!stack_sorted(*stack_a))
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
