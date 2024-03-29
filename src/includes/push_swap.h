/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmendiol <mmendiol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 11:28:18 by mmendiol          #+#    #+#             */
/*   Updated: 2024/03/22 12:20:24 by mmendiol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../../libft/includes/libft.h"
# include "./defines.h"
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack	t_stack;

struct					s_stack
{
	int					id;
	long				num;
	int					cost;
	bool				median;
	bool				min_cost;
	t_stack				*target;
	t_stack				*prev;
	t_stack				*next;
};

void					stack_move_node_a(t_stack **stack_a, t_stack **stack_b);
void					stack_move_node_b(t_stack **stack_a, t_stack **stack_b);

/* =============== PUSH FUNTIONS =============== */
void					push(t_stack **stack_a, t_stack **stack_b, int move);
void					push_node(t_stack **stack, t_stack **node);

/* =============== SWAP FUNTIONS =============== */
void					swap(t_stack **stack_a, t_stack **stack_b, int move);
void					swap_node(t_stack **stack);

/* ============== REVERSE FUNTIONS ============= */
void					rotate(t_stack **stack_a, t_stack **stack_b, int move);
void					rotate_node(t_stack **stack);

/* =============== REVERSE ROTATE ============== */
void					reverse_rotate(t_stack **stack_a, t_stack **stack_b,
							int move);
void					reverse_rotate_node(t_stack **stack);

/* =============== STACK CREATOR =============== */
void					stack_duplicate_arg(t_stack *stack);
void					stack_add_node(t_stack **stack, char **nums,
							int *index);
void					stack_creator(char *av[], t_stack **stack_a);

/* ============= STACK PROPERTIES ============== */
void					stack_index(t_stack *stack);
t_stack					*stack_max(t_stack *stack);
t_stack					*stack_min(t_stack *stack);
t_stack					*stack_min_cost(t_stack *stack);

/* =============== SETTERS STACK =============== */
void					stack_set_min_cost(t_stack *stack);
void					stack_set_above_half(t_stack *stack);
void					stack_set_push_cost(t_stack *stack_a, t_stack *stack_b);
void					stack_set_target_a(t_stack *stack_a, t_stack *stack_b);
void					stack_set_target_b(t_stack *stack_a, t_stack *stack_b);

/* ================= SORT STACK ================ */
int						sorted_stack(t_stack *stack);
void					sort_stack_three(t_stack **stack);
void					sort_stack(t_stack **stack_a, t_stack **stack_b);
void					stack_final_sort(t_stack **stack_a, t_stack **stack_b);

/* ================ STACK UTILS ================ */
t_stack					*last_node(t_stack *lst);
t_stack					*new_node(int id, long num);
void					add_node_back(t_stack **stack, t_stack *new);
long					ft_atol_ps(char *str);
int						stack_len(t_stack *stack);

/* =============== SHOW FUNTIONS =============== */
void					show_lst(t_stack **stack);
void					show_error(void);

#endif