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

void	sort(t_data *data)
{
	if (stack_is_sorted(data->stack_a) == true)
		return ;
	if (data->size_of_a <= 4)
		return (sort_four(data));
	push(data, PB);
	push(data, PB);
	while (data->size_of_a > 4)
	{
		set_target(data);
		set_moves(data);
		exec_moves(data);
	}
	sort_four(data);
	while (data->size_of_b > 0)
	{
		set_target(data);
		set_moves(data);
		exec_moves(data);
	}
	while (!stack_is_sorted(data->stack_a))
		reverse_rotate(data, RRA);
}
