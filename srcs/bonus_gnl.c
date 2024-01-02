/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_gnl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 00:07:54 by jhogonca          #+#    #+#             */
/*   Updated: 2024/01/02 00:07:54 by jhogonca         ###   ########.fr       */
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
	static char	buf[FOPEN_MAX][BUFFER_SIZE + 1];

	gnl.line = NULL;
	gnl.size_line = 0;
	gnl.size_buffer = 0;
	while (buf[fd][gnl.size_buffer] && fd >= 0 && fd < FOPEN_MAX)
		gnl.size_buffer++;
	gnl.index = 1;
	while (fd >= 0 && fd < FOPEN_MAX && gnl.index > 0)
	{
		if (!buf[fd][0] || !gnl.size_buffer)
			gnl.size_buffer = read(fd, buf[fd], BUFFER_SIZE);
		gnl.index = gnl.size_buffer;
		if (gnl.size_buffer > 0)
		{
			gnl.size_buffer = 0;
			while (buf[fd][gnl.size_buffer] && buf[fd][gnl.size_buffer] != '\n')
				gnl.size_buffer++;
			gnl.index = (gnl.index == gnl.size_buffer);
			gnl.size_buffer += buf[fd][gnl.size_buffer] == '\n';
			gnl.line = get_line(gnl.line, buf[fd], gnl.size_buffer, &gnl.size_line);
		}
	}
	return (gnl.line);
}