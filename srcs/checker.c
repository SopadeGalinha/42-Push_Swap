/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 00:14:24 by jhogonca          #+#    #+#             */
/*   Updated: 2024/01/02 00:14:24 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*get_line(char *line, char *buffer, long size_buffer, long *sz_line)
{
	t_gnl	gnl;

	gnl.size_line = -1;
	gnl.index = -1;
	gnl.size_buffer = -1;
	gnl.line = line;
	*sz_line += size_buffer;
	line = malloc(*sz_line + 1 * sizeof(char));
	if (line)
	{
		line[*sz_line] = 0;
		while (gnl.line && gnl.line[++gnl.size_line])
			line[++gnl.index] = gnl.line[gnl.size_line];
		gnl.size_line = -1;
		while (buffer && buffer[++gnl.size_line])
		{
			if (gnl.size_line < size_buffer)
				line[++gnl.index] = buffer[gnl.size_line];
			else
				buffer[++gnl.size_buffer] = buffer[gnl.size_line];
			buffer[gnl.size_line] = 0;
		}
	}
	free(gnl.line);
	return (line);
}

char	*get_next_line(int fd)
{
	t_gnl		gnl;
	static char	buf[BUFFER_SIZE + 1];

	gnl.line = NULL;
	gnl.size_line = 0;
	gnl.size_buffer = 0;
	while (buf[gnl.size_buffer] && fd >= 0 && fd)
		gnl.size_buffer++;
	gnl.index = 1;
	while (fd >= 0 && gnl.index > 0)
	{
		if (!buf[0] || !gnl.size_buffer)
			gnl.size_buffer = read(fd, buf, BUFFER_SIZE);
		gnl.index = gnl.size_buffer;
		if (gnl.size_buffer > 0)
		{
			gnl.size_buffer = 0;
			while (buf[gnl.size_buffer] && buf[gnl.size_buffer] != '\n')
				gnl.size_buffer++;
			gnl.index = (gnl.index == gnl.size_buffer);
			gnl.size_buffer += buf[gnl.size_buffer] == '\n';
			gnl.line = get_line(gnl.line, buf, gnl.size_buffer, &gnl.size_line);
		}
	}
	return (gnl.line);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = -1;
	if (!s1 || !s2)
		return (i);
	while (s1[++i] && s2[i])
		if (s1[i] != s2[i])
			break ;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
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
	st.fd = -1;
	init_stack(&stack_a, ac, av, &st);
	if (st.error == false)
		read_instructions(&stack_a, &stack_b, &st);
	if (!st.error)
	{
		if (ft_lstsorted(stack_a) && !st.size_of_b)
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
	}
	ft_clean(&stack_a, &stack_b, &st);
	if (st.error)
		return (1);
	return (0);
}
