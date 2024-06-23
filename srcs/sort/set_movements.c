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

static int	distance_to_top(t_stack *stack, int reference)
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
	int total_moves;
	int total_temp_moves;

	// Inicializar total_moves com a soma dos movimentos atuais
	total_moves = moves[RA] + moves[RB] + moves[RRA] + moves[RRB] + moves[RR] + moves[RRR];

	// Combinar movimentos em temp_moves
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

	// Calcular o total de movimentos em temp_moves
	total_temp_moves = temp_moves[RA] + temp_moves[RB] + temp_moves[RRA] + temp_moves[RRB] + temp_moves[RR] + temp_moves[RRR];

	// Atualizar moves se total_temp_moves for menor que total_moves
	if (total_temp_moves < total_moves)
	{
		for (int i = 0; i < 6; i++)
			moves[i] = temp_moves[i];
	}
	printf("Total moves: %d\n", total_moves);
}

void	set_moves(t_data *data, int *moves)
{
	t_stack	*temporary_a;
	int		distance_value;
	int		distance_target;
	int		temp_moves[6];
	int		i;

	temporary_a = data->stack_a;
	while (temporary_a)
	{
		i = 0;
		while (i < 6)
			temp_moves[i++] = 0;
		distance_value = distance_to_top(data->stack_a, temporary_a->value);
		distance_target = distance_to_top(data->stack_b, temporary_a->target);
		if (distance_value > data->size_of_a / 2)
			temp_moves[RRA] = data->size_of_a - distance_value;
		else
			temp_moves[RA] = distance_value;
		if (distance_target > data->size_of_b / 2)
			temp_moves[RRB] = data->size_of_b - distance_target;
		else
			temp_moves[RB] = distance_target;
		update_moves(moves, temp_moves);
		temporary_a = temporary_a->next;
	}
}