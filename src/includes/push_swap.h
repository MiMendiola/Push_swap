/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmendiol <mmendiol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 11:28:18 by mmendiol          #+#    #+#             */
/*   Updated: 2024/03/18 16:52:50 by mmendiol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../../libft/includes/libft.h"
# include "./defines.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack	t_stack;

struct					s_stack
{
	int					id;
	long				num;
	t_stack				*prev;
	t_stack				*next;
};

/* =============== STACK CREATOR =============== */
void					stack_duplicate_arg(t_stack *stack);
void					stack_add_node(t_stack **stack, char **nums,
							int *index);
void					stack_creator(char *av[], t_stack **stack_a);

/* ================ STACK UTILS ================ */
void					free_list(t_stack **stack);
long					ft_atol_ps(char *str);
void					add_node_back(t_stack **stack, t_stack *new);
t_stack					*last_node(t_stack *lst);
t_stack					*new_node(int id, long num);

/* =============== PUSH FUNTIONS =============== */
void					push_to(t_stack **stack_a, t_stack **stack_b, int move);
void					push_node(t_stack **stack, t_stack **node);

/* =============== SWAP FUNTIONS =============== */
void					swap(t_stack **stack_a, t_stack **stack_b, int move);
void					swap_node(t_stack **stack);

/* ============== REVERSE FUNTIONS ============= */
void					reverse(t_stack **stack_a, t_stack **stack_b, int move);
void					reverse_node(t_stack **stack);

/* =============== REVERSE ROTATE ============== */
void					reverse_rotate(t_stack **stack_a, t_stack **stack_b,
							int move);
void					reverse_rotate_node(t_stack **stack);

/* =============== SHOW FUNTIONS =============== */
void					show_lst(t_stack **stack);
void					show_error(void);

#endif