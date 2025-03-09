/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruiz-d <anruiz-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 18:51:48 by anruiz-d          #+#    #+#             */
/*   Updated: 2025/03/09 13:59:52 by anruiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static	int	ft_sqrt(int	size)
{
	int	res;

	res = 0;
	while (res * res <= size)
		res++;
	res--;
	return (res);
}


int chunk(int size)
{
	return (ft_sqrt(size)*2.5);
}