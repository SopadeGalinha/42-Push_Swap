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

static int	ft_strcmp(const char *s1, const char *s2)
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

static bool	auxiliar(t_stack **stk_a, t_stack **stk_b, t_push *st, char *line)
{
	if (ft_strcmp(line, "pa") == 0)
		push(stk_a, stk_b, PA, st);
	else if (ft_strcmp(line, "pb") == 0)
		push(stk_a, stk_b, PB, st);
	else if (ft_strcmp(line, "ra") == 0)
		rotate(stk_a, stk_b, RA, st);
	else if (ft_strcmp(line, "rb") == 0)
		rotate(stk_a, stk_b, RB, st);
	else if (ft_strcmp(line, "rr") == 0)
		rotate(stk_a, stk_b, RR, st);
	else if (ft_strcmp(line, "rra") == 0)
		reverse_rotate(stk_a, stk_b, RRA, st);
	else if (ft_strcmp(line, "rrb") == 0)
		reverse_rotate(stk_a, stk_b, RRB, st);
	else if (ft_strcmp(line, "rrr") == 0)
		reverse_rotate(stk_a, stk_b, RRR, st);
	else
	{
		st->error = true;
		return (false);
	}
	return (true);
}

static void	execute_cmd(t_stack **stack_a, t_stack **stack_b, \
t_push *st, char *line)
{
	if (ft_strcmp(line, "sa") == 0)
		swap(stack_a, stack_b, SA, st);
	else if (ft_strcmp(line, "sb") == 0)
		swap(stack_a, stack_b, SB, st);
	else if (ft_strcmp(line, "ss") == 0)
		swap(stack_a, stack_b, SS, st);
	else
		if (!auxiliar(stack_a, stack_b, st, line))
			st->error = true;
}

static void	read_instructions(t_stack **stack_a, \
t_stack **stack_b, t_push *st)
{
	char	*line;
	int		i;
	char	c;

	i = 0;
	line = NULL;
	while (read(0, &c, 1))
	{
		if (line == NULL)
			line = malloc(sizeof(char) * 4);
		if (c == '\n' || i == 3)
		{
			line[i] = '\0';
			execute_cmd(stack_a, stack_b, st, line);
			if (st->error)
				break ;
			i = 0;
			free(line);
			line = NULL;
		}
		else
			line[i++] = c;
	}
	if (line)
		free(line);
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
	st.checker = true;
	init_stack(&stack_a, ac, av, &st);
	if (!st.error)
		read_instructions(&stack_a, &stack_b, &st);
	if (!st.error)
	{
		if (ft_lstsorted(stack_a) && !st.size_of_b)
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
	}
	ft_clean(&stack_a, &stack_b, &st);
	return (st.error);
}
