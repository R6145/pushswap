/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 12:35:48 by fmaqdasi          #+#    #+#             */
/*   Updated: 2023/08/29 14:34:00 by fmaqdasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	find_largest_when(t_Stack	*s1)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i <= s1->top)
	{
		if (s1->array[i] > s1->array[j])
		{
			j = i;
		}
		i++;
	}
	return (j);
}

int	find_smallest_when(t_Stack	*s1)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i <= s1->top)
	{
		if (s1->array[i] < s1->array[j])
		{
			j = i;
		}
		i++;
	}
	return (j);
}