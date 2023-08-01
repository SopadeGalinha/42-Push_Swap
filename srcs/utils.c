/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 06:26:42 by jhogonca          #+#    #+#             */
/*   Updated: 2023/07/28 06:26:42 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	ft_lstsorted(t_stack *list)
{
	t_stack	*tmp;

	tmp = list;
	while (tmp->next)
	{
		if (tmp->value > tmp->next->value)
			return (false);
		tmp = tmp->next;
	}
	return (true);
}

unsigned int	ft_smallest(t_stack *list)
{
	t_stack			*tmp;
	unsigned int	smallest;

	tmp = list;
	smallest = tmp->index;
	while (tmp)
	{
		if (tmp->index < smallest)
			smallest = tmp->index;
		tmp = tmp->next;
	}
	return (smallest);
}

unsigned int	ft_biggest(t_stack *list)
{
	t_stack			*tmp;
	unsigned int	biggest;

	tmp = list;
	biggest = tmp->index;
	while (tmp)
	{
		if (tmp->index > biggest)
			biggest = tmp->index;
		tmp = tmp->next;
	}
	return (biggest);
}

unsigned	int	lst_distance(t_stack *stack_a, unsigned int index)
{
	t_stack			*node;
	unsigned int	distance;

	node = stack_a;
	distance = 0;
	while (node->index != index)
	{
		node = node->next;
		distance++;
	}
	return (distance);
}

bool	is_on_the_list(t_stack **stack, unsigned int index)
{
	t_stack	*node;

	node = *stack;
	while (node)
	{
		if (node->index == index)
			return (true);
		node = node->next;
	}
	return (false);
}
