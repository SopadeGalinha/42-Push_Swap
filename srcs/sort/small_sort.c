/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 00:00:38 by jhogonca          #+#    #+#             */
/*   Updated: 2024/06/12 00:00:38 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort_three(t_data *data)
{
	int	first;
	int	middle;
	int	last;

	if (stack_is_sorted(data->stack_a) == true)
		return ;
	if (data->size_of_a == 2)
		return (swap(data, SA));
	first = data->stack_a->value;
	middle = data->stack_a->next->value;
	last = data->stack_a->next->next->value;
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
	if (stack_is_sorted(data->stack_a) == true || data->size_of_a < 4)
		return (sort_three(data));
	if (smallest_value(data->stack_a) == stack_last(data->stack_a)->value)
		reverse_rotate(data, RRA);
	else if (smallest_value(data->stack_a) == data->stack_a->next->value)
		swap(data, SA);
	if (data->stack_a->value != smallest_value(data->stack_a))
	{
		if (data->stack_a->next->value == \
		(second_smallest_value(data->stack_a)))
			swap(data, SA);
		else if (stack_last(data->stack_a)->value == \
			(second_smallest_value(data->stack_a)))
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

void	sort_five(t_data *data)
{
	int	smallest;

	if (stack_is_sorted(data->stack_a) == true || data->size_of_a < 5)
		return (sort_four(data));
	smallest = smallest_value(data->stack_a);
	if (distance_to_top(data->stack_a, smallest) <= data->size_of_a / 2)
	{
		while (data->stack_a->value != smallest)
			rotate(data, RA);
	}
	else
	{
		while (data->stack_a->value != smallest)
			reverse_rotate(data, RRA);
	}
	push(data, PB);
	sort_four(data);
	push(data, PA);
}
