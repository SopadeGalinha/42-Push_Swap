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

int	get_distance(t_stack *stack, int value, bool is_target)
{
	int		distance;
	t_stack	*temporary;

	(void)is_target;
	temporary = stack;
	distance = 0;
	while (temporary != NULL)
	{
		if ((temporary->value == value) || \
			(temporary->target == value))
			break ;
		temporary = temporary->next;
		distance++;
	}
	return (distance);
}

void	update_moves(t_data *data, int *distance, int *moves)
{
	(void)data;
	(void)distance;
	(void)moves;
	printf("Distance value: %d\n", distance[0]);
	printf("Distance target: %d\n", distance[1]);
}

void	set_moves(t_data *data, int *moves, bool isfirstLoop)
{
	int		i;
	int		distance[2];
	t_stack	*temporary;

	(void)isfirstLoop;
	(void)moves;
	i = -1;
	while (++i < 6)
		moves[i] = 0;
	temporary = data->stack_a;
	while (temporary != NULL)
	{
		distance[VALUE] = get_distance(data->stack_a, temporary->value, false);
		distance[TARGET] = get_distance(data->stack_b, temporary->target, true);
		update_moves(data, distance, moves);
		temporary = temporary->next;
	}
	printf("\n");
}
