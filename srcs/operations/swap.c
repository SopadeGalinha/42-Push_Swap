/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 10:23:45 by jhogonca          #+#    #+#             */
/*   Updated: 2024/06/08 10:23:45 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	swap_operation(t_stack **stack)
{
	t_stack	*temp;

	if (!*stack || !(*stack)->next)
		return ;
	temp = (*stack)->next;
	(*stack)->next = temp->next;
	if (temp->next)
		temp->next->prev = *stack;
	temp->next = *stack;
	temp->prev = (*stack)->prev;
	(*stack)->prev = temp;
	*stack = temp;
}

void	swap(t_data *data, int move)
{
	if (!(move == SA || move == SB || move == SS))
		write(STDERR_FILENO, "Fix your code!\n", 15);
	if (move == SA || move == SS)
		swap_operation(&data->stack_a);
	if (move == SB || move == SS)
		swap_operation(&data->stack_b);
	if (DEBUG || data->checker)
		return ;
	if (move == SA)
		write(STDOUT_FILENO, "sa\n", 3);
	else if (move == SB)
		write(STDOUT_FILENO, "sb\n", 3);
	else if (move == SS)
		write(STDOUT_FILENO, "ss\n", 3);
}
