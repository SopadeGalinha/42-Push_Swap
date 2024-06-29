/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 11:34:33 by jhogonca          #+#    #+#             */
/*   Updated: 2024/06/08 11:34:33 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	rotate_operation(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (!*stack || !(*stack)->next)
		return ;
	first = *stack;
	last = *stack;
	while (last->next)
		last = last->next;
	*stack = first->next;
	(*stack)->prev = NULL;
	first->next = NULL;
	last->next = first;
	first->prev = last;
}

void	rotate(t_data *data, int move)
{
	if (!(move == RA || move == RB || move == RR))
		write(STDERR_FILENO, "Fix your code!\n", 15);
	if (move == RA || move == RR)
		rotate_operation(&data->stack_a);
	if (move == RB || move == RR)
		rotate_operation(&data->stack_b);
	if (DEBUG || data->checker)
		return ;
	if (move == RA)
		write(STDOUT_FILENO, "ra\n", 3);
	else if (move == RB)
		write(STDOUT_FILENO, "rb\n", 3);
	else if (move == RR)
		write(STDOUT_FILENO, "rr\n", 3);
}
