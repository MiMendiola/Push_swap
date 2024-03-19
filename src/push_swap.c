/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmendiol <mmendiol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 11:28:23 by mmendiol          #+#    #+#             */
/*   Updated: 2024/03/19 19:46:45 by mmendiol         ###   ########.fr       */
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

void	stack_min_cost(t_stack *stack)
{
	t_stack *min;
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

void	stack_set_target(t_stack *stack_a, t_stack *stack_b)
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

void	stack_push_cost(t_stack *stack_a, t_stack *stack_b)
{
	int len_stack_a;
	int len_stack_b;

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
		stack_set_target(*stack_a, *stack_b);
		stack_push_cost(*stack_a, *stack_b);
		stack_min_cost(*stack_a);
	}
}

int	main(int ac, char *av[])
{
	t_stack	**stack_a;
	t_stack	**stack_b;

	stack_a = ft_calloc(1, sizeof(t_stack *));
	stack_b = ft_calloc(1, sizeof(t_stack *));
	atexit(ft_leaks);
	if (ac > 1)
	{
		stack_creator(av, stack_a);
		show_lst(stack_a);
		show_lst(stack_b);
		if (!stack_sorted(*stack_a))
		{
			if (stack_len(*stack_a) == 2)
				swap(stack_a, stack_b, MOVESA);
			else if (stack_len(*stack_a) == 3)
				sort_stack_three(stack_a);
			else
				sort_stack(stack_a, stack_b);
		}
		printf("\n\nStack A ORDENADO:\n\n");
		show_lst(stack_a);
		// printf("Stack b \n");
		// show_lst(stack_b);
		free_list(stack_a);
		free_list(stack_b);
	}
	else
		show_error();
}
