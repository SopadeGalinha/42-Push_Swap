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
	t_stack	*this;

	this = data->stack_a;
	while (this != NULL)
	{
		this->target = INT_MIN;
		assign_target(this, data->stack_b, true);
		this = this->next;
	}
	this = data->stack_b;
	while (this != NULL)
	{
		this->target = INT_MAX;
		assign_target(this, data->stack_a, false);
		this = this->next;
	}
}
