/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 17:28:53 by jhogonca          #+#    #+#             */
/*   Updated: 2023/07/28 17:28:53 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_isdigit(char *str, t_push *st)
{
	int	i;

	if (st->error == true)
		return ;
	i = 0;
	if ((str[i] == '-' || str[i] == '+')
		&& (str[i + 1] != '\0' && str[i + 1] != ' '))
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			st->error = true;
		i++;
	}
}

void	ft_free_split(char **split)
{
	int	i;

	i = -1;
	while (split[++i])
		free(split[i]);
	free(split);
}

void	set_target_in_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temporary_a;
	t_stack	*temporary_b;

	temporary_a = *stack_a;
	while (temporary_a != NULL)
	{
		temporary_b = *stack_b;
		temporary_a->target = INT_MIN;
		while (temporary_b != NULL)
		{
			if (temporary_b->value < temporary_a->value
				&& temporary_b->value > temporary_a->target)
			{
				temporary_a->target = temporary_b->value;
			}
			temporary_b = temporary_b->next;
		}
		if (temporary_a->target == INT_MIN)
			temporary_a->target = ft_biggest(*stack_b);
		temporary_a = temporary_a->next;
	}
}

void	set_target_in_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temporary_a;
	t_stack	*temporary_b;

	temporary_b = *stack_b;
	while (temporary_b != NULL)
	{
		temporary_a = *stack_a;
		temporary_b->target = INT_MAX;
		while (temporary_a != NULL)
		{
			if (temporary_a->value > temporary_b->value
				&& temporary_a->value < temporary_b->target)
			{
				temporary_b->target = temporary_a->value;
			}
			temporary_a = temporary_a->next;
		}
		if (temporary_b->target == INT_MAX)
			temporary_b->target = ft_smallest(*stack_a);
		temporary_b = temporary_b->next;
	}
}

void	ft_clean(t_stack **stack_a, t_stack **stack_b, t_push *st)
{
	t_stack	*tmp;

	while (*stack_a)
	{
		tmp = *stack_a;
		*stack_a = (*stack_a)->next;
		free(tmp);
	}
	while (*stack_b)
	{
		tmp = *stack_b;
		*stack_b = (*stack_b)->next;
		free(tmp);
	}
	if (st->error == true)
		write(2, "Error\n", 6);
}
