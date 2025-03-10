/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 00:11:20 by jhogonca          #+#    #+#             */
/*   Updated: 2024/05/28 00:11:20 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// Libraries
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>

// Macros
# define DEBUG 0
# define INITIAL_VALUE 55555

// Constants
# define VALUE 1
# define TARGET 0

// Colors
# define BOLD "\033[1m"
# define BOLD_RED "\033[1;31m"
# define BOLD_BLUE "\033[1;34m"
# define BOLD_GREEN "\033[1;32m"
# define BOLD_YELLOW "\033[1;33m"
# define BOLD_WHITE "\033[1;37m"
# define RESET "\033[0m"

/**
 * Structure for the stack.
 *
 * @param value - The value of the node.
 * @param target - The target value of the node.
 * @param next - Pointer to the next node.
	* @example: [1]->[2]->[3]->[5]->[4]
* @param prev - Pointer to the previous node.
	* @example: [1]<-[2]<-[3]<-[5]<-[4]
	[1]<->[2]<->[3]<->[5]<->[4]
*/
typedef struct s_stack
{
	int				value;
	int				target;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

/**
 * Structure for the data.
 *
 * @param stack_a - Pointer to the stack A.
 * @param stack_b - Pointer to the stack B.
 * @param size_of_a - The size of the stack A.
 * @param size_of_b - The size of the stack B.
*/
typedef struct s_data
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	bool		checker;
	int			size_of_a;
	int			size_of_b;
}	t_data;

/**
 * Structure for the operations.
 *  @param SA: Swap the first two elements at the top of stack A.
 *  @param SB: Swap the first two elements at the top of stack B.
 *  @param SS: SA and SB at the same time.
 *  @param PA: Take the first element at the top of B and put it at the top of A.
 *  @param PB: Take the first element at the top of A and put it at the top of B.
 *  @param RA: Shift up all elements of stack A by 1. 
 *		The first element becomes the last one.
*  @param RB: Shift up all elements of stack B by 1.
* 			The first element becomes the last one.
* @param RRA: Shift down all elements of stack A by 1.
* 			The last element becomes the first one.
* @param RRB: Shift down all elements of stack B by 1.
* 			The last element becomes the first one.
*  @param RR: RA and RB at the same time.
* @param RRR: RRA and RRB at the same time.
*/
enum e_operations
{
	RA,
	RB,
	RRA,
	RRB,
	RR,
	RRR,
	SA,
	SB,
	PA,
	PB,
	SS
};

// ----------------------> Sort <--------------------------

/**
 * Sorts the stack.
 *
 * @param data: The data structure.
*/
void	sort(t_data *data);

/**
 * @brief Sorts a stack with 5 elements
 * 
 * @param data The data structure
*/
void	sort_five(t_data *data);

/**
 * Sets the target value for both stacks.
 * The target value is the closest value in the other stack.
 * 
 * @param data The structure that contains the stacks.
 * @note The target value for stack A is the closest value in stack B
 * that is smaller than the current value.
 * @note The target value for stack B is the closest value in stack A
 * that is bigger than the current value.
 * @note The target value is assigned to the target field of the stack.
 * @note If there is no smaller value in stack B for stack A, it means that
 * the current value is the smallest value in stack A, so the target value
 * is assigned to the biggest value in stack B.
 * @note If there is no bigger value in stack A for stack B, it means that
 * the current value is the biggest value in stack B, so the target value
 * is assigned to the smallest value in stack A.
 */
void	set_targets(t_data *data);

/**
 * Returns the distance to the top of the stack.
 * 
 * @param stack The stack.
 * @param reference The reference value.
 * @return The distance to the top of the stack.
 * @note The distance is calculated by counting the number of moves
 * needed to reach the reference value.
 */
int		distance_to_top(t_stack *stack, int reference);

/**
 * Sets the moves to be executed.
 * 
 * @param data The data structure.
 * @param moves The array of moves.
 * @param fistPart If true, the moves are calculated for the 
 * first part of the sort. 
*/
void	set_moves(t_data *data, int *moves, bool fistPart);

// -------------------> Operations <------------------------

/**
 * Swap the first two elements at the top of the stack.
 *
 * @param stack: Pointer to the pointer of the stack.
 * @param move: The move to be executed.
 * @note SA: Swap the first two elements at the top of stack A.
 * @note SB: Swap the first two elements at the top of stack B.
 * @note SS: SA and SB at the same time.
*/
void	swap(t_data *data, int move);

/**
 * Take the first element at the top of B and put it at the top of A.
 * 
 * @param data: The data structure.
 * @param move: The move to be executed.
 * @note PA: Take the first element at the top of B and put it at the top of A.
 * @note PB: Take the first element at the top of A and put it at the top of B.
 * @note The size of the stack B must be greater than 0.
*/
void	push(t_data *data, int move);

/**
 * Shift up all elements of the stack by 1.
 * The first element becomes the last one.
 *
 * @param stack: Pointer to the pointer of the stack.
 * @param move: The move to be executed.
 * @note RA: Shift up all elements of stack A by 1.
 * @note RB: Shift up all elements of stack B by 1.
 * @note RR: RA and RB at the same time.
*/
void	rotate(t_data *data, int move);

/**
 * Shift down all elements of the stack by 1.
 * The last element becomes the first one.
 *
 * @param stack: Pointer to the pointer of the stack.
 * @param move: The move to be executed.
 * @note RRA: Shift down all elements of stack A by 1.
 * @note RRB: Shift down all elements of stack B by 1.
 * @note RRR: RRA and RRB at the same time.
*/
void	reverse_rotate(t_data *data, int move);

// ----------------------> Utils <---------------------------

/**
 * Converts a string to an integer.
 *
 * @param str: The string to be converted.
 * @param error: Pointer to a boolean that will 
 * 	be set to true if an error occurs.
 * @return The integer value of the string.
 * 
*/
int		ft_atoi(const char *str, bool *error);

/**
 * Split a string into an array of strings using a delimiter.
 *
 * @param str: The string to be split.
 * @param delimiter: The delimiter used to split the string.
 * @return An array of strings.
 * @note The array must be freed using the free_array function.
 * @see free_array
 */
char	**split(const char *str, char delimiter);

/**
 * Frees an array of strings.
 * @param array: The array of strings to be freed.
 */
void	free_array(char **array);

/**
 * Adds a new node with the specified value to the end of the stack.
 *
 * @param stack: Pointer to the pointer of the stack.
 * @param value: The value to be added to the stack.
 * @return true if the node was successfully added, false otherwise.
 */
bool	push_back(t_stack **stack, int value);

/**
 * Frees the memory allocated for the stack.
 *
 * @param stack: Pointer to the pointer of the stack.
 */
void	clear(t_stack **stack);

/**
 * Checks if the stack is sorted.
 *
 * @param stack: The stack.
 * @return true if the stack is sorted, false otherwise.
 */
bool	stack_is_sorted(t_stack *stack);

/**
 * Returns the smallest value of the stack.
 *
 * @param stack: The stack.
 * @return The smallest value of the stack.
 */
int		smallest_value(t_stack *stack);

/**
 * Returns the second smallest value of the stack.
 *
 * @param stack: The stack.
 * @return The second smallest value of the stack.
 */
int		second_smallest_value(t_stack *stack);

/**
 * Returns the biggest value of the stack.
 *
 * @param stack: The stack.
 * @return The biggest value of the stack.
 */
int		biggest_value(t_stack *stack);

// ---------------------> data->checker <--------------------------

/**
* @brief This function reads the commands from the 
* standard input and executes them one by one until 
* the end of the input or an error occurs.
*
* @param data The data structure.:
*   - data: a pointer to the data structure 
*/
void	checker(t_data *data);

/**
 * Compares two strings.
 *
 * @param s1: The first string.
 * @param s2: The second string.
 * @return The difference between the first different characters.
 */
int		ft_strcmp(const char *s1, const char *s2);

// ---------------------> Debug <--------------------------

/** 
 * Prints the stack. (For debugging purposes)
 *
 * @param data: The data structure.
 * @note The stack is printed in the following format:
 * 	1. The stack name.
 * 	2. The values of the stack.
 * 	3. The target values of the stack.
 * 
*/
void	print_stack(t_data *data);

#endif
