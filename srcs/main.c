/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 06:09:18 by jhogonca          #+#    #+#             */
/*   Updated: 2023/07/28 06:09:18 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	{
		if (st.size_of_a > 3)
			sort_list(&stack_a, &stack_b, &st);
		sort_three(&stack_a, &stack_b, &st);
	}
	ft_clean(&stack_a, &stack_b, &st);
	if (st.error)
		return (1);
	return (0);
}
