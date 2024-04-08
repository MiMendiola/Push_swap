/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmendiol <mmendiol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 16:23:15 by mmendiol          #+#    #+#             */
/*   Updated: 2024/04/08 20:50:10 by mmendiol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// void	ft_leaks(void)
// {
// 	system("leaks -q checker");
// }
// atexit(ft_leaks);

void	show_error(void)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	execute_rotates(t_stack **stack_a, t_stack **stack_b, char *move)
{
	if (!ft_strncmp(move, RA, 3))
		rotate_node(stack_a);
	else if (!ft_strncmp(move, RB, 3))
		rotate_node(stack_b);
	else if (!ft_strncmp(move, RR, 3))
	{
		rotate_node(stack_a);
		rotate_node(stack_b);
	}
	else if (!ft_strncmp(move, RRA, 4))
		reverse_rotate_node(stack_a);
	else if (!ft_strncmp(move, RRB, 4))
		reverse_rotate_node(stack_b);
	else if (!ft_strncmp(move, RRR, 4))
	{
		reverse_rotate_node(stack_a);
		reverse_rotate_node(stack_b);
	}
}

void	execute_moves(t_stack **stack_a, t_stack **stack_b, char *move)
{
	if (!ft_strncmp(move, PA, 3))
		push_node(stack_a, stack_b);
	else if (!ft_strncmp(move, PB, 3))
		push_node(stack_b, stack_a);
	else if (!ft_strncmp(move, SA, 3))
		swap_node(stack_a);
	else if (!ft_strncmp(move, SB, 3))
		swap_node(stack_b);
	else if (!ft_strncmp(move, SS, 3))
	{
		swap_node(stack_a);
		swap_node(stack_b);
	}
	execute_rotates(stack_a, stack_b, move);
}

int	main(int ac, char *av[])
{
	t_stack	**stack_a;
	t_stack	**stack_b;
	char	*move;

	stack_a = ft_calloc(1, sizeof(t_stack *));
	stack_b = ft_calloc(1, sizeof(t_stack *));
	if (ac <= 1 || av[1][0] == '\0')
		show_error();
	if (ac != 2)
	{
		stack_creator(av, stack_a);
		move = get_next_line(0);
		while (move)
		{
			execute_moves(stack_a, stack_b, move);
			free(move);
			move = get_next_line(0);
		}
	}
	if (stack_sorted(*stack_a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_list(stack_a);
	free_list(stack_b);
}
