/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmendiol <mmendiol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 10:34:44 by mmendiol          #+#    #+#             */
/*   Updated: 2024/03/12 17:45:06 by mmendiol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void    free_matrix(char **matrix)
{
    int i;

    i = 0;
    while (matrix[i])
        free(matrix[i++]);
    free(matrix);
}