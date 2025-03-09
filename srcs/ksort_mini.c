/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksort_mini.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruiz-d <anruiz-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 19:14:14 by anruiz-d          #+#    #+#             */
/*   Updated: 2025/03/09 20:33:27 by anruiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	stack_of_three(t_stack *stack)
{
	if (stack->head->value > stack->head->next->value 
			&& stack->head->value < stack->head->next->next->value)
		swap(stack);
	else if (stack->head->value > stack->head->next->value 
			&& stack->head->value > stack->head->next->next->value)
		rotate(stack);
}

void stack_of_four(t_stack *stack)
{
	pb(stack);
	stack_of_three(stack);
	if 
}