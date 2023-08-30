/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 12:19:15 by fmaqdasi          #+#    #+#             */
/*   Updated: 2023/08/29 20:55:25 by fmaqdasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include <stdio.h>

void	step1(t_Stacks_op *s)
{
	int	x;
	int	j;

	x = find_largest_when(s->stacka);
	j = s->stacka->top;
	while (x <= j)
	{
		pb(s);
		x++;
	}
}

void	step2(t_Stacks_op *s)
{
	int	x;
	int	j;

	x = find_smallest_when(s->stackb);
	j = s->stackb->top;
	while (x <= j)
	{
		pa(s);
		x++;
	}
}

void	step3(t_Stacks_op *s)
{
	int	x;
	int	j;

	x = peek(s->stacka);
	while (s->stacka->top)
	{
		if (peek(s->stacka) > peek(s->stackb))
		{
			x = peek(s->stacka);
			pb(s);
		}
		else
			ra(s);
		printf("%d\n", peek(s->stacka));
	}
}n

void	sorting(t_Stacks_op *s)
{
	int x = 1;
	pb(s);
	while (peek(s->stacka) > peek(s->stackb))
	{
		pb(s);
		x = x + 1;
	}
	while (peek(s->stacka) < peek(s->stackb))
	{
		pa(s);
		x = x + 1;
	}
	else
		pb(s);
	while(peek(s->stacka))
	pb(s);
}
