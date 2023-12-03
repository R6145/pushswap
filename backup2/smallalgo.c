/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smallalgo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 14:01:54 by fmaqdasi          #+#    #+#             */
/*   Updated: 2023/12/03 15:48:37 by fmaqdasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	s3(t_Stacks_op *s)
{
	int	*j;

	j = s->stacka->array;
	if (j[1] > j[0] && j[1] > j[2])
	{
		rra(s);
		if (j[2] > j[1])
			sa(s);
	}
	if (j[2] > j[0])
		ra(s);
	if (j[2] > j[1])
		sa(s);
}

void	s5(t_Stacks_op *s)
{
	while (s->stacka->top > 2 && sortedcheck(s->stacka) != 1)
		pb(s);
	s3(s);
	s->stacka->maxnum = maxa(s);
	s->stacka->minnum = mina(s);
	while (s->stackb->top > -1)
	{
		s->stacka->maxnum = maxa(s);
		s->stacka->minnum = mina(s);
		s->stacka->between = 0;
		movetoa(s);
	}
	fixmove(s, 2, 2);
}
