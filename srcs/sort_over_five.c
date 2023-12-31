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

// Função para definir os targets na stack A
static void set_target(t_stack **stack_a, t_stack **stack_b, t_push *st)
{
	(void)st;

	t_stack *temporary_a;
	t_stack *temporary_b;

	temporary_a = *stack_a;
	while (temporary_a != NULL)
	{
		temporary_b = *stack_b;
		temporary_a->target = INT_MIN;
		while (temporary_b != NULL)
		{
			if (temporary_b->value < temporary_a->value && temporary_b->value > temporary_a->target)
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


void	get_cust(t_stack **stack_a, t_stack **stack_b, t_push *st, t_stack *node)
{
	t_stack *temporary;

	(void)st;
	(void)stack_b;
	int index = 0;
	int	ra;
	int	rra;
	int rb;
	int rrb;

	ra = INT_MAX;
	rra = INT_MAX;
	rb = INT_MAX;
	rrb = INT_MAX;
	// Set moves to put the value on top of stack A
	temporary = *stack_a;
	while (temporary->value != node->value && index++ != -1)
		temporary = temporary->next;
	if (index > st->size_of_a / 2)
		rra = st->size_of_a - index;
	else
		ra = index;
	printf("value: %d - index: %d \nra: %d - rra: %d\n\n", node->value, index, ra, rra);
	
	// Set moves to put the target on top of stack B
	index = 0;
	temporary = *stack_b;
	while (temporary->value != node->target && index++ != -1)
		temporary = temporary->next;
	if (index > st->size_of_b / 2)
		rrb = st->size_of_b - index;
	else
		rb = index;
	printf("target: %d - index: %d \nrb: %d - rrb: %d\n\n", node->target, index, rb, rrb);
	if (ra == INT_MAX)
		ra = 0;
	if (rra == INT_MAX)
		rra = 0;
	if (rb == INT_MAX)
		rb = 0;
	if (rrb == INT_MAX)
		rrb = 0;
	if (ra + rb < st->r[0] + st->r[1])
	{
		st->r[0] = ra;
		st->r[1] = rb;
	}
	if (rra + rrb < st->rr[0] + st->rr[1])
	{
		st->rr[0] = rra;
		st->rr[1] = rrb;
	}
	printf("r: %d - %d\nrr: %d - %d\n\n", st->r[0], st->r[1], st->rr[0], st->rr[1]);
}

void set_cust(t_stack **stack_a, t_stack **stack_b, t_push *st)
{
	t_stack *temporary_a;

	temporary_a = *stack_a;
	st->r[0] = 20000;
	st->r[1] = 20000;
	st->rr[0] = 20000;
	st->rr[1] = 20000;
	while (temporary_a != NULL)
	{
		get_cust(stack_a, stack_b, st, temporary_a);
		temporary_a = temporary_a->next;
	}
}

void	sort_over_five(t_stack **stack_a, t_stack **stack_b, t_push *st)
{
	push(stack_a, stack_b, PB, st);
	push(stack_a, stack_b, PB, st);
	push(stack_a, stack_b, PB, st);
	push(stack_a, stack_b, PB, st);
	push(stack_a, stack_b, PB, st);
	set_target(stack_a, stack_b, st);
	set_cust(stack_a, stack_b, st);
	ft_printlist(*stack_a, *stack_b, st);
}
