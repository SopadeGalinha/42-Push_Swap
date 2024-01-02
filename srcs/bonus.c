/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 10:55:06 by jhogonca          #+#    #+#             */
/*   Updated: 2024/01/02 10:55:06 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	auxiliar(t_stack **stack_a, t_stack **stack_b, t_push *st, char *line)
{
	if (ft_strcmp(line, "pa\n") == 0)
		push(stack_a, stack_b, PA, st);
	else if (ft_strcmp(line, "pb\n") == 0)
		push(stack_a, stack_b, PB, st);
	else if (ft_strcmp(line, "ra\n") == 0)
		rotate(stack_a, stack_b, RA, st);
	else if (ft_strcmp(line, "rb\n") == 0)
		rotate(stack_a, stack_b, RB, st);
	else if (ft_strcmp(line, "rr\n") == 0)
		rotate(stack_a, stack_b, RR, st);
	else if (ft_strcmp(line, "rra\n") == 0)
		reverse_rotate(stack_a, stack_b, RRA, st);
	else if (ft_strcmp(line, "rrb\n") == 0)
		reverse_rotate(stack_a, stack_b, RRB, st);
	else if (ft_strcmp(line, "rrr\n") == 0)
		reverse_rotate(stack_a, stack_b, RRR, st);
	else
	{
		st->error = true;
		free(line);
		return (false);
	}
	return (true);
}

void	read_instructions(t_stack **stack_a, t_stack **stack_b, t_push *st)
{
	char	*line;

	line = NULL;
	while (true)
	{
		free(line);
		line = get_next_line(0);
		if (!line)
			break ;
		if (line[0] == '\0')
			continue ;
		if (ft_strcmp(line, "sa\n") == 0)
			swap(stack_a, stack_b, SA, st);
		else if (ft_strcmp(line, "sb\n") == 0)
			swap(stack_a, stack_b, SB, st);
		else if (ft_strcmp(line, "ss\n") == 0)
			swap(stack_a, stack_b, SS, st);
		else
			if (!auxiliar(stack_a, stack_b, st, line))
				break ;
	}
}
