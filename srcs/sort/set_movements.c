/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_movements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 09:52:54 by jhogonca          #+#    #+#             */
/*   Updated: 2024/06/14 09:52:54 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	distance_to_top(t_stack *stack, int reference)
{
	int	distance;

	distance = 0;
	while (stack->value != reference)
	{
		stack = stack->next;
		distance++;
	}
	return (distance);
}

static void	update_moves(int *moves, int *temp_moves)
{
	int	i;
	int	total_moves;
	int	total_temp_moves;

	total_moves = moves[RA] + moves[RB] + moves[RR] + \
	moves[RRA] + moves[RRB] + moves[RRR];
	while (temp_moves[RA] > 0 && temp_moves[RB] > 0)
	{
		temp_moves[RA]--;
		temp_moves[RB]--;
		temp_moves[RR]++;
	}
	while (temp_moves[RRA] > 0 && temp_moves[RRB] > 0)
	{
		temp_moves[RRA]--;
		temp_moves[RRB]--;
		temp_moves[RRR]++;
	}
	total_temp_moves = temp_moves[RA] + temp_moves[RB] + temp_moves[RR];
	total_temp_moves += temp_moves[RRA] + temp_moves[RRB] + temp_moves[RRR];
	i = -1;
	while (++i < 6 && total_temp_moves < total_moves)
		moves[i] = temp_moves[i];
}

static void	calculate_moves_a(t_data *data, int *moves)
{
	int		i;
	int		distance[2];
	int		temp_moves[6];
	t_stack	*temporary;

	temporary = data->stack_a;
	while (temporary)
	{
		i = -1;
		while (++i < 6)
			temp_moves[i] = 0;
		distance[VALUE] = distance_to_top(data->stack_a, temporary->value);
		distance[TARGET] = distance_to_top(data->stack_b, temporary->target);
		if (distance[VALUE] > data->size_of_a / 2)
			temp_moves[RRA] = data->size_of_a - distance[VALUE];
		else
			temp_moves[RA] = distance[VALUE];
		if (distance[TARGET] > data->size_of_b / 2)
			temp_moves[RRB] = data->size_of_b - distance[TARGET];
		else
			temp_moves[RB] = distance[TARGET];
		update_moves(moves, temp_moves);
		temporary = temporary->next;
	}
}

static void	calculate_moves_b(t_data *data, int *moves)
{
	int		i;
	int		distance[2];
	int		temp_moves[6];
	t_stack	*temporary;

	temporary = data->stack_b;
	while (temporary)
	{
		i = -1;
		while (++i < 6)
			temp_moves[i] = 0;
		distance[VALUE] = distance_to_top(data->stack_b, temporary->value);
		distance[TARGET] = distance_to_top(data->stack_a, temporary->target);
		if (distance[VALUE] > data->size_of_b / 2)
			temp_moves[RRB] = data->size_of_b - distance[VALUE];
		else
			temp_moves[RB] = distance[VALUE];
		if (distance[TARGET] > data->size_of_a / 2)
			temp_moves[RRA] = data->size_of_a - distance[TARGET];
		else
			temp_moves[RA] = distance[TARGET];
		update_moves(moves, temp_moves);
		temporary = temporary->next;
	}
}

void	set_moves(t_data *data, int *moves, bool fistPart)
{
	if (fistPart)
		return (calculate_moves_a(data, moves));
	return (calculate_moves_b(data, moves));
}
