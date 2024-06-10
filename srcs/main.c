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

static void	end_process(t_data *data, int argc, char **argv, bool error)
{
	if (argc == 2)
		free_array(argv);
	clear(&data->stack_a);
	clear(&data->stack_b);
	if (error == false)
		exit(EXIT_SUCCESS);
	write(STDERR_FILENO, "Error\n", 6);
	exit(EXIT_FAILURE);
}

static bool	initialization(t_data *data, int argc, char ***argv)
{
	int		index;
	bool	error;

	index = -1;
	error = false;
	if (argc == 2)
		*argv = split((*argv)[1], ' ');
	else
		*argv = *argv + 1;
	if (!*argv)
		return (true);
	while ((*argv)[++index])
	{
		if (push_back(&data->stack_a, ft_atoi((*argv)[index], &error)))
			return (true);
		data->size_of_a++;
	}
	return (error);
}

int	main(int argc, char **argv)
{
	bool	error;
	t_data	data;

	data = (t_data){0};
	if (argc < 2)
		return (0);
	error = initialization(&data, argc, &argv);
	if (error == false)
		sort(&data);
	end_process(&data, argc, argv, error);
}
