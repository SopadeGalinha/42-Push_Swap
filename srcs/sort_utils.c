/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c	                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 16:59:32 by jhogonca          #+#    #+#             */
/*   Updated: 2023/07/28 16:59:32 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **stack_a, t_stack **stack_b, t_push *st)
{
	if (st->size_of_a == 2)
		swap(stack_a, stack_b, SA, st);
	while (ft_lstsorted(*stack_a) == false)
	{
		if ((*stack_a)->value == ft_smallest(*stack_a)
			&& (*stack_a)->next->value == ft_biggest(*stack_a))
			reverse_rotate(stack_a, stack_b, RRA, st);
		else if ((*stack_a)->value == ft_biggest(*stack_a)
			&& ft_lstlast(*stack_a)->value == ft_smallest(*stack_a))
			swap(stack_a, stack_b, SA, st);
		else if (ft_lstlast(*stack_a)->value == ft_smallest(*stack_a)
			&& (*stack_a)->next->value == ft_biggest(*stack_a))
			reverse_rotate(stack_a, stack_b, RRA, st);
		else if ((*stack_a)->value == ft_biggest(*stack_a)
			&& (*stack_a)->next->value == ft_smallest(*stack_a))
			rotate(stack_a, stack_b, RA, st);
		else if (ft_lstlast(*stack_a)->value == ft_biggest(*stack_a)
			&& (*stack_a)->next->value == ft_smallest(*stack_a))
			swap(stack_a, stack_b, SA, st);
		else
			break ;
	}
}

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

int	ft_smallest(t_stack *list)
{
	t_stack			*tmp;
	int				smallest;

	tmp = list;
	smallest = tmp->value;
	while (tmp)
	{
		if (tmp->value < smallest)
			smallest = tmp->value;
		tmp = tmp->next;
	}
	return (smallest);
}

int	ft_biggest(t_stack *list)
{
	t_stack			*tmp;
	int				biggest;

	tmp = list;
	biggest = tmp->value;
	while (tmp)
	{
		if (tmp->value > biggest)
			biggest = tmp->value;
		tmp = tmp->next;
	}
	return (biggest);
}

t_stack	*ft_lstlast(t_stack *lst)
{
	t_stack	*last;

	if (!lst)
		return (NULL);
	last = lst;
	while (last->next)
		last = last->next;
	return (last);
}
