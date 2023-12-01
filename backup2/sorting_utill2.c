/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utill2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 16:05:09 by fmaqdasi          #+#    #+#             */
/*   Updated: 2023/12/02 02:28:27 by fmaqdasi         ###   ########.fr       */
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
		arr2[i] = coststack(s, i) + bottomfix(s, i);
		i--;
	}
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

int	bottomfix(t_Stacks_op *s, int j)
{
	if ((s->stackb->top + 1) / 2 > j)
		return (j);
	return (s->stackb->top - j);
}

int	counterstack(t_Stacks_op *s, int i)
{
	int	*arr;
	int	j;
	int	temp;

	j = s->stacka->top;
	arr = s->stacka->array;
	if (s->stackb->array[i] > arr[s->stacka->maxnum])
		return (betweenmaxmin(s, 2), exct(s, s->stacka->maxnum, 3));
	if (s->stackb->array[i] < arr[s->stacka->minnum])
		return (betweenmaxmin(s, 1), exct(s, s->stacka->minnum, 2));
	if (arr[0] < s->stackb->array[i]
		&& arr[s->stacka->top] > s->stackb->array[i])
		return (exct(s, s->stacka->top, 2));
	while (j >= 0)
	{
		temp = arr[j];
		if (temp < s->stackb->array[i] && arr[j - 1] > s->stackb->array[i])
			return (exct(s, j, 1));
		j--;
	}
	return (0);
}

int	exct(t_Stacks_op *s, int j, int x)
{
	s->stacka->num = j;
	if (x == 2)
	{
		if ((s->stacka->top + 1) / 2 > j)
			return (s->stacka->rot = 0, j + 1);
		return (s->stacka->rot = 1, s->stacka->top - j);
	}
	if (x == 3)
	{
		if ((s->stacka->top + 1) / 2 > j)
			return (s->stacka->rot = 0, j);
		return (s->stacka->rot = 1, s->stacka->top - j + 1);
	}
	if ((s->stacka->top + 1) / 2 > j)
		return (s->stacka->rot = 0, j);
	return (s->stacka->between = 1, s->stacka->rot = 1, s->stacka->top - j + 1);
}

void	betweenmaxmin(t_Stacks_op *s, int i)
{
	if (i == 1)
	{
		if (s->stacka->minnum != s->stacka->top)
			s->stacka->between = 1;
	}
	if (i == 2)
	{
		if (s->stacka->maxnum != 0)
			s->stacka->between = 1;
	}
}
