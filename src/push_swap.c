/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmendiol <mmendiol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 11:28:23 by mmendiol          #+#    #+#             */
/*   Updated: 2024/03/13 19:54:24 by mmendiol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/lib/ft_bzero.c"
#include "../libft/lib/ft_calloc.c"
#include "../libft/lib/ft_isdigit.c"
#include "../libft/lib/ft_memset.c"
#include "../libft/lib/ft_putstr_fd.c"
#include "../libft/lib/ft_split.c"
#include "../libft/lib/ft_strdup.c"
#include "../libft/lib/ft_strlen.c"
#include "../libft/lib/ft_substr.c"
#include "../libft/additional/free_matrix.c"
#include "./includes/push_swap.h"

void	ft_leaks(void)
{
	system("leaks -q push_swap");
}

void	show_error(char *str)
{
	ft_putstr_fd(RED "ERROR: ", STDERR_FILENO);
	ft_putstr_fd(str, STDERR_FILENO);
	ft_putstr_fd(CLEAR, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	free_lst(t_stack **stack)
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

















t_stack	*lst_last(t_stack *lst)
{
	while (lst && lst->next != NULL)
		lst = lst->next;
	return (lst);
}


t_stack	*new_node(int id, long num)
{
	t_stack	*list;

	list = ft_calloc(1, sizeof(t_stack));
	if (!list)
		return (NULL);
	list->id = id;
	list->num = num;
	list->prev = NULL;
	list->next = NULL;
	return (list);
}

void	add_node_back(t_stack **stack, t_stack *new)
{
	t_stack	*aux;

	aux = lst_last(*stack);
	if (*stack != NULL)
	{
		printf("ENTRA\n");
		new->prev = aux;
		new->next = NULL;
		aux->next = new;
	}
	else
		*stack = new;
}


void	show_lst(t_stack **stack)
{
	t_stack	*aux;

	aux = *stack;
	while (aux != NULL)
	{
		if (aux->prev)
			printf("num prev[%d] --> [%ld]\n", aux->prev->id ,aux->prev->num);
		printf("num node[%d] --> [%ld]\n", aux->id ,aux->num);
		printf("node stack--> [%p]\n", *stack);
		printf("node prev--> [%p]\n", aux->prev);
		printf("node next--> [%p]\n\n", aux->next);
		aux = aux->next;
	}
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
			show_error(ERROR_ARGUMENT_NON_DIGIT);
		n = (n * 10) + (str[i++] - '0');
	}
	n *= sign;
	if (INT_MIN >= n || n >= INT_MAX)
		show_error(ERROR_ARGUMENT_NON_VALID);
	return (n);
}

void	check_arguments(char *av[], t_stack **stack_a)
{
	int		i;
	int		j;
	int		index;
	char	**numbers;
	long	num;

	i = 0;
	num = 0;
	index = 1;
	while (av[++i])
	{
		numbers = ft_split(av[i], ' ');
		if (!numbers[1])
			add_node_back(stack_a, new_node(index++, ft_atol_ps(av[i])));
		else
		{
			j = 0;
			while(numbers[j])
			{
				num = ft_atol_ps(numbers[j]);
				add_node_back(stack_a, new_node(index++, num));
				j++;
			}
		}
		free_matrix(numbers);
	}
	show_lst(stack_a);
}

int	main(int ac, char *av[])
{
	t_stack **stack_a;
	t_stack **stack_b;

	stack_a = ft_calloc(1, sizeof(t_stack *));
	stack_b = ft_calloc(1, sizeof(t_stack *));

	atexit(ft_leaks);

	// ac = 15;
	// av[1] = "87";
	// av[2] = "6";
 	// av[3] = "68";
	// av[4] = "45";
/*	av[5] = "63";
	av[6] = "84";
	av[7] = "36";
	av[8] = "54";
	av[9] = "65";
	av[10] = "77";
	av[11] = "95";
	av[12] = "23";
	av[13] = "98";
	av[14] = "83";
	av[15] = "59";
	av[16] = "80";
	av[17] = "71";
	av[18] = "48";
	av[19] = "11";
	av[20] = "25"; */
	if (ac > 1)
	{
		check_arguments(av, stack_a);
        
		printf("node stack--> [%p]\n", stack_a);
		free_lst(stack_a);
		free_lst(stack_b);
	}
	else
		show_error(ERROR_ARGUMENTS);
}
