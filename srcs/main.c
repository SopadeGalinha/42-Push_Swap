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
	st.fd = STDOUT_FILENO;
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
