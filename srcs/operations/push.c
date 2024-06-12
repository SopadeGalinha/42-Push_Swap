/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 11:33:34 by jhogonca          #+#    #+#             */
/*   Updated: 2024/06/08 11:33:34 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	push_operation(t_stack **src, t_stack **dst)
{
	t_stack	*temp;

	if (!*src)
		return ;
	temp = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	temp->next = *dst;
	if (*dst)
		(*dst)->prev = temp;
	*dst = temp;
}

void	push(t_data *data, int move)
{
	if (!(move == PA || move == PB))
		write(STDERR_FILENO, "Fix your code!\n", 15);
	if (move == PA)
		push_operation(&data->stack_b, &data->stack_a);
	if (move == PB)
		push_operation(&data->stack_a, &data->stack_b);
	if (move == PA)
	{
		data->size_of_a++;
		data->size_of_b--;
		if (!DEBUG && !BONUS)
			write(STDOUT_FILENO, "pa\n", 3);
	}
	else if (move == PB)
	{
		data->size_of_a--;
		data->size_of_b++;
		if (!DEBUG && !BONUS)
			write(STDOUT_FILENO, "pb\n", 3);
	}
}
