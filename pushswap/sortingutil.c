/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortingutil.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:32:41 by fmaqdasi          #+#    #+#             */
/*   Updated: 2023/11/14 18:43:16 by fmaqdasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ra_or_rra(t_Stacks_op *s, int i)
{
	int	*arr;
	int	j;
	int	temp;

	j = s->stacka->top;
	arr = s->stacka->array;
	while (j != -1)
	{
		if (temp < s->stackb->array[i] && arr[j] > s->stackb->array[i])
		{
			if (s->stacka->top + 1 - j > j)
				return (0);
			else
				return (1);
		}
		temp = arr[j];
		j--;
	}
	return (0);
}
