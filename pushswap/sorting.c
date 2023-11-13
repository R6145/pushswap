/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:57:02 by fmaqdasi          #+#    #+#             */
/*   Updated: 2023/11/13 17:41:30 by fmaqdasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sorting(t_Stacks_op *s)
{
	if (s->stacka->top > 2)
		pb(s);
	if (s->stacka->top > 2 && sortedcheck(s->stacka) != 1)
		pb(s);
	while (s->stacka->top > 2 && sortedcheck(s->stacka) != 1)
	{
		pb(s);
	}
	s3(s);
	while (s->stackb->top > -1)
	{
		if (countstack(s, costcomp(s)) == 1)
			pa(s);
		else
			movetoa(s, costcomp(s));
	}
}

int	ra_or_rra(t_Stacks_op *s)
{
	int	*arr;

	arr = s->stacka->array;
	if (s->stacka->top - j > j)
		return (1);
	return (0);
}

void	movetoa(t_Stacks_op *s, int i)
{
	int	temp;

	temp = s->stackb->array[i];
	while (temp != s->stackb->array[s->stackb->top])
	{
		rb(s);
	}
}
