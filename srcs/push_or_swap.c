/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_or_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 16:18:26 by jhogonca          #+#    #+#             */
/*   Updated: 2023/07/28 16:18:26 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// IF Move = 1, swap stack_a
// IF Move = 2, swap stack_b
// IF Move = 3, swap both stacks

static void	swap_operation(t_stack **stack);
static void	push_operation(t_stack **src, t_stack **dst);

void	swap(t_stack **stack_a, t_stack **stack_b, char move)
{
	if (!(move == '1' || move == '2' || move == '3'))
		write(1, "Swap: fix your code\n", 20);
	if (stack_a == NULL && stack_b == NULL)
		return ;
	if (move == '1' || move == '3')
		swap_operation(stack_a);
	if (move == '2' || move == '3')
		swap_operation(stack_b);
	if (move == '1')
		write(1, "sa\n", 3);
	if (move == '2')
		write(1, "sb\n", 3);
	if (move == '3')
		write(1, "ss\n", 3);
}

static void	swap_operation(t_stack **stack)
{
	t_stack	*temporary;
	t_stack	*swap;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	temporary = *stack;
	swap = (*stack)->next;
	if (swap->next)
		swap->next->prev = *stack;
	swap->prev = temporary->prev;
	temporary->prev = swap;
	(*stack)->next = swap->next;
	swap->next = temporary;
	*stack = swap;
}

void	push(t_stack **stack_a, t_stack **stack_b, char move, t_push *st)
{
	if (!(move == '1' || move == '2' || move == '3'))
		write(1, "Push: fix your code\n", 20);
	if (move == '1')
	{
		push_operation(stack_a, stack_b);
		st->size--;
		st->size_of_b++;
	}
	if (move == '2')
	{
		push_operation(stack_b, stack_a);
		st->size++;
		st->size_of_b--;
	}
	if (move == '1')
		write(1, "pa\n", 3);
	if (move == '2')
		write(1, "pb\n", 3);
}

static void	push_operation(t_stack **src, t_stack **dst)
{
	t_stack	*top_s;
	t_stack	*top_d;

	if (*src == NULL)
		return ;
	top_s = *src;
	top_d = *dst;
	*src = top_s->next;
	if (*src)
		(*src)->prev = NULL;
	if (top_d == NULL)
	{
		top_s->next = NULL;
		*dst = top_s;
		(*dst)->prev = NULL;
		return ;
	}
	top_s->next = top_d;
	top_d->prev = top_s;
	*dst = top_s;
}
