/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 21:52:40 by jhogonca          #+#    #+#             */
/*   Updated: 2024/05/28 21:52:40 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static bool	str_isdigit(const char *str, bool *error)
{
	int	index;

	index = 0;
	if (str[index] == '-' || str[index] == '+')
		index++;
	while (str[index])
	{
		if (str[index] < '0' || str[index] > '9')
		{
			*error = true;
			return (false);
		}
		index++;
	}
	if (index == 0 || (index == 1 && (str[0] == '-' || str[0] == '+')))
	{
		*error = true;
		return (false);
	}
	return (true);
}

int	ft_atoi(const char *str, bool *error)
{
	int		index;
	long	result;
	int		sign;

	index = 0;
	result = 0;
	sign = 1;
	if (*error || !str_isdigit(str, error))
		return (0);
	while (str[index] == ' ' || (str[index] >= 9 && str[index] <= 13))
		index++;
	if (str[index] == '-' || str[index] == '+')
		if (str[index++] == '-')
			sign = -1;
	while (str[index] >= '0' && str[index] <= '9')
	{
		result = result * 10 + (str[index++] - '0');
		if (result * sign > INT_MAX || result * sign < INT_MIN)
		{
			*error = true;
			return (0);
		}
	}
	return (result * sign);
}
