/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmendiol <mmendiol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 11:28:23 by mmendiol          #+#    #+#             */
/*   Updated: 2024/03/14 17:01:00 by mmendiol         ###   ########.fr       */
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
		free((*stack));
		*stack = aux;
	}
	free(stack);
}

void	check_duplicates(t_stack **stack)
{
	int i;
	t_stack *next_num;
	
	i = 0;
	if (*stack != NULL)
	{
		next_num = (*stack)->next;
		while (next_num != NULL)
		{
			if ((*stack)->num == next_num->num)
				show_error("CAGUE");
			next_num = next_num->next;
		}
	}
}

void	check_arguments(char *av[], t_stack **stack_a)
{
	int		i;
	int		index;
	char	**numbers;

	i = 0;
	index = 1;
	while (av[++i])
	{
		numbers = ft_split(av[i], ' ');
		create_stack(stack_a, numbers, &index);
		check_duplicates(stack_a);
		free_matrix(numbers);
	}
	show_lst(stack_a);
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
		check_arguments(av, stack_a);
		printf("node stack--> [%p]\n", stack_a);
		free_list(stack_a);
		free_list(stack_b);
	}
	else
		show_error(ERROR);
}
