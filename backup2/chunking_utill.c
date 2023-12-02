/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunking_utill.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 02:29:03 by fmaqdasi          #+#    #+#             */
/*   Updated: 2023/12/02 20:13:34 by fmaqdasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	next_mina(t_Stacks_op *s, int val)
{
	int	temp;
	int	i;

	i = s->stacka->top;
	temp = maxa(s);
	while (i != -1)
	{
		if (s->stacka->array[temp] > s->stacka->array[i]
			&& s->stacka->array[i] > val)
			temp = i;
		i--;
	}
	return (temp);
}

void	normalize(t_Stacks_op *s)
{
	int	val;
	int	i;
	int	minindex;
	int	*temp;

	i = 0;
	temp = malloc(sizeof(int) * (s->stacka->top + 1));
	val = s->stacka->array[mina(s)];
	while (i <= s->stacka->top)
	{
		minindex = next_mina(s, val);
		val = s->stacka->array[minindex];
		temp[minindex] = i;
		i++;
	}
	i = 0;
	while (i <= s->stacka->top)
	{
		s->stacka->array[i] = temp[i];
		i++;
	}
	free(temp);
}
