/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruiz-d <anruiz-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 11:54:32 by anruiz-d          #+#    #+#             */
/*   Updated: 2025/03/09 20:05:37 by anruiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	print_stack(t_stack *stack)
{
	t_node	*current_node;

	if (!stack || !stack->head)
	{
		ft_printf("stack is empty");
		return ;
	}
	current_node = stack->head;
	while (current_node)
	{
		ft_printf("%d ", current_node->value);
		current_node = current_node->next;
	}
}

static	int	populate_stack(t_stack *stack, int *numbers, int num_count)
{
    int	i;
    t_node	*new_node;
    t_node	*last_node;

    i = -1;
    last_node = NULL;
    while (++i < num_count)
    {
        new_node = init_node(numbers[i]);
        if (!new_node)
            return (1);
        new_node->prev = last_node;
        if (last_node)
            last_node->next = new_node;
        else
            stack->head = new_node;
        last_node = new_node;
        stack->tail = new_node;
        stack->size++;
    }
    return (0);
}

int	main(int argc, char *argv[])
{
	int *numbers;
	int	count;
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc <= 1)
		return (0);
	numbers = handle_numbers(argc, argv);
	if (!numbers)
		return (1);
	stack_a = init_stack('a');
	if (!stack_a)
		return (free(numbers), 1);
	stack_b = init_stack('b');
	if (!stack_b)
		return (free(numbers), free_stack(stack_a), 1);
	count = argc - 1;
	if (populate_stack(stack_a, numbers, count))
		return (free(numbers), free_stack(stack_a), free_stack(stack_b), 1);
	if (stack_a->size == 3)
		stack_of_three(stack_a);
	else if (stack_a->size ==4)
		stack_of_four(stack_a);
	else
		ksort(stack_a, stack_b, count);    
	free(numbers);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
