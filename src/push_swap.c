/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmendiol <mmendiol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 11:28:23 by mmendiol          #+#    #+#             */
/*   Updated: 2024/03/18 16:57:11 by mmendiol         ###   ########.fr       */
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

		push_to(stack_a, stack_b, MOVEPB);
		push_to(stack_a, stack_b, MOVEPB);
		push_to(stack_a, stack_b, MOVEPB);

		show_lst(stack_a);
		show_lst(stack_b);

		printf("node stack--> [%p]\n", stack_a);
		free_list(stack_a);
		free_list(stack_b);
	}
	else
		show_error();
}
