/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inutils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 08:46:32 by jhogonca          #+#    #+#             */
/*   Updated: 2024/06/08 08:46:32 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	print(int value, int target, int size)
{
	char	*color;

	if (value <= size)
		color = BOLD_BLUE;
	else if (value <= size * 2)
		color = BOLD_GREEN;
	else if (value <= size * 3)
		color = BOLD_YELLOW;
	else
		color = BOLD_RED;
	printf(BOLD_WHITE"V-[%s%3d"BOLD_WHITE"] T-[" \
		BOLD_BLUE"%3d"BOLD_WHITE"]"RESET, \
		color, value, target);
}

void	print_stack(t_data *data)
{
	auto t_stack * temporary_a = data->stack_a;
	auto t_stack * temporary_b = data->stack_b;
	auto int size = (data->size_of_a + data->size_of_b) / 4;
	printf(BOLD_WHITE"    Stack A\t|\tStack B\n"RESET);
	printf(BOLD_WHITE"-----------------------------------\n"RESET);
	while (temporary_a || temporary_b)
	{
		if (temporary_a)
		{
			print(temporary_a->value, temporary_a->target, size);
			temporary_a = temporary_a->next;
		}
		else
			printf("	");
		printf(BOLD_WHITE"\t|  "RESET);
		if (temporary_b)
		{
			print(temporary_b->value, temporary_b->target, size);
			temporary_b = temporary_b->next;
		}
		else
			printf("	");
		printf("\n");
	}
}
