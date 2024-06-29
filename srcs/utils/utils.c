/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 11:42:34 by jhogonca          #+#    #+#             */
/*   Updated: 2024/06/08 11:42:34 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = -1;
	if (!s1 || !s2)
		return (i);
	while (s1[++i] && s2[i])
		if (s1[i] != s2[i])
			break ;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

bool	stack_is_sorted(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp->next)
	{
		if (tmp->value > tmp->next->value)
			return (false);
		tmp = tmp->next;
	}
	return (true);
}

int	smallest_value(t_stack *stack)
{
	t_stack			*tmp;
	int				smallest;

	tmp = stack;
	smallest = tmp->value;
	while (tmp)
	{
		if (tmp->value < smallest)
			smallest = tmp->value;
		tmp = tmp->next;
	}
	return (smallest);
}

int	second_smallest_value(t_stack *stack)
{
	t_stack			*tmp;
	int				smallest;
	int				second_smallest;

	tmp = stack;
	smallest = tmp->value;
	second_smallest = INT_MAX;
	while (tmp)
	{
		if (tmp->value < smallest)
		{
			second_smallest = smallest;
			smallest = tmp->value;
		}
		else if (tmp->value < second_smallest && tmp->value != smallest)
			second_smallest = tmp->value;
		tmp = tmp->next;
	}
	return (second_smallest);
}

int	biggest_value(t_stack *stack)
{
	t_stack			*tmp;
	int				biggest;

	tmp = stack;
	biggest = tmp->value;
	while (tmp)
	{
		if (tmp->value > biggest)
			biggest = tmp->value;
		tmp = tmp->next;
	}
	return (biggest);
}
