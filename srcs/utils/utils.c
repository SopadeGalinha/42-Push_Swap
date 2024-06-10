/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 11:42:34 by jhogonca          #+#    #+#             */
/*   Updated: 2024/06/08 11:42:34 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

bool	stack_is_sorted(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp->next)
	{
		if (tmp->value > tmp->next->value)
			return (false);
		tmp = tmp->next;
	}
	return (true);
}

int	smallest_value(t_stack *stack)
{
	t_stack			*tmp;
	int				smallest;

	tmp = stack;
	smallest = tmp->value;
	while (tmp)
	{
		if (tmp->value < smallest)
			smallest = tmp->value;
		tmp = tmp->next;
	}
	return (smallest);
}

int	biggest_value(t_stack *stack)
{
	t_stack			*tmp;
	int				biggest;

	tmp = stack;
	biggest = tmp->value;
	while (tmp)
	{
		if (tmp->value > biggest)
			biggest = tmp->value;
		tmp = tmp->next;
	}
	return (biggest);
}

t_stack	*stack_last(t_stack *stack)
{
	t_stack	*last;

	if (!stack)
		return (NULL);
	last = stack;
	while (last->next)
		last = last->next;
	return (last);
}
