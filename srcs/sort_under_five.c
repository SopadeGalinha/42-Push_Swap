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
		swap(stack_a, stack_b, SA);
}

static	void	just_three(t_stack **stack_a, t_stack **stack_b, t_push *st)
{
	if (st->size_of_a == 2)
		just_two(stack_a, stack_b);
	while (ft_lstsorted(*stack_a) == false)
	{
		if ((*stack_a)->index == ft_smallest(*stack_a)
			&& (*stack_a)->next->index == ft_biggest(*stack_a))
			reverse_rotate(stack_a, stack_b, RRA);
		else if ((*stack_a)->index == ft_biggest(*stack_a)
			&& ft_lstlast(*stack_a)->index == ft_smallest(*stack_a))
			just_two(stack_a, stack_b);
		else if (ft_lstlast(*stack_a)->index == ft_smallest(*stack_a)
			&& (*stack_a)->next->index == ft_biggest(*stack_a))
			reverse_rotate(stack_a, stack_b, RRA);
		else if ((*stack_a)->index == ft_biggest(*stack_a)
			&& (*stack_a)->next->index == ft_smallest(*stack_a))
			rotate(stack_a, stack_b, RA);
		else if (ft_lstlast(*stack_a)->index == ft_biggest(*stack_a)
			&& (*stack_a)->next->index == ft_smallest(*stack_a))
			swap(stack_a, stack_b, SA);
		else
			break ;
	}
}

static void	just_four(t_stack **stack_a, t_stack **stack_b, t_push *st)
{
	if (ft_lstlast(*stack_a)->index == ft_smallest(*stack_a))
		reverse_rotate(stack_a, stack_b, RRA);
	else
		while ((*stack_a)->index != ft_smallest(*stack_a))
			rotate(stack_a, stack_b, RA);
	push(stack_a, stack_b, PB, st);
	just_three(stack_a, stack_b, st);
	push(stack_a, stack_b, PA, st);
}

void	sort_under_five(t_stack **stack_a, t_stack **stack_b, t_push *st)
{
	if (st->size_of_a <= 3)
		just_three(stack_a, stack_b, st);
	else
	{
		if (st->size_of_a == 5)
		{
			while ((*stack_a)->index != ft_smallest(*stack_a)
				&& (*stack_a)->index != (ft_smallest(*stack_a) + 1))
			{
				if (ft_lstlast(*stack_a)->prev->index == ft_smallest(*stack_a))
					reverse_rotate(stack_a, stack_b, RRA);
				else if (ft_lstlast(*stack_a)->index == ft_smallest(*stack_a))
					reverse_rotate(stack_a, stack_b, RRA);
				else
					rotate(stack_a, stack_b, RA);
			}
			push(stack_a, stack_b, PB, st);
			just_four(stack_a, stack_b, st);
			push(stack_a, stack_b, PA, st);
			if (ft_lstsorted(*stack_a) == false)
				swap(stack_a, stack_b, SA);
		}
		else
			just_four(stack_a, stack_b, st);
	}
}
