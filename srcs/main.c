/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 23:45:59 by jhogonca          #+#    #+#             */
/*   Updated: 2024/05/27 23:45:59 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int end_process(t_data *data, int argc, char **argv, bool error)
{
	if (argc == 2)
		free_array(argv);
	clear(&data->stack_a);
	clear(&data->stack_b);
	if (!error)
		return (EXIT_SUCCESS);
	write(STDERR_FILENO, "Error\n", 6);
	return (EXIT_FAILURE);
}

static void initialization(t_data *data, int argc, char ***argv, bool *error)
{
	int index;
	int current_value;

	index = 0;
	*error = false;

	if (argc == 2)
		*argv = split((*argv)[1], ' ');
	else
		*argv = *argv + 1;

	if (!*argv)
		*error = true;

	while (*argv && (*argv)[index] && !*error)
	{
		current_value = ft_atoi((*argv)[index], error);
		if (*error || push_back(&data->stack_a, current_value))
			*error = true;
		data->size_of_a++;
		index++;
	}
}

int main(int argc, char **argv)
{
	bool error;
	t_data data = {0};

	if (argc < 2)
		return (0);
	initialization(&data, argc, &argv, &error);
	if (!error && data.size_of_a > 1)
	{
		if (data.checker)
			checker(&data);
		else
			sort(&data);
	}
	return (end_process(&data, argc, argv, error));
}
