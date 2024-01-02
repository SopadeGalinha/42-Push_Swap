/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 00:14:24 by jhogonca          #+#    #+#             */
/*   Updated: 2024/01/02 00:14:24 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// bonus part

static void	ft_clean(t_stack **stack_a, t_stack **stack_b, t_push *st)
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
	get_next_line(-1);
}

void	read_instructions(t_stack **stack_a, t_stack **stack_b, t_push *st)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (strcmp(line, "sa") == 0)
			swap(stack_a, stack_b, SA);
		if (strcmp(line, "sb") == 0)
			swap(stack_b, stack_a, SB);
		if (strcmp(line, "ss") == 0)
			swap(stack_a, stack_b, SS);
		if (strcmp(line, "pa") == 0)
			push(stack_b, stack_a, PA, st);
		if (strcmp(line, "pb") == 0)
			push(stack_a, stack_b, PB, st);
		if (strcmp(line, "ra") == 0)
			rotate(stack_a, stack_b, RA);
		if (strcmp(line, "rb") == 0)
			rotate(stack_b, stack_a, RB);
		if (strcmp(line, "rr") == 0)
			rotate(stack_a, stack_b, RR);
		if (strcmp(line, "rra") == 0)
			reverse_rotate(stack_a, stack_b, RRA);
		if (strcmp(line, "rrb") == 0)
			reverse_rotate(stack_b, stack_a, RRB);
		if (strcmp(line, "rrr") == 0)
			reverse_rotate(stack_a, stack_b, RRR);
		else
			st->error = true;
		free(line);
	}
	if (st->error == true)
		return ;
	if (ft_lstsorted(*stack_a) && !*stack_b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_push	st;

	if (ac < 2)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	st = (t_push){0};
	init_stack(&stack_a, ac, av, &st);
	if (st.error == false)
		read_instructions(&stack_a, &stack_b, &st);
	ft_clean(&stack_a, &stack_b, &st);
	if (st.error)
		return (1);
	return (0);
}
