/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortcheck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 16:05:09 by fmaqdasi          #+#    #+#             */
/*   Updated: 2023/11/23 18:12:35 by fmaqdasi         ###   ########.fr       */
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
	int	*arr;
	int	j;
	int	temp;
	int	flag;

	j = s->stacka->top;
	arr = s->stacka->array;
	temp = arr[j--];
	while (j != -1)
	{
		if (temp < s->stackb->array[i] && arr[j] > s->stackb->array[i])
		{
			if ((s->stacka->top + 1) / 2 > j)
				return (s->stacka->rot = 1, s->stacka->top - j + 1);
			return (s->stacka->rot = 0, j);
		}
		else if (j == 0 && (temp < s->stackb->array[i]
				&& arr[s->stacka->top] > s->stackb->array[i]))//fix
			return (1);
		j--;
	}
	return (0);
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
