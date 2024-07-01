/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 12:07:48 by jhogonca          #+#    #+#             */
/*   Updated: 2024/06/08 12:07:48 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	execute_moves(t_data *data, int *moves)
{
	while (moves[RRR]-- > 0)
		reverse_rotate(data, RRR);
	while (moves[RR]-- > 0)
		rotate(data, RR);
	while (moves[RA]-- > 0)
		rotate(data, RA);
	while (moves[RB]-- > 0)
		rotate(data, RB);
	while (moves[RRA]-- > 0)
		reverse_rotate(data, RRA);
	while (moves[RRB]-- > 0)
		reverse_rotate(data, RRB);
}

static void	reset_moves(int *moves)
{
	int	i;

	i = -1;
	while (++i < 6)
		moves[i] = INITIAL_VALUE;
}

static void	process_moves(t_data *data, int *moves, int is_a)
{
	int	operation;

	operation = PA;
	if (is_a)
		operation = PB;
	reset_moves(moves);
	set_targets(data);
	set_moves(data, moves, is_a);
	execute_moves(data, moves);
	push(data, operation);
}

void	sort(t_data *data)
{
	int	moves[6];

	if (stack_is_sorted(data->stack_a) == true || data->size_of_a <= 5)
		return (sort_five(data));
	push(data, PB);
	push(data, PB);
	while (data->size_of_a > 5)
		process_moves(data, moves, true);
	sort_five(data);
	while (data->size_of_b > 0)
		process_moves(data, moves, false);
	while (stack_is_sorted(data->stack_a) == false)
		reverse_rotate(data, RRA);
}
