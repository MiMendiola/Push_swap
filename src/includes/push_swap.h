/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmendiol <mmendiol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 11:28:18 by mmendiol          #+#    #+#             */
/*   Updated: 2024/03/12 20:02:50 by mmendiol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../../libft_ext/includes/libft.h"
# include "./defines.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

void					show_error(char *str);

typedef struct s_lst	t_lst;

struct					s_lst
{
	int					id;
	long				num;
	t_lst				*prev;
	t_lst				*next;
};

#endif