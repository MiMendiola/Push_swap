/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_creator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmendiol <mmendiol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 19:42:17 by mmendiol          #+#    #+#             */
/*   Updated: 2024/03/18 12:15:15 by mmendiol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void	stack_duplicate_arg(t_stack *stack)
{
	t_stack *next_num;
	
	while (stack)
	{
		next_num = stack->next;
		while (next_num != NULL)
		{
			if (stack->num == next_num->num)
				show_error();
			next_num = next_num->next;
		}
		stack = stack->next;
	}
}

void	stack_add_node(t_stack **stack, char **nums, int *index)
{
	int		j;
	long	num;
	t_stack	*node;

	num = 0;
	if (!nums[1])
	{
		num = ft_atol_ps(nums[0]);
		if (num == (long) INT_MAX + 1)
			show_error();
		node = new_node((*index)++, num);
		add_node_back(stack, node);
	}
	else
	{
		j = 0;
		while (nums[j])
		{
			num = ft_atol_ps(nums[j++]);
			if (num == (long) INT_MAX + 1)
				show_error();
			node = new_node((*index)++, num);
			add_node_back(stack, node);
		}
	}
}

void	stack_creator(char *av[], t_stack **stack_a)
{
	int		i;
	int		index;
	char	**numbers;

	i = 0;
	index = 1;
	while (av[++i])
	{
		numbers = ft_split(av[i], ' ');
		stack_add_node(stack_a, numbers, &index);
		stack_duplicate_arg(*stack_a);
		free_matrix(numbers);
	}
	
	// show_lst(stack_a);
}