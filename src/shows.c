/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shows.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmendiol <mmendiol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:23:15 by mmendiol          #+#    #+#             */
/*   Updated: 2024/03/22 12:21:12 by mmendiol         ###   ########.fr       */
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
		printf("STACK NODE	->	%p\n", *stack);
		if (aux->prev)
			printf("PREV NUM[%d]	->	%ld\n", aux->prev->id, aux->prev->num);
		printf("NUM NODE[%d]	->	%ld\n", aux->id, aux->num);
		printf("COST NODE	->	%d\n", (*stack)->cost);
		printf("ABOVE MEDIAN	->	%d\n", aux->median);
		printf("MIN COST	->	%d\n", aux->min_cost);
		printf("TARGET NODE	->	%p\n", aux->target);
		printf("PREV NODE	->	%p\n", aux->prev);
		printf("NEXT NODE	->	%p\n\n\n", aux->next);
		aux = aux->next;
	}
}
