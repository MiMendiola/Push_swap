/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmendiol <mmendiol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 11:28:23 by mmendiol          #+#    #+#             */
/*   Updated: 2024/03/12 20:37:00 by mmendiol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_ext/src/ft_bzero.c"
#include "../libft_ext/src/ft_calloc.c"
#include "../libft_ext/src/ft_isdigit.c"
#include "../libft_ext/src/ft_memset.c"
#include "../libft_ext/src/ft_putstr_fd.c"
#include "../libft_ext/src/ft_split.c"
#include "../libft_ext/src/ft_strdup.c"
#include "../libft_ext/src/ft_strlen.c"
#include "../libft_ext/src/ft_substr.c"
#include "../libft_ext/additional/free_matrix.c"
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

void	free_lst(t_lst *stack)
{
	t_lst	*aux;

	while (stack)
	{
		aux = stack->next;
		free(stack);
		stack = aux;
	}
}




















t_lst	*new_node(int id, long num)
{
	t_lst	*list;

	list = malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	list->id = id;
	list->num = num;
	list->prev = NULL;
	list->next = NULL;
	return (list);
}

void	add_node_back(t_lst **stack, t_lst *new)
{
	t_lst	*aux;

	aux = *stack;
	if (*stack != NULL)
	{
		*stack = new;
		return; 
	}
	while (aux->next != NULL)
		aux = aux->next;
	aux->next = new;
	new->prev = aux;
	new->next = NULL;
}


void	show_lst(t_lst **stack)
{
	t_lst *aux;
	
	aux = *stack;
	while (aux != NULL)
	{
		printf("num node[%d] --> [%ld]\n", aux->id ,aux->num);
		printf("node --> [%p]\n\n", aux);
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
	sign = 0;
	while (str[i])
	{
		if (str[i] == '-' || str[i] == '+')
		{
			if (str[i] == '-')
				sign++;
			i++;
		}
		if (!ft_isdigit(str[i]))
			show_error(ERROR_ARGUMENT_NON_DIGIT);
		n = (n * 10) + (str[i++] - '0');
	}
	if (sign)
		n *= -1;
	return (n);
}

void	check_arguments(char *av[], t_lst **stack_a)
{
	int		i;
	char	**numbers;
	long	num;

	i = 0;
	num = 0;
	while (av[++i])
	{
		numbers = ft_split(av[i], ' ');
		if (!numbers[1])
		{
			num = ft_atol_ps(av[i]);
			if (INT_MIN >= num || num <= INT_MAX)
			{
				printf("list num node[] --> [%ld]\n", num);
				add_node_back(stack_a, new_node(0, num));
				
			
				
				// printf("INDEX: %d", stack_a->id);
				// printf("NUMERO STACK: %ld\n\n", stack_a->num);
				// printf("AQUI\n");
				// printf("DIRECCION DEL STACK NULL: %p\n", stack_a);
				// ft_lstadd_back((t_list **)stack_a, ft_lstnew(stack_a->content));
				// printf("NUMBER STRUCT: %s\n\n", stack_a);
				
			}
			else
				show_error(ERROR_ARGUMENT_NON_VALID);
		}
		else
		{
			// FUNCION PARA GESTIONAR UN STRING DE NUMEROS
			
		}
		// show_lst(stack_a);
		free_matrix(numbers);
	}
}

int	main(int ac, char *av[])
{
	t_lst *stack_a;
	t_lst *stack_b;

	// stack_a = ft_calloc(1, sizeof(t_lst));
	// stack_b = ft_calloc(1, sizeof(t_lst));
	stack_a = NULL;
	stack_b = NULL;

	atexit(ft_leaks);

	// ac = 15;
	// av[0] = "7";
	// av[1] = "87";
	// av[2] = "6";
	// av[3] = "68";
	// av[4] = "45";
	// av[5] = "63";
	// av[6] = "84";
	// av[7] = "36";
	// av[8] = "54";
	// av[9] = "65";
	// av[10] = "77";
	// av[11] = "95";
	// av[12] = "23";
	// av[13] = "98";
	// av[14] = "83";
	// av[15] = "59";
	// av[16] = "80";
	// av[17] = "71";
	// av[18] = "48";
	// av[19] = "11";
	// av[20] = "25";
	if (ac > 1)
	{
		check_arguments(av, &stack_a);
        
		free_lst(stack_a);
		// free_lst(stack_b);
	}
	else
		show_error(ERROR_ARGUMENTS);
}
