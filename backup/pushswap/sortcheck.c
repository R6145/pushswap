/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortcheck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 16:05:09 by fmaqdasi          #+#    #+#             */
/*   Updated: 2023/11/19 16:31:34 by fmaqdasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	costcomp(t_Stacks_op *s)
{
	int	*arr2;
	int	i;
	int	temp;

	arr2 = (int *)malloc(sizeof(int) * (s->stackb->max_size + 1));
	i = s->stackb->top;
	while (i > -1)
	{
		arr2[i] = counterstack(s, i);
		i--;
	}
	// s->samesize = samesize(s, arr2);
	i = s->stackb->top;
	temp = i;
	i--;
	while (i >= 0)
	{
		if (arr2[temp] > arr2[i])
			temp = i;
		i--;
	}
	free(arr2);
	return (temp);
}

int	countbetween(t_Stacks_op *s, int j)
{
	if ((s->stacka->top + 1) / 2 > j)
		return ((s->stacka->top - j) * 2);
	return (j);
}

int	counterstack(t_Stacks_op *s, int i)
{
	int	luckilest;
	int	*arr;
	int	j;
	int	temp;

	j = s->stacka->top;
	arr = s->stacka->array;
	luckilest = s->stackb->top - i + 1;
	if (arr[0] < s->stackb->array[i])
		return (luckilest + 1);
	else if (arr[s->stacka->top] > s->stackb->array[i])
		return (luckilest);
	temp = arr[j--];
	while (j != -1)
	{
		if (temp < s->stackb->array[i] && arr[j] > s->stackb->array[i])
			return (luckilest + countbetween(s, j));
		temp = arr[j];
		j--;
	}
	return (luckilest);
}

int	counter(t_Stacks_op *s, int i)
{
	int	*arr;
	int	j;
	int	r;
	int	temp;

	r = 1;
	j = s->stacka->top;
	arr = s->stacka->array;
	temp = arr[j--];
	while (j != -1)
	{
		if (temp < i && arr[j] > i)
		{
			if ((s->stacka->top + 1) / 2 > j)
				return (s->stacka->top - r + 1);
			else
				return (r);
		}
		temp = arr[j--];
		r++;
	}
	return (r);
}
