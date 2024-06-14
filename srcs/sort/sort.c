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
	set_moves(data, moves, true);
}
