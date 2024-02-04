/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_or_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 16:17:31 by jhogonca          #+#    #+#             */
/*   Updated: 2023/07/28 16:17:31 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// IF Move = 1, rotate stack_a
// IF Move = 2, rotate stack_b
// IF Move = 3, rotate both stacks

static void	rotate_operation(t_stack **stack);
static void	reverse_rotate_operation(t_stack **stack);

void	rotate(t_stack **stack_a, t_stack **stack_b, int move, t_push *st)
{
	if (!(move == RA || move == RB || move == RR))
		write(1, "Rotate: fix your code\n", 22);
	if (stack_a == NULL && stack_b == NULL)
		return ;
	if (move == RA || move == RR)
		rotate_operation(stack_a);
	if (move == RB || move == RR)
		rotate_operation(stack_b);
	if (st->checker)
		return ;
	if (move == RA)
		write(1, "ra\n", 3);
	if (move == RB)
		write(1, "rb\n", 3);
	if (move == RR)
		write(1, "rr\n", 3);
}

static void	rotate_operation(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;
	t_stack	*second;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	first = *stack;
	second = (*stack)->next;
	last = ft_lstlast(*stack);
	*stack = second;
	second->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
}

void	reverse_rotate(t_stack **stack_a, t_stack **stack_b, \
int move, t_push *st)
{
	if (!(move == RRA || move == RRB || move == RRR))
		write(1, "Reverse Rotate: fix your code\n", 31);
	if (stack_a == NULL && stack_b == NULL)
		return ;
	if (move == RRA || move == RRR)
		reverse_rotate_operation(stack_a);
	if (move == RRB || move == RRR)
		reverse_rotate_operation(stack_b);
	if (st->checker)
		return ;
	if (move == RRA)
		write(1, "rra\n", 4);
	if (move == RRB)
		write(1, "rrb\n", 4);
	if (move == RRR)
		write(1, "rrr\n", 4);
}

static void	reverse_rotate_operation(t_stack **stack)
{
	t_stack	*temporary;
	t_stack	*last;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	last = *stack;
	while (last->next)
	{
		temporary = last;
		last = last->next;
	}
	last->next = *stack;
	temporary->next = NULL;
	(*stack)->prev = last;
	*stack = last;
	(*stack)->prev = NULL;
}
