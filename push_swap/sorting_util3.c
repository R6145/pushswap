/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_util3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 01:55:19 by fmaqdasi          #+#    #+#             */
/*   Updated: 2023/12/03 17:23:51 by fmaqdasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	coststack(t_Stacks_op *s, int i)
{
	int	*arr;
	int	j;
	int	temp;

	j = s->stacka->top;
	arr = s->stacka->array;
	if (s->stackb->array[i] > arr[s->stacka->maxnum])
		return (exct2(s, s->stacka->maxnum, 3));
	if (s->stackb->array[i] < arr[s->stacka->minnum])
		return (exct2(s, s->stacka->minnum, 2));
	if (arr[0] < s->stackb->array[i]
		&& arr[s->stacka->top] > s->stackb->array[i])
		return (exct2(s, s->stacka->top, 2));
	while (j >= 0)
	{
		temp = arr[j];
		if (temp < s->stackb->array[i] && arr[j - 1] > s->stackb->array[i])
			return (exct2(s, j, 1));
		j--;
	}
	return (0);
}

int	exct2(t_Stacks_op *s, int j, int x)
{
	int	i;

	i = 0;
	if (x == 1)
		i++;
	if (x == 2)
	{
		if (s->stacka->array[s->stacka->minnum] == s->stacka->top
			&& s->stacka->minnum == j)
			return (1);
		if ((s->stacka->top + 1) / 2 > j)
			return (j + 1);
		return (s->stacka->top - j);
	}
	if (x == 3)
	{
		if (s->stacka->array[s->stacka->maxnum] == 0 && s->stacka->maxnum == j)
			return (1);
		if ((s->stacka->top + 1) / 2 > j)
			return (j);
		return (s->stacka->top - j + 1);
	}
	if ((s->stacka->top + 1) / 2 > j)
		return (j);
	return (s->stacka->top - j + i);
}
