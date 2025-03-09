/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruiz-d <anruiz-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:00:39 by anruiz-d          #+#    #+#             */
/*   Updated: 2025/03/09 12:28:02 by anruiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/include/libft.h"
#include <limits.h>

typedef	struct s_node 
{
	int	value;				// value of the node
	int	index;				// to determine the position of the node
	int	s_index;			// sorted index
	int	pos_in_stack;
	struct	s_node *next;
	struct	s_node *prev;

}	t_node;

//	structure for a stack

typedef	struct	s_stack
{
	char	name;	// the name will be 'a' or 'b' depending on the stack 
	t_node	*head;	// pointer to the top
	t_node	*tail;	// pointer to the end
	int		size;	// number of elements
}	t_stack;

/* Parse arguments */
int	parse_arguments(int argc, char **argv, int **numbers, int *num_count);

/* utils parse arguments */
void	free_split(char	**result);
int	validate_number(char *argv, int *numbers);






/* -- new files -- */

/* -- index_assign.c -- */
void	assign_sorted_index(t_stack *stack_a, int *sorted_numbers, int count);
void	selection_sort_ints(int	*str, int size);
void	index_stack(t_stack *stack, int size);
int		find_pos_index_stack(t_stack *stack, int target_index);

/* -- init_and_free -- */
void	free_stack(t_stack *stack);
t_stack	*init_stack(char name_stack);
t_node	*init_node(int value);

/* -- handle_numbers -- */
int		*handle_numbers(int argc, char **argv);

/* -- swap -> sa, sb and ss -- */
void	swap(t_stack *stack);
void	ss(t_stack *stack_a, t_stack *stack_b);

/* -- push -> pa and pb -- */
void	push(t_stack *dst, t_stack *src);

/* -- rotate -> ra, rb and rr -- */
void	rotate(t_stack *stack);
void	rr(t_stack *stack_a, t_stack *stack_b);

/* -- reverse -> rra, rrb and rrr -- */
void	reverse(t_stack *stack);
void	rrr(t_stack *stack_a, t_stack *stack_b);

/* -- utils -> chunk -- */
int		chunk(int size);

/* -- ksort -> ksort1 and ksort2 */
void	ksort(t_stack *a, t_stack *b, int size);
void	ksort_1(t_stack *a, t_stack *b, int size);
void	ksort_2(t_stack *a, t_stack *b, int size);

/*  push_swap */
int	main(int argc, char *argv[]);

#endif