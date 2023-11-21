/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortingutil.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:32:41 by fmaqdasi          #+#    #+#             */
/*   Updated: 2023/11/19 16:44:49 by fmaqdasi         ###   ########.fr       */
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
	temp = arr[j--];
	while (j != -1)
	{
		if (temp < i && arr[j] > i)
		{
			if ((s->stacka->top + 1) / 2 > j)
				return (1);
			else
				return (0);
		}
		temp = arr[j];
		j--;
	}
	return (0);
}

int	samesize(t_Stacks_op *s, int *x)
{
	if (s->stackb->top <= 0)
		return (0);
	if (x[s->stackb->top] == x[s->stackb->top - 1] - 1)
		return (1);
	return (0);
}

void	between_ra(t_Stacks_op *s, int count)
{
	int	x;

	x = count;
	while (x != 0)
	{
		ra(s);
		x--;
	}
	x = count;
	pa(s);
	while (x != 0)
	{
		rra(s);
		x--;
	}
}

void	between_rra(t_Stacks_op *s, int count)
{
	int	x;

	x = count;

	while (x != 0)
	{
		rra(s);
		x--;
	}
	x = count + 1;
	pa(s);
	while (x != 0)
	{
		ra(s);
		x--;
	}
}