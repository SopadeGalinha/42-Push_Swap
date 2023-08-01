/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_under_five.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 16:59:32 by jhogonca          #+#    #+#             */
/*   Updated: 2023/07/28 16:59:32 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	just_two(t_stack **stack_a, t_stack **stack_b)
{
	if (!ft_lstsorted(*stack_a))
		swap(stack_a, stack_b, '1');
}

static	void	just_three(t_stack **stack_a, t_stack **stack_b, t_push *st)
{
	if (st->size == 2)
		just_two(stack_a, stack_b);
	while (ft_lstsorted(*stack_a) == false)
	{
		if ((*stack_a)->index == ft_smallest(*stack_a)
			&& (*stack_a)->next->index == ft_biggest(*stack_a))
			reverse_rotate(stack_a, stack_b, '1');
		else if ((*stack_a)->index == ft_biggest(*stack_a)
			&& ft_lstlast(*stack_a)->index == ft_smallest(*stack_a))
			just_two(stack_a, stack_b);
		else if (ft_lstlast(*stack_a)->index == ft_smallest(*stack_a)
			&& (*stack_a)->next->index == ft_biggest(*stack_a))
			reverse_rotate(stack_a, stack_b, '1');
		else if ((*stack_a)->index == ft_biggest(*stack_a)
			&& (*stack_a)->next->index == ft_smallest(*stack_a))
			rotate(stack_a, stack_b, '1');
		else if (ft_lstlast(*stack_a)->index == ft_biggest(*stack_a)
			&& (*stack_a)->next->index == ft_smallest(*stack_a))
			swap(stack_a, stack_b, '1');
		else
			break ;
	}
}

static void	just_four(t_stack **stack_a, t_stack **stack_b, t_push *st)
{
	if (ft_lstlast(*stack_a)->index == ft_smallest(*stack_a))
		reverse_rotate(stack_a, stack_b, '1');
	else
		while ((*stack_a)->index != ft_smallest(*stack_a))
			rotate(stack_a, stack_b, '1');
	push(stack_a, stack_b, '1', st);
	just_three(stack_a, stack_b, st);
	push(stack_a, stack_b, '2', st);
}

void	sort_under_five(t_stack **stack_a, t_stack **stack_b, t_push *st)
{
	if (st->size <= 3)
		just_three(stack_a, stack_b, st);
	else
	{
		if (st->size == 5)
		{
			while ((*stack_a)->index != ft_smallest(*stack_a)
				&& (*stack_a)->index != (ft_smallest(*stack_a) + 1))
			{
				if (ft_lstlast(*stack_a)->prev->index == ft_smallest(*stack_a))
					reverse_rotate(stack_a, stack_b, '1');
				else if (ft_lstlast(*stack_a)->index == ft_smallest(*stack_a))
					reverse_rotate(stack_a, stack_b, '1');
				else
					rotate(stack_a, stack_b, '1');
			}
			push(stack_a, stack_b, '1', st);
			just_four(stack_a, stack_b, st);
			push(stack_a, stack_b, '2', st);
			if (ft_lstsorted(*stack_a) == false)
				swap(stack_a, stack_b, '1');
		}
		else
			just_four(stack_a, stack_b, st);
	}
}
