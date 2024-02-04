/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 06:53:00 by jhogonca          #+#    #+#             */
/*   Updated: 2023/07/28 06:53:00 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*ft_lstnew(int value);
static int		ft_atoi(char *str, t_push *st);
static void		ft_lstadd_back(t_stack **stack, int content, t_push *st);
static void		check_duplicates(t_stack *stack_a, t_push *st, int content);

void	init_stack(t_stack **stack_a, int ac, char **av, t_push *st)
{
	int	i;
	int	content;

	i = 0;
	if (ac == 2)
	{
		av = ft_split(av[1], ' ');
		if (!*av)
			st->error = true;
		i = -1;
	}
	while (av[++i] && st->error == false)
	{
		ft_isdigit(av[i], st);
		content = ft_atoi(av[i], st);
		if (st->error == true)
			break ;
		ft_lstadd_back(stack_a, content, st);
		check_duplicates(*stack_a, st, content);
	}
	if (ac == 2)
		ft_free_split(av);
}

static t_stack	*ft_lstnew(int value)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (new)
	{
		new->value = value;
		new->next = NULL;
		new->prev = NULL;
	}
	return (new);
}

static void	ft_lstadd_back(t_stack **stack, int content, t_push *st)
{
	t_stack	*last;
	t_stack	*new;

	if (!stack)
		st->error = true;
	if (st->error == true)
		return ;
	new = ft_lstnew(content);
	if (!new)
	{
		st->error = true;
		return ;
	}
	st->size_of_a++;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	last = ft_lstlast(*stack);
	new->prev = last;
	last->next = new;
}

static int	ft_atoi(char *str, t_push *st)
{
	int		sign;
	int		i;
	long	nbr;

	sign = 1;
	i = 0;
	nbr = 0;
	if (st->error == true)
		return (0);
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			sign = -1;
	}
	while (str[i] && st->error == false)
	{
		nbr = nbr * 10 + (str[i++] - '0');
		if (nbr < 0)
			st->error = true;
	}
	return (nbr * sign);
}

static void	check_duplicates(t_stack *stack_a, t_push *st, int content)
{
	t_stack	*tmp;

	tmp = stack_a;
	while (tmp->next)
	{
		if (tmp->value == content)
			st->error = true;
		tmp = tmp->next;
	}
}
