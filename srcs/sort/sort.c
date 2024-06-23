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

void	sort(t_data *data)
{
	int	moves[6];

	if (stack_is_sorted(data->stack_a) == true || data->size_of_a <= 4)
		return (sort_four(data));
	push(data, PB);
	push(data, PB);
	while (data->size_of_a > 4)
	{
		reset_moves(moves);
		set_targets(data);
		set_moves(data, moves, true);
		execute_moves(data, moves);
		push(data, PB);
	}
	sort_four(data);
	while (data->size_of_b > 0)
	{
		reset_moves(moves);
		set_targets(data);
		set_moves(data, moves, false);
		execute_moves(data, moves);
		push(data, PA);
	}
	while (stack_is_sorted(data->stack_a) == false)
		reverse_rotate(data, RRA);
}
