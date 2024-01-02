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
	int				target;
	int				value;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

typedef struct s_push
{
	bool			error;
	int				rotate[6];
	int				size_of_a;
	int				size_of_b;
}	t_push;

enum e_moves
{
	RA,
	RB,
	RRA,
	RRB,
	RR,
	RRR,
	SA,
	SB,
	SS,
	PA,
	PB,
};

/*__________________________________PROTOTYPES_____________________________*/

// INITIALIZATION

t_stack			*ft_lstlast(t_stack *lst);
void			ft_free_split(char **split);
char			**ft_split(char const *s, char c);
void			ft_isdigit(char *str, t_push *st);
void			init_stack(t_stack **stack_a, int ac, char **av, t_push *st);

// UTILS
bool			ft_lstsorted(t_stack *list);
int				ft_biggest(t_stack *list);
int				ft_smallest(t_stack *list);
void			set_target_in_b(t_stack **stk_a, t_stack **stk_b);
void			set_target_in_a(t_stack **stk_a, t_stack **stk_b);

// INUTILS
void			ft_printlist(t_stack *stack_a, t_stack *stack_b, t_push *st);

// OPERATIONS
void			push(t_stack **stack_a, t_stack **stack_b, int mv, t_push *st);
void			swap(t_stack **stack_a, t_stack **stack_b, int move);
void			rotate(t_stack **stack_a, t_stack **stack_b, int move);
void			reverse_rotate(t_stack **stack_a, t_stack **stack_b, int move);

// ALGORITHM
void			sort_list(t_stack **stacka, t_stack **stackb, t_push *st);
void			set_cust(t_stack **stk_a, t_stack **stk_b, t_push *st, int stk);
void			sort_three(t_stack **stacka, t_stack **stackb, t_push *st);

#endif
