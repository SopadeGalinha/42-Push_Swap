/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_targets.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 09:11:25 by jhogonca          #+#    #+#             */
/*   Updated: 2024/06/13 09:11:25 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	assign_target(t_stack *this, t_stack *stack, bool is_stack_a)
{
	t_stack	*other;

	other = stack;
	this->target = INT_MAX;
	if (is_stack_a)
		this->target = INT_MIN;
	while (other != NULL)
	{
		if (is_stack_a)
		{
			if (other->value < this->value && other->value > this->target)
				this->target = other->value;
		}
		else
		{
			if (other->value > this->value && other->value < this->target)
				this->target = other->value;
		}
		other = other->next;
	}
	if (is_stack_a && this->target == INT_MIN)
		this->target = biggest_value(stack);
	else if (!is_stack_a && this->target == INT_MAX)
		this->target = smallest_value(stack);
}

void	set_targets(t_data *data)
{
	t_stack	*temporary;

	temporary = data->stack_a;
	while (temporary != NULL)
	{
		assign_target(temporary, data->stack_b, true);
		temporary = temporary->next;
	}
	temporary = data->stack_b;
	while (temporary != NULL)
	{
		assign_target(temporary, data->stack_a, false);
		temporary = temporary->next;
	}
}
