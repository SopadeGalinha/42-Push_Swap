/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 11:41:03 by jhogonca          #+#    #+#             */
/*   Updated: 2024/06/08 11:41:03 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	clear(t_stack **stack)
{
	t_stack	*temporary;

	while (*stack)
	{
		temporary = *stack;
		*stack = (*stack)->next;
		free(temporary);
	}
}

void	free_array(char **array)
{
	int	index;

	if (!array)
		return ;
	index = -1;
	while (array[++index])
		free(array[index]);
	free(array);
}
