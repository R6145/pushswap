/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:57:02 by fmaqdasi          #+#    #+#             */
/*   Updated: 2023/11/30 17:43:33 by fmaqdasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sorting(t_Stacks_op *s)
{
	int	x;

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
	{
		pb(s);
	}
	s3(s);
	s->stacka->maxnum = maxa(s);
	s->stacka->minnum = mina(s);
	while (s->stackb->top > -1)
	{
		s->stacka->maxnum = maxa(s);
		s->stacka->minnum = mina(s);
		x = s->stackb->top;
		s->stacka->between = 0;
		movetoa(s, x);
	}
	while (sortedcheck(s->stacka) != 1)
	{
		// ft_printf("|||||||||||||||||||||\n");
		// ft_printf("%d\n", pop(s->stacka));
		// ft_printf("%d\n", pop(s->stacka));
		// ft_printf("%d\n", pop(s->stacka));
		// ft_printf("%d\n", pop(s->stacka));
		// ft_printf("%d\n", pop(s->stacka));
		// ft_printf("%d\n", pop(s->stacka));
		// ft_printf("|||||||||||||||||||||\n");
		// ft_printf("%d\n", pop(s->stackb));
		// ft_printf("%d\n", pop(s->stackb));
		// ft_printf("%d\n", pop(s->stackb));
		// ft_printf("%d\n", pop(s->stackb));
		// ft_printf("%d\n", pop(s->stackb));
		// ft_printf("%d\n", pop(s->stackb));
		rra(s);
	}
}

void	between(t_Stacks_op *s, int i, int count)
{
	i = 0;
	if (i < INT_MIN)
		ft_printf("%d", i);
	if (s->stacka->rot == 1 && count != 0)
		between_ra(s, count);
	else if (count != 0)
		between_rra(s, count);
}

void	movetoa(t_Stacks_op *s, int i)
{
	int	temp;
	int	count;

	temp = s->stackb->array[i];
	count = counterstack(s, i);
	// ft_printf("count = %d\n", count);
	// ft_printf("num = %d\n", s->stacka->num);
	// exit(0);
	if (s->stacka->num == s->stacka->top && s->stacka->between != 1)
		pa(s);
	else if (s->stacka->num == 0 && s->stacka->between != 1)
	{
		pa(s);
		ra(s);
	}
	else
	{
		between(s, temp, count);
	}
}
