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

static void	execute_moves(t_stack **stack_a, t_stack **stack_b, t_push *st)
{
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

void	sort_list(t_stack **stack_a, t_stack **stack_b, t_push *st)
{
	if (ft_lstsorted(*stack_a))
		return ;
	push(stack_a, stack_b, PB, st);
	push(stack_a, stack_b, PB, st);
	while (st->size_of_a > 3)
	{
		set_target_in_b(stack_a, stack_b);
		set_cust(stack_a, stack_b, st, 'A');
		execute_moves(stack_a, stack_b, st);
		push(stack_a, stack_b, PB, st);
	}
	sort_three(stack_a, stack_b, st);
	while (st->size_of_b)
	{
		set_target_in_a(stack_a, stack_b);
		set_cust(stack_a, stack_b, st, 'B');
		execute_moves(stack_a, stack_b, st);
		push(stack_a, stack_b, PA, st);
	}
	while (ft_lstsorted(*stack_a) == false)
		reverse_rotate(stack_a, stack_b, RRA, st);
}
