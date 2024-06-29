/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 11:42:34 by jhogonca          #+#    #+#             */
/*   Updated: 2024/06/08 11:42:34 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	error(char *line)
{
	free(line);
	write(STDERR_FILENO, "Error\n", 6);
	return (EXIT_FAILURE);
}

static int	execute_cmd(t_data *data, char *line)
{
	if (ft_strcmp(line, "sa") == 0)
		swap(data, SA);
	else if (ft_strcmp(line, "sb") == 0)
		swap(data, SB);
	else if (ft_strcmp(line, "ss") == 0)
		swap(data, SS);
	else if (ft_strcmp(line, "pa") == 0)
		push(data, PA);
	else if (ft_strcmp(line, "pb") == 0)
		push(data, PB);
	else if (ft_strcmp(line, "ra") == 0)
		rotate(data, RA);
	else if (ft_strcmp(line, "rb") == 0)
		rotate(data, RB);
	else if (ft_strcmp(line, "rr") == 0)
		rotate(data, RR);
	else if (ft_strcmp(line, "rra") == 0)
		reverse_rotate(data, RRA);
	else if (ft_strcmp(line, "rrb") == 0)
		reverse_rotate(data, RRB);
	else if (ft_strcmp(line, "rrr") == 0)
		reverse_rotate(data, RRR);
	else
		return (error(line));
	return (EXIT_SUCCESS);
}

void	checker(t_data *data)
{
	int		i;
	int		buf;
	char	*line;

	i = 0;
	line = NULL;
	while ((read(0, &buf, 1)))
	{
		if (line == NULL)
			line = malloc(sizeof(char) * 4);
		if (buf == '\n' || i == 3)
		{
			line[i] = '\0';
			if (execute_cmd(data, line) == EXIT_FAILURE)
				break ;
			i = 0;
		}
		else
			line[i++] = buf;
	}
	if (line)
		free(line);
}
