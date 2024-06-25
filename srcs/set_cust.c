/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 17:38:00 by jhogonca          #+#    #+#             */
/*   Updated: 2024/01/01 17:38:00 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_values_aux(t_push *st, int *rotate);
static void	set_values(t_push *st, int *rotate);
static void	get_min_moves_to_a(t_stack **stack_a, t_stack **stack_b, \
t_push *st, t_stack *node);
static void	get_min_moves_to_b(t_stack **stack_a, t_stack **stack_b, \
t_push *st, t_stack *node);

void	get_moves(t_stack **stack_a, t_stack **stack_b, t_push *st, int stack)
{
	t_stack	*temporary;
	int i;

	temporary = *stack_b;
	if (stack == 'A')
		temporary = *stack_a;
	i = 0;
	while (i < 6)
		st->rotate[i++] = 100;
	while (temporary != NULL)
	{
		if (stack == 'A')
			get_min_moves_to_a(stack_a, stack_b, st, temporary);
		else
			get_min_moves_to_b(stack_a, stack_b, st, temporary);
		temporary = temporary->next;
	}
}

static void	get_min_moves_to_a(t_stack **stack_a, t_stack **stack_b, \
t_push *st, t_stack *node)
{
	int		index;
	int		rotate[6];
	t_stack	*temporary;

	index = 0;
	while (index < 6)
		rotate[index++] = INT_MAX;
 	rotate[RR] = 0;
	rotate[RRR] = 0;
	index = 0;
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
		temporary = temporary->next;
	if (index > st->size_of_b / 2)
		rotate[RRB] = st->size_of_b - index;
	else
		rotate[RB] = index;
	return (set_values(st, rotate));
}

static void	get_min_moves_to_b(t_stack **stack_a, t_stack **stack_b, \
t_push *st, t_stack *node)
{
	int		index;
	int		rotate[6];
	t_stack	*temporary;

	index = 0;
	while (index < 6)
		rotate[index++] = INT_MAX;
 	rotate[RR] = 0;
	rotate[RRR] = 0;
	index = 0;
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
	if (index > st->size_of_a / 2)
		rotate[RRA] = st->size_of_a - index;
	else
		rotate[RA] = index;
	return (set_values(st, rotate));
}

static void	set_values(t_push *st, int *rotate)
{
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

static void	set_values_aux(t_push *st, int *rotate)
{
	int i;

	i = -1;
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
		while (++i < 6)
			st->rotate[i] = rotate[i];	
	}
}
