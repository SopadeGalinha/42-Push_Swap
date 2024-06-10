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

/**
 * @brief Sorts a stack with 3 elements
 * 
 * @param data The data structure
 * @note possible cases: 3 2 1 = SA, RRA
 * @note possible cases: 1 3 2 = SA, RA
 * @note possible cases: 2 1 3 = SA
 * @note possible cases: 2 3 1 = RRA
 * @note possible cases: 3 1 2 = RA
 * 
*/
void	sort_three(t_data *data)
{
	int	first;
	int	middle;
	int	last;

	first = data->stack_a->value;
	middle = data->stack_a->next->value;
	last = data->stack_a->next->next->value;
	if (data->size_of_a == 2)
		return (swap(data, SA));
	if ((first > middle && middle > last) || \
		(middle > last && last > first) || \
		(last > first && first > middle))
		swap(data, SA);
	if ((middle > last && last > first) || \
		(first > last && last > middle))
		rotate(data, RA);
	if ((first > middle && middle > last) || \
		(middle > first && first > last))
		reverse_rotate(data, RRA);
}

void	sort_four(t_data *data)
{
	if (data->size_of_a == 3)
		return (sort_three(data));
	if (smallest_value(data->stack_a) == stack_last(data->stack_a)->value)
		reverse_rotate(data, RRA);
	else if (smallest_value(data->stack_a) == data->stack_a->next->value)
		swap(data, SA);
	if (data->stack_a->value != smallest_value(data->stack_a))
	{
		if (data->stack_a->next->value == (smallest_value(data->stack_a) + 1))
			swap(data, SA);
		else if (stack_last(data->stack_a)->value == (smallest_value(data->stack_a) + 1))
			reverse_rotate(data, RRA);
	}
	if (stack_is_sorted(data->stack_a) == true)
		return ;
	push(data, PB);
	sort_three(data);
	push(data, PA);
	if (stack_is_sorted(data->stack_a) == false)
		swap(data, SA);
}

void	sort(t_data *data)
{
	if (stack_is_sorted(data->stack_a) == true)
		return ;
	if (data->size_of_a <= 4)
		sort_four(data);
	print_stack(data->stack_a);
}

/*
2 3 4 1 = 1 move
2 1 3 4 = 1 move
1 3 2 4 = 3 moves
1 3 4 2 = 3 moves
1 4 2 3 = 3 moves
1 2 4 3 = 4 moves
1 4 3 2 = 4 moves
3 2 4 1 = 4 moves
3 4 2 1 = 4 moves
4 2 3 1 = 4 moves
3 1 2 4 = 4 moves
3 1 4 2 = 4 moves
4 1 2 3 = 4 moves
2 3 1 4 = 4 moves
2 4 1 3 = 4 moves
3 2 1 4 = 4 moves
2 4 3 1 = 5 moves
4 3 2 1 = 5 moves
4 1 3 2 = 5 moves
2 1 4 3 = 5 moves
4 2 1 3 = 5 moves
3 4 1 2 = 5 moves
4 3 1 2 = 6 moves

*/