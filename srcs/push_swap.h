/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 06:09:57 by jhogonca          #+#    #+#             */
/*   Updated: 2023/07/28 06:09:57 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define FD 1

/*________________________________HEADERS__________________________________*/

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdbool.h>

/*__________________________________STRUCTS________________________________*/

typedef struct s_stack
{
	int				value;
	unsigned int	index;
	unsigned int	reverse;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

typedef struct s_push
{
	bool			error;
	unsigned int	size_of_a;
	unsigned int	size_of_b;
	unsigned int	reference;
	unsigned int	better;
	unsigned int	match;
}	t_push;

enum e_moves
{
	SA,
	SB,
	SS,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR,
	PB,
	PA,
};

/*__________________________________PROTOTYPES_____________________________*/

// INITIALIZATION

t_stack			*ft_lstlast(t_stack *lst);
void			ft_free_split(char **split);
char			**ft_split(char const *s, char c);
void			insert_index(t_stack **stack_a, t_push *st);
void			ft_isdigit(char *str, t_push *st);
void			init_stack(t_stack **stack_a, int ac, char **av, t_push *st);

// UTILS
unsigned int	ft_smallest(t_stack *list);
unsigned int	ft_biggest(t_stack *list);
bool			ft_lstsorted(t_stack *list);
bool			is_on_the_list(t_stack **stack, unsigned int index);
unsigned int	lst_distance(t_stack *stack_a, unsigned int index);
void			ft_printlist(t_stack *stack_a, t_stack *stack_b, t_push *st);

// OPERATIONS
void			push(t_stack **stack_a, t_stack **stack_b, int mv, t_push *st);
void			swap(t_stack **stack_a, t_stack **stack_b, int move);
void			rotate(t_stack **stack_a, t_stack **stack_b, int move);
void			reverse_rotate(t_stack **stack_a, t_stack **stack_b, int move);

// ALGORITHM
void			sort_over_five(t_stack **stacka, t_stack **stackb, t_push *st);
void			sort_under_five(t_stack **stacka, t_stack **stackb, t_push *st);

#endif