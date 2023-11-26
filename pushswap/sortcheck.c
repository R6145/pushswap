/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortcheck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 16:05:09 by fmaqdasi          #+#    #+#             */
/*   Updated: 2023/11/26 18:36:51 by fmaqdasi         ###   ########.fr       */
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
	int	*arr;
	int	j;
	int	temp;

	j = s->stacka->top;
	arr = s->stacka->array;
	temp = arr[j--];
	if (s->stackb->array[i] > arr[s->stacka->maxnum])
		return (exct(s, s->stacka->maxnum, 2));
	if (s->stackb->array[i] < arr[s->stacka->minnum])
		return (exct(s, s->stacka->minnum, 2));
	while (j != -1)
	{
		if (temp < s->stackb->array[i] && arr[j] > s->stackb->array[i])
			return (exct(s, j, 1));
		else if (j == 0 && arr[0] < s->stackb->array[i]
			&& arr[s->stacka->top] > s->stackb->array[i])
			return (exct(s, s->stacka->top, 0));
		temp = arr[j];
		j--;
	}
	// ft_printf("temp: %d\ncurrent: %d\n", temp, arr[0]);
	return (0);
}

int	exct(t_Stacks_op *s, int j, int x)
{
	ft_printf("num: %d\n", j);
	ft_printf("num top: %d\n", (s->stacka->top + 1) / 2);
	ft_printf("x: %d\n", x);
	// s->stacka->num = j;
	// if (x == 2)
	// {
	// 	j++;
	// 	s->stacka->num++;
	// }
	// if (s->stacka->num > s->stacka->top)
	// 	s->stacka->num = s->stacka->top;
	// if (((x == 1 || x == 2 )&& j == 0))
	// 	return (s->stacka->num = j + 1, s->stacka->rot = 0, 1);
	// if ((x == 1 && j == 0))
	// 	return (s->stacka->num = j + 1, s->stacka->rot = 0, 1);
	if (x == 2 && (s->stacka->top + 1) / 2 > j)
		return (s->stacka->rot = 0, j);
	// else if (x == 2)
	// 	return (s->stacka->rot = 1, s->stacka->num++, j++);
	if ((s->stacka->top + 1) / 2 > j)
		return (s->stacka->rot = 0, j + 1);
	return (s->stacka->rot = 1, s->stacka->top - j);
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
