/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inutils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 00:53:49 by jhogonca          #+#    #+#             */
/*   Updated: 2023/12/31 00:53:49 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_print_a(t_stack *temporary_a, int size)
{
	if (temporary_a)
	{
		if (temporary_a->value < size)
			printf("\033[0;34m%9u\033[0m - [%u]", temporary_a->value, temporary_a->target);
		else if (temporary_a->value < size * 2)
			printf("\033[0;32m%8u\033[0m - [%u]" , temporary_a->value, temporary_a->target);
		else if (temporary_a->value < size * 3)
			printf("\033[0;33m%8u\033[0m - [%u]" , temporary_a->value, temporary_a->target);
		else
			printf("\033[0;31m%8u\033[0m - [%u]" , temporary_a->value, temporary_a->target);
	}
	else
		printf(" %9c  ", ' ');
}

//PRINT THE ELEMENTS OF LIST B
static void	ft_print_b(t_stack *temporary_b, int size)
{
	if (temporary_b != NULL)
	{
		if (temporary_b->value < size)
			printf("\033[0;34m%8u\033[0m", temporary_b->value);
		else if (temporary_b->value < size * 2)
			printf("\033[0;32m%8u\033[0m", temporary_b->value);
		else if (temporary_b->value < size * 3)
			printf("\033[0;33m%8u\033[0m", temporary_b->value);
		else
			printf("\033[0;31m%8u\033[0m", temporary_b->value);
	}
}

//PRINT THE ELEMENTS OF THE LISTS
void	ft_printlist(t_stack *stack_a, t_stack *stack_b, t_push *st)
{
	int					size;
	t_stack				*temporary_a;
	t_stack				*temporary_b;

	temporary_a = stack_a;
	temporary_b = stack_b;
	size = (st->size_of_a + st->size_of_b) / 4;
	printf("_______________________________________\n");
	printf("	Stack A		|    Stack B");
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