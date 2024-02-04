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

static void	set_target_in_a(t_stack **stack_a, t_stack **stack_b);
static void	set_target_in_b(t_stack **stack_a, t_stack **stack_b);
static void	execute_moves(t_stack **stack_a, t_stack **stack_b, t_push *st);

void	sort_list(t_stack **stack_a, t_stack **stack_b, t_push *st)
{
	if (ft_lstsorted(*stack_a))
		return ;
	push(stack_a, stack_b, PB, st);
	push(stack_a, stack_b, PB, st);
	while (st->size_of_a > 3)
	{
		set_target_in_b(stack_a, stack_b);
		get_moves(stack_a, stack_b, st, 'A');
		execute_moves(stack_a, stack_b, st);
		push(stack_a, stack_b, PB, st);
	}
	sort_three(stack_a, stack_b, st);
	while (st->size_of_b)
	{
		set_target_in_a(stack_a, stack_b);
		get_moves(stack_a, stack_b, st, 'B');
		execute_moves(stack_a, stack_b, st);
		push(stack_a, stack_b, PA, st);
	}
	while (ft_lstsorted(*stack_a) == false)
		reverse_rotate(stack_a, stack_b, RRA, st);
}

static void	set_target_in_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temporary_a;
	t_stack	*temporary_b;

	temporary_a = *stack_a;
	while (temporary_a != NULL)
	{
		temporary_b = *stack_b;
		temporary_a->target = INT_MIN;
		while (temporary_b != NULL)
		{
			if (temporary_b->value < temporary_a->value
				&& temporary_b->value > temporary_a->target)
			{
				temporary_a->target = temporary_b->value;
			}
			temporary_b = temporary_b->next;
		}
		if (temporary_a->target == INT_MIN)
			temporary_a->target = ft_biggest(*stack_b);
		temporary_a = temporary_a->next;
	}
}

static void	set_target_in_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temporary_a;
	t_stack	*temporary_b;

	temporary_b = *stack_b;
	while (temporary_b != NULL)
	{
		temporary_a = *stack_a;
		temporary_b->target = INT_MAX;
		while (temporary_a != NULL)
		{
			if (temporary_a->value > temporary_b->value \
			&& temporary_a->value < temporary_b->target)
				temporary_b->target = temporary_a->value;
			temporary_a = temporary_a->next;
		}
		if (temporary_b->target == INT_MAX)
			temporary_b->target = ft_smallest(*stack_a);
		temporary_b = temporary_b->next;
	}
}

static void	execute_moves(t_stack **stack_a, t_stack **stack_b, t_push *st)
{
	if (*stack_a == NULL)
	{
		st->error = true;
		return ;
	}
	while (st->rotate[RRR]--)
		reverse_rotate(stack_a, stack_b, RRR, st);
	while (st->rotate[RR]--)
		rotate(stack_a, stack_b, RR, st);
	while (st->rotate[RA]--)
		rotate(stack_a, stack_b, RA, st);
	while (st->rotate[RB]--)
		rotate(stack_a, stack_b, RB, st);
	while (st->rotate[RRA]--)
		reverse_rotate(stack_a, stack_b, RRA, st);
	while (st->rotate[RRB]--)
		reverse_rotate(stack_a, stack_b, RRB, st);
}
