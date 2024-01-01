/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_cust.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 17:38:00 by jhogonca          #+#    #+#             */
/*   Updated: 2024/01/01 17:38:00 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_values_aux(t_push *st, int *rotate)
{
	if (rotate[RRA] > 0 && rotate[RRB] > 0)
	{
		while (rotate[RRA] && rotate[RRB])
		{
			rotate[RRR]++;
			rotate[RRA]--;
			rotate[RRB]--;
		}
	}
	if (rotate[RA] + rotate[RB] + rotate[RRA] + rotate[RRB] \
		+ rotate[RR] + rotate[RRR] < st->rotate[RA] + st->rotate[RB] \
		+ st->rotate[RRA] + st->rotate[RRB] + st->rotate[RRR] + st->rotate[RR])
	{
		st->rotate[RA] = rotate[RA];
		st->rotate[RB] = rotate[RB];
		st->rotate[RR] = rotate[RR];
		st->rotate[RRA] = rotate[RRA];
		st->rotate[RRB] = rotate[RRB];
		st->rotate[RRR] = rotate[RRR];
	}
}

static void	set_values(t_push *st, int index, int *rotate)
{
	if (index > st->size_of_b / 2)
		rotate[RRB] = st->size_of_b - index;
	else
		rotate[RB] = index;
	
	if (rotate[RA] == INT_MAX)
		rotate[RA] = 0;
	if (rotate[RRA] == INT_MAX)
		rotate[RRA] = 0;
	if (rotate[RB] == INT_MAX)
		rotate[RB] = 0;
	if (rotate[RRB] == INT_MAX)
		rotate[RRB] = 0;
	if (rotate[RA] > 0 && rotate[RB] > 0)
	{
		while (rotate[RA] && rotate[RB])
		{
			rotate[RR]++;
			rotate[RA]--;
			rotate[RB]--;
		}
	}
	set_values_aux(st, rotate);
}

void get_cust(t_stack **stack_a, t_stack **stack_b, t_push *st, t_stack *node)
{
    int		index;
	int		rotate[6];
    t_stack	*temporary;

    index = 0;
    rotate[RR] = 0;
    rotate[RRR] = 0;
    rotate[RA] = INT_MAX;
    rotate[RB] = INT_MAX;
    rotate[RRA] = INT_MAX;
    rotate[RRB] = INT_MAX;
    temporary = *stack_a;
    while (temporary->value != node->value && index++ != -1)
        temporary = temporary->next;
    if (index > st->size_of_a / 2)
        rotate[RRA] = st->size_of_a - index;
    else
        rotate[RA] = index;
    index = 0;
    temporary = *stack_b;
    while (temporary->value != node->target && index++ != -1)
	{
        temporary = temporary->next;
	}
	return set_values(st, index, rotate);
}

void	set_values_b(t_push *st, int index, int *rotate)
{
	if (index > st->size_of_a / 2)
		rotate[RRA] = st->size_of_a - index;
	else
		rotate[RA] = index;
	if (rotate[RA] == INT_MAX)
		rotate[RA] = 0;
	if (rotate[RRA] == INT_MAX)
		rotate[RRA] = 0;
	if (rotate[RB] == INT_MAX)
		rotate[RB] = 0;
	if (rotate[RRB] == INT_MAX)
		rotate[RRB] = 0;
	if (rotate[RA] > 0 && rotate[RB] > 0)
	{
		while (rotate[RA] && rotate[RB])
		{
			rotate[RR]++;
			rotate[RA]--;
			rotate[RB]--;
		}
	}
	set_values_aux(st, rotate);
}

void	get_cust_to_b(t_stack **stack_a, t_stack **stack_b, t_push *st, t_stack *node)
{
	int		index;
	int		rotate[6];
	t_stack	*temporary;

	index = 0;
	rotate[RR] = 0;
	rotate[RRR] = 0;
	rotate[RA] = INT_MAX;
	rotate[RB] = INT_MAX;
	rotate[RRA] = INT_MAX;
	rotate[RRB] = INT_MAX;
	temporary = *stack_b;
	while (temporary->value != node->value && index++ != -1)
		temporary = temporary->next;
	if (index > st->size_of_b / 2)
		rotate[RRB] = st->size_of_b - index;
	else
		rotate[RB] = index;
	index = 0;
	temporary = *stack_a;
	while (temporary->value != node->target && index++ != -1)
		temporary = temporary->next;
	return set_values_b(st, index, rotate);
}

void set_cust(t_stack **stack_a, t_stack **stack_b, t_push *st, int stack)
{
	t_stack *temporary;

	temporary = *stack_b;
	if (stack == 'A')
		temporary = *stack_a;
	st->rotate[RA] = 100;
	st->rotate[RB] = 100;
	st->rotate[RR] = 100;
	st->rotate[RRA] = 100;
	st->rotate[RRB] = 100;
	st->rotate[RRR] = 100;
	while (temporary != NULL)
	{
		if (stack == 'A')
			get_cust(stack_a, stack_b, st, temporary);
		else
		get_cust_to_b(stack_a, stack_b, st, temporary);
		temporary = temporary->next;
	}
}
