/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmendiol <mmendiol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:26:24 by mmendiol          #+#    #+#             */
/*   Updated: 2024/03/14 16:30:24 by mmendiol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

t_stack	*last_node(t_stack *lst)
{
	while (lst && lst->next != NULL)
		lst = lst->next;
	return (lst);
}

t_stack	*new_node(int id, long num)
{
	t_stack	*stack;

	stack = ft_calloc(1, sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->id = id;
	stack->num = num;
	stack->prev = NULL;
	stack->next = NULL;
	return (stack);
}

void	add_node_back(t_stack **stack, t_stack *new)
{
	t_stack	*aux;

	aux = last_node(*stack);
	if (*stack != NULL)
	{
		new->prev = aux;
		new->next = NULL;
		aux->next = new;
	}
	else
		*stack = new;
}

long	ft_atol_ps(char *str)
{
	long	n;
	int		i;
	int		sign;

	n = 0;
	i = 0;
	sign = 1;
	while (str[i])
	{
		if (str[i] == '-' || str[i] == '+')
		{
			if (str[i] == '-')
				sign = -1;
			i++;
		}
		if (!ft_isdigit(str[i]))
			show_error(ERROR);
		n = (n * 10) + (str[i++] - '0');
	}
	n *= sign;
	if (INT_MIN >= n || n >= INT_MAX)
		show_error(ERROR);
	return (n);
}

void	create_stack(t_stack **stack, char **nums, int *index)
{
	int		j;
	long	num;
	t_stack	*node;

	num = 0;
	if (!nums[1])
	{
		num = ft_atol_ps(nums[0]);
		node = new_node((*index)++, num);
		add_node_back(stack, node);
	}
	else
	{
		j = 0;
		while (nums[j])
		{
			num = ft_atol_ps(nums[j++]);
			node = new_node((*index)++, num);
			add_node_back(stack, node);
		}
	}
}