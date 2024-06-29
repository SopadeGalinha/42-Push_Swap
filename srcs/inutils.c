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

static void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

static void	ft_putnbr(int n)
{
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
		write(1, &"0123456789"[n], 1);
}

static void	ft_putalignednbr(int n)
{
	if (n < 10 && n >= 0)
		write(1, "  ", 2);
	else if (n < 100 && n >= 0)
		write(1, " ", 1);
	else if (n < 0 && n > -10)
		write(1, " ", 1);
	ft_putnbr(n);
}

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
	ft_putstr(BOLD_WHITE "V-[");
	ft_putstr(color);
	ft_putalignednbr(value);
	ft_putstr(BOLD_WHITE "] T-[");
	ft_putstr(BOLD_BLUE);
	ft_putalignednbr(target);
	ft_putstr(BOLD_WHITE "]" RESET);
}

void	print_stack(t_data *data)
{
	auto t_stack * temporary_a = data->stack_a;
	auto t_stack * temporary_b = data->stack_b;
	auto int size = (data->size_of_a + data->size_of_b) / 4;
	ft_putstr(BOLD_WHITE "    Stack A\t|\tStack B\n" RESET);
	ft_putstr(BOLD_WHITE "-----------------------------------\n" RESET);
	while (temporary_a || temporary_b)
	{
		if (temporary_a)
		{
			print(temporary_a->value, temporary_a->target, size);
			temporary_a = temporary_a->next;
		}
		else
			ft_putstr("        ");
		ft_putstr(BOLD_WHITE "\t|  " RESET);
		if (temporary_b)
		{
			print(temporary_b->value, temporary_b->target, size);
			temporary_b = temporary_b->next;
		}
		else
			ft_putstr("        ");
		ft_putstr("\n");
	}
}
