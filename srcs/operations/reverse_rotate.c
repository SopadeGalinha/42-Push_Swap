/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 11:32:05 by jhogonca          #+#    #+#             */
/*   Updated: 2024/06/08 11:32:05 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	reverse_rotate_operation(t_stack **stack)
{
	t_stack	*last;

	if (!*stack || !(*stack)->next)
		return ;
	last = *stack;
	while (last->next)
		last = last->next;
	last->prev->next = NULL;
	last->next = *stack;
	(*stack)->prev = last;
	*stack = last;
	last->prev = NULL;
}

void	reverse_rotate(t_data *data, int move)
{
	if (!(move == RRA || move == RRB || move == RRR))
		write(STDERR_FILENO, "Fix your code!\n", 15);
	if (move == RRA || move == RRR)
		reverse_rotate_operation(&data->stack_a);
	if (move == RRB || move == RRR)
		reverse_rotate_operation(&data->stack_b);
	if (DEBUG || BONUS)
		return ;
	if (move == RRA)
		write(STDOUT_FILENO, "rra\n", 4);
	else if (move == RRB)
		write(STDOUT_FILENO, "rrb\n", 4);
	else if (move == RRR)
		write(STDOUT_FILENO, "rrr\n", 4);
}
