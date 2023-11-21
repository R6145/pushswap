/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortcheck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 16:05:09 by fmaqdasi          #+#    #+#             */
/*   Updated: 2023/11/21 17:43:09 by fmaqdasi         ###   ########.fr       */
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
		arr2[i] = counterstack(s, i) + s->stacka->top - i;
		// ft_printf("the cost of %d is: %d \n", s->stackb->array[i], arr2[i]);
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

int	counterstack(t_Stacks_op *s, int i)
{
	int		j;
	long	x;
	int		*arr;
	int		temp;

	j = s->stacka->top;
	arr = s->stacka->array;
	temp = 0;
	x = LONG_MIN;
	while (j != -1)
	{
		if (arr[j] - s->stackb->array[i] > 0 && (long)arr[j] < x)
		{
			temp = j;
			x = arr[temp];
		}
		j--;
	}
	if (s->stacka->maxnum < s->stackb->array[i])
		temp = s->stacka->maxnum;
	if ((s->stacka->top + 1) / 2 > temp)
		return (s->stacka->top - temp + 1);
	return (temp);
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
