/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 21:37:47 by jhogonca          #+#    #+#             */
/*   Updated: 2024/05/28 21:37:47 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	count_words(const char *s, char delimiter)
{
	int	index;
	int	words_counter;

	index = 0;
	words_counter = 0;
	while (s[index])
	{
		if ((index == 0 && s[index] != delimiter) || \
		(s[index] != delimiter && s[index - 1] == delimiter))
			words_counter++;
		index++;
	}
	return (words_counter);
}

static int	get_word_length(const char *str, char delimiter)
{
	int	index;

	index = 0;
	while (str[index] && str[index] != delimiter)
		index++;
	return (index);
}

static char	*copy_word(const char *str, char delimiter)
{
	char	*word;
	int		i;

	word = malloc(sizeof(char *) * (get_word_length(str, delimiter) + 1));
	if (word == NULL)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != delimiter)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**split(const char *str, char delimiter)
{
	char	**result;
	int		pos;
	int		index;

	pos = count_words(str, delimiter);
	if (pos == 0)
		return (NULL);
	result = malloc(sizeof(char *) * (pos + 1));
	if (result == NULL)
		return (NULL);
	pos = 0;
	index = 0;
	while (str[pos])
	{
		if (str[pos] == delimiter)
			pos++;
		else
		{
			result[index] = copy_word(&str[pos], delimiter);
			index++;
			pos += get_word_length(&str[pos], delimiter);
		}
	}
	result[index] = NULL;
	return (result);
}
