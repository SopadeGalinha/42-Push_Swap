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

void	insert_index(t_stack **stack_a, t_push *st)
{
	unsigned int	i;
	t_stack			*head;
	t_stack			*temporary;

	if (st->error == true)
		return ;
	i = 1;
	head = *stack_a;
	while (head)
	{
		temporary = *stack_a;
		while (temporary)
		{
			if (head->value > temporary->value)
				i++;
			temporary = temporary->next;
		}
		head->index = i;
		head = head->next;
		i = 1;
	}
}

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

t_stack	*ft_lstlast(t_stack *lst)
{
	t_stack	*last;

	if (!lst)
		return (NULL);
	last = lst;
	while (last->next)
		last = last->next;
	return (last);
}

void	ft_free_split(char **split)
{
	int	i;

	i = -1;
	while (split[++i])
		free(split[i]);
	free(split);
}
