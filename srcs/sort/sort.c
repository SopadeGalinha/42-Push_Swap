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

void	sort(t_data *data)
{
	int	moves[6];
	int	i;

	i = -1;
	while (++i < 6)
		moves[i] = 13;
	if (stack_is_sorted(data->stack_a) == true)
		return ;
	if (data->size_of_a <= 4)
		return (sort_four(data));
	push(data, PB);
	push(data, PB);

	print_stack(data);
	while (data->size_of_a > 3)
	{
		set_targets(data);
		set_moves(data, moves);
		execute_moves(data, moves);
		push(data, PB);
	}
}
