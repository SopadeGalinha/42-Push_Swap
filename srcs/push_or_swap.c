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

void	swap(t_stack **stack_a, t_stack **stack_b, int move, t_push *st)
{
	if (!(move == SA || move == SB || move == SS))
		write(st->fd, "Swap: fix your code\n", 20);
	if (stack_a == NULL && stack_b == NULL)
		return ;
	if (move == SA || move == SS)
		swap_operation(stack_a);
	if (move == SB || move == SS)
		swap_operation(stack_b);
	if (st->fd == -1)
		return ;
	if (move == SA)
		write(st->fd, "sa\n", 3);
	if (move == SB)
		write(st->fd, "sb\n", 3);
	if (move == SS)
		write(st->fd, "ss\n", 3);
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

void	push(t_stack **stack_a, t_stack **stack_b, int move, t_push *st)
{
	if (!(move == PB || move == PA))
		write(st->fd, "Push: fix your code\n", 20);
	if (move == PB)
	{
		push_operation(stack_a, stack_b);
		st->size_of_a--;
		st->size_of_b++;
	}
	if (move == PA)
	{
		push_operation(stack_b, stack_a);
		st->size_of_a++;
		st->size_of_b--;
	}
	if (st->fd == -1)
		return ;
	if (move == PB)
		write(st->fd, "pb\n", 3);
	if (move == PA)
		write(st->fd, "pa\n", 3);
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
