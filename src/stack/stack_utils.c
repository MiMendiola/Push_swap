/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmendiol <mmendiol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:26:24 by mmendiol          #+#    #+#             */
/*   Updated: 2024/03/22 12:18:09 by mmendiol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

int	stack_len(t_stack *stack)
{
	int	counter;

	counter = 0;
	while (stack)
	{
		counter++;
		stack = stack->next;
	}
	return (counter);
}

long	ft_atol_ps(char *str)
{
	long	n;
	int		i;
	long	sign;

	n = 0;
	i = 0;
	sign = 1;
	while (str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			sign *= -1;
	}
	if (!ft_isdigit(str[i]))
		show_error();
	while (ft_isdigit(str[i]))
		n = (str[i++] - '0') + (n * 10);
	if (!ft_isdigit(str[i]) && str[i])
		show_error();
	n *= sign;
	if (n > INT_MAX || n < INT_MIN)
		show_error();
	return (n);
}
