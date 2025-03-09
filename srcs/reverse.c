/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruiz-d <anruiz-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 18:36:12 by anruiz-d          #+#    #+#             */
/*   Updated: 2025/03/08 18:49:42 by anruiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	reverse(t_stack *stack)
{
	int	i;
	int	size;
	if (!stack || !stack->head || !stack->head->next)
		return ;
	size = stack->size;
	i = 0;
	while (i < size - 1)
	{
		rotate(stack);
		i++;
	}
	if (stack->name == 'a')
		ft_printf("rra\n");
	else
		ft_printf("rrb\n");
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	reverse(stack_a);
	reverse(stack_b);
	ft_printf("rrr\n");
}