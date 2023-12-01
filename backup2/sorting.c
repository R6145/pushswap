/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:57:02 by fmaqdasi          #+#    #+#             */
/*   Updated: 2023/12/02 03:18:19 by fmaqdasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sorting(t_Stacks_op *s)
{
	chunking(s);
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

void	chunking(t_Stacks_op *s)
{
	s->stacka->maxnum = s->stacka->array[maxa(s)];
	while (s->stacka->top > 2 && sortedcheck(s->stacka) != 1 && s->stacka->top
		- 1 > (2 * s->stacka->maxnum) / 3)
	{
		if (s->stacka->array[s->stacka->top] < s->stacka->maxnum / 3)
			pb(s);
		else
			ra(s);
	}
	while (s->stacka->top > 2 && sortedcheck(s->stacka) != 1 && s->stacka->top
		- 1 > s->stacka->maxnum / 3)
	{
		if (s->stacka->array[s->stacka->top] < (2 * s->stacka->maxnum) / 3)
			pb(s);
		else
			ra(s);
	}
	while (s->stacka->top > 2 && sortedcheck(s->stacka) != 1)
		pb(s);
}

void	movetoa(t_Stacks_op *s)
{
	int	count;
	int	num;

	num = costcomp(s);
	fixmove(s, num, 1);
	count = counterstack(s, s->stackb->top);
	if (s->stacka->num == s->stacka->top && s->stacka->between != 1)
		pa(s);
	else if (s->stacka->num == 0 && s->stacka->between != 1)
	{
		pa(s);
		ra(s);
	}
	else
	{
		if (s->stacka->rot == 1 && count != 0)
			between_ra(s, count);
		else if (count != 0)
			between_rra(s, count);
	}
}

void	fixmove(t_Stacks_op *s, int i, int x)
{
	int	temp;

	if (x == 1)
	{
		temp = s->stackb->array[i];
		if ((s->stackb->top + 1) / 2 > i)
			while (s->stackb->array[s->stackb->top] != temp)
				rrb(s);
		else
			while (s->stackb->array[s->stackb->top] != temp)
				rb(s);
	}
	if (x == 2)
	{
		if ((s->stackb->top + 1) / 2 >= s->stacka->minnum)
			while (sortedcheck(s->stacka) != 1)
				ra(s);
		else
			while (sortedcheck(s->stacka) != 1)
				rra(s);
	}
}
