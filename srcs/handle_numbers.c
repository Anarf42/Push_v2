/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_numbers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruiz-d <anruiz-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 16:45:36 by anruiz-d          #+#    #+#             */
/*   Updated: 2025/03/08 21:42:53 by anruiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static	int	is_not_duplicate(int *numbers, int max_pos, int	n)
{
	int	i;

	i = 0;
	while (i < max_pos)
	{
		if (numbers[i] == n)
			return (0);
		i++;
	}
	return (1);
}

int	*handle_numbers(int argc, char **argv)
{
	int	*numbers;
	int	tmp;
	int	size;
	int	i;

	size = argc - 1;
	numbers = malloc(sizeof(int) * size);
	if (!numbers)
		return (NULL);
	i = 0;
	while (i < size)
	{
		tmp = ft_atoi(argv[i + 1]);
		if (is_not_duplicate(numbers, i, tmp))
			numbers[i] = tmp;
		else
		{
			free(numbers);
			ft_printf("Error: has a duplicate number");
			return (0);
		}
		i++;
	}
	return (numbers);
}
