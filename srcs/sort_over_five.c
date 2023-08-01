/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_over_five.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 17:00:52 by jhogonca          #+#    #+#             */
/*   Updated: 2023/07/28 17:00:52 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	first_part(t_stack **stack_a, t_stack **stack_b, t_push *st)
{
	st->reference = ft_smallest(*stack_a) + ft_biggest(*stack_a);
	st->reference /= 2;

	while (ft_smallest(*stack_a) < st->reference)
	{
		if (st->reference >= (*stack_a)->index)
			push(stack_a, stack_b, '1', st);
		else
		{
			if (st->size_of_b > 5 && (*stack_b)->index > st->reference)
				rotate(stack_a, stack_b, '3');
			else
				rotate(stack_a, stack_b, '1');
		}
		if (st->size_of_b > 7 && ((*stack_b)->index < st->reference / 2))
		{
			if ((*stack_a)->index > st->reference)
				rotate(stack_a, stack_b, '3');
			else
				rotate(stack_a, stack_b, '2');
		}
	}
}

static void	second_part(t_stack **stack_a, t_stack **stack_b, t_push *st)
{
	while (st->size > 5)
	{
		if (lst_distance(*stack_a, ft_smallest(*stack_a)) < st->size / 2)
		{
			if (st->size_of_b > 1 && (*stack_b)->index < (*stack_b)->next->index)
				rotate(stack_a, stack_b, '3');
			else
				rotate(stack_a, stack_b, '1');
		}	
		else
			reverse_rotate(stack_a, stack_b, '1');
		if (ft_smallest(*stack_a) == (*stack_a)->index)
			push(stack_a, stack_b, '1', st);
	}
	if (!ft_lstsorted(*stack_a))
		sort_under_five(stack_a, stack_b, st);
}

static void	its_on_stack_a(t_stack **stack_a, t_stack **stack_b, t_push *st)
{
	while (st->reference != (*stack_a)->index)
	{
		if (ft_lstlast(*stack_b)->index > (*stack_b)->index)
			reverse_rotate(stack_a, stack_b, '3');
		else
			reverse_rotate(stack_a, stack_b, '1');
	}
	st->reference -= 1;
}

static void	its_on_stack_b(t_stack **stack_a, t_stack **stack_b, t_push *st)
{
	if (lst_distance(*stack_b, st->reference) > st->size_of_b / 2)
	{
		while (st->reference != (*stack_b)->index)
		{
			if (ft_lstlast(*stack_a)->index == ft_biggest(*stack_a)
				|| ft_lstlast(*stack_a)->index < (*stack_b)->index)
			{
				push(stack_a, stack_b, '2', st);
				rotate(stack_a, stack_b, '1');
			}
			else
				reverse_rotate(stack_a, stack_b, '2');
		}
	}
	else
	{
		while (st->reference != (*stack_b)->index)
		{
			if (ft_lstlast(*stack_a)->index < (*stack_b)->index
				|| ft_lstlast(*stack_a)->index == ft_biggest(*stack_a))
			{
				if ((*stack_a)->next->index != st->reference)
					push(stack_a, stack_b, '2', st);
				if ((*stack_b)->index < (*stack_b)->next->index)
					rotate(stack_a, stack_b, '3');
				else
					rotate(stack_a, stack_b, '1');
			}
			else
				rotate(stack_a, stack_b, '2');
		}
	}
	push(stack_a, stack_b, '2', st);
	st->reference -= 1;
}

void	sort_over_five(t_stack **stack_a, t_stack **stack_b, t_push *st)
{
	while (st->size > 12)
		first_part(stack_a, stack_b, st);
	second_part(stack_a, stack_b, st);
	st->reference = (*stack_a)->index - 1;
	while (st->size_of_b > 0)
	{
		if (is_on_the_list(stack_a, st->reference))
			its_on_stack_a(stack_a, stack_b, st);
		else
			its_on_stack_b(stack_a, stack_b, st);
	}
	while (ft_lstsorted(*stack_a) == false)
		reverse_rotate(stack_a, stack_b, '1');
	// ft_printlist(*stack_a, *stack_b, st);
}
