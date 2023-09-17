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

static void	sort_stack(t_stack **stack_a, t_stack **stack_b, t_push *st)
{
	if (ft_lstsorted(*stack_a))
		return ;
	if (st->size_of_a < 6)
		sort_under_five(stack_a, stack_b, st);
	else
		sort_over_five(stack_a, stack_b, st);
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
		sort_stack(&stack_a, &stack_b, &st);
	ft_clean(&stack_a, &stack_b, &st);
	return (0);
}

/*
static void	ft_print_a(t_stack *temporary_a, unsigned int size)
{
	if (temporary_a)
	{
		if (temporary_a->index < size)
			printf("\033[0;34m%9u\033[0m", temporary_a->index);
		else if (temporary_a->index < size * 2)
			printf("\033[0;32m%9u\033[0m", temporary_a->index);
		else if (temporary_a->index < size * 3)
			printf("\033[0;33m%9u\033[0m", temporary_a->index);
		else
			printf("\033[0;31m%9u\033[0m", temporary_a->index);
	}
	else
		printf(" %9c  ", ' ');
}

//PRINT THE ELEMENTS OF LIST B
static void	ft_print_b(t_stack *temporary_b, unsigned int size)
{
	if (temporary_b != NULL)
	{
		if (temporary_b->index < size)
			printf("\033[0;34m%11u\033[0m", temporary_b->index);
		else if (temporary_b->index < size * 2)
			printf("\033[0;32m%11u\033[0m", temporary_b->index);
		else if (temporary_b->index < size * 3)
			printf("\033[0;33m%11u\033[0m", temporary_b->index);
		else
			printf("\033[0;31m%11u\033[0m", temporary_b->index);
	}
}

//PRINT THE ELEMENTS OF THE LISTS
void	ft_printlist(t_stack *stack_a, t_stack *stack_b, t_push *st)
{
	unsigned int		size;
	t_stack				*temporary_a;
	t_stack				*temporary_b;

	temporary_a = stack_a;
	temporary_b = stack_b;
	size = (st->size_of_a + st->size_of_b) / 4;
	printf("_____________________________________\n");
	printf("    Stack A	|        Stack B");
	while (temporary_a != NULL || temporary_b != NULL)
	{
		printf("\n");
		ft_print_a(temporary_a, size);
		printf(" 	|  ");
		ft_print_b(temporary_b, size);
		if (temporary_b != NULL)
			temporary_b = temporary_b->next;
		if (temporary_a != NULL)
			temporary_a = temporary_a->next;
	}
	printf("\n_____________________________________\n");
	if (ft_lstsorted(stack_a))
		printf("\033[0;36m\nSORTED\n\033[0m");
	else
		printf("\033[0;35m\nNOT SORTED\n\033[0m");
}

*/