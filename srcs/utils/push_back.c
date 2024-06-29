/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 08:42:12 by jhogonca          #+#    #+#             */
/*   Updated: 2024/06/08 08:42:12 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/**
 * Create a new node.
 *
 * @param value - The value of the node.
 * @return - The new node.
 */

static t_stack	*create_node(int value)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->value = value;
	node->target = 0;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

bool	push_back(t_stack **stack, int value)
{
	t_stack	*last;
	t_stack	*new;

	last = *stack;
	if (last && last->value == value)
		return (true);
	while (last && last->next)
	{
		if (value == last->value || last->next->value == value)
			return (true);
		last = last->next;
	}
	new = create_node(value);
	if (!new)
		return (true);
	if (!last)
		*stack = new;
	else
	{
		last->next = new;
		new->prev = last;
	}
	return (false);
}
