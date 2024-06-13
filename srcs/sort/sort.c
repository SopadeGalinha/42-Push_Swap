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

int	get_distance(t_stack *stack, int value)
{
	int	distance;

	while (stack->value != value)
	{
		stack = stack->next;
		distance++;
	}
	return (distance);
}

void	set_moves(t_data *data, int *moves, bool isfirstLoop)
{
	int		i;
	int		distance;
	t_stack	*temporary;

	(void)isfirstLoop;
	(void)moves;
	i = -1;
	while (++i < 6)
		moves[i] = 100;
	temporary = data->stack_a;
	while (temporary != NULL)
	{
		distance = get_distance(data->stack_a, temporary->value);
		printf("Value: %d - Distance: %d\n", temporary->value, distance);
		temporary = temporary->next;
	}
	exit(0);
}

void	sort(t_data *data)
{
	int	moves[6];

	(void)moves;
	if (stack_is_sorted(data->stack_a) == true)
		return ;
	if (data->size_of_a <= 4)
		return (sort_four(data));
	push(data, PB);
	push(data, PB);
	push(data, PB);
	push(data, PB);
	set_targets(data);
}
