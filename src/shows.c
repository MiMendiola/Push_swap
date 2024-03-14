/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shows.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmendiol <mmendiol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:23:15 by mmendiol          #+#    #+#             */
/*   Updated: 2024/03/14 20:25:09 by mmendiol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void	show_error(void)
{
	ft_putstr_fd(RED "Error\n", STDERR_FILENO);
	ft_putstr_fd(CLEAR, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	show_lst(t_stack **stack)
{
	t_stack	*aux;

	aux = *stack;
	while (aux != NULL)
	{
		if (aux->prev)
			printf("num prev[%d] --> [%ld]\n", aux->prev->id, aux->prev->num);
		printf("num node[%d] --> [%ld]\n", aux->id, aux->num);
		printf("node stack--> [%p]\n", *stack);
		printf("node prev--> [%p]\n", aux->prev);
		printf("node next--> [%p]\n\n", aux->next);
		aux = aux->next;
	}
}