/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:57:02 by fmaqdasi          #+#    #+#             */
/*   Updated: 2023/12/02 01:45:37 by fmaqdasi         ###   ########.fr       */
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
		// ft_printf("%d\n", pop(s->stacka));
		// ft_printf("%d\n", pop(s->stacka));
		// ft_printf("|||||||||||||||||||||\n");
		// ft_printf("%d\n", pop(s->stackb));
		// ft_printf("%d\n", pop(s->stackb));
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
	int	num;

	if (i < INT_MIN)
		ft_printf("%d", i);
	num = costcomp(s);
	temp = s->stackb->array[num];
	fixmove(s, num, 1);
	// while (s->stackb->array[s->stackb->top] != temp)
	// 	rb(s);
	count = counterstack(s, s->stackb->top);
	// ft_printf("index = %d\n", num);
	// ft_printf("temp: %d\n",temp);
	// ft_printf("num = %d\n", s->stacka->num);
	// ft_printf("top s = %d\n", s->stacka->num);
	// ft_printf("between = %d\n", s->stacka->between);
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

void	fixmove(t_Stacks_op *s, int i, int x)
{
	int temp;

	if (x == 1)
	{
		temp = s->stackb->array[i];
		if ((s->stackb->top + 1) / 2 > i)
		{
			while (s->stackb->array[s->stackb->top] != temp)
				rrb(s);
		}
		else
		{
			while (s->stackb->array[s->stackb->top] != temp)
				rb(s);
		}
	}
	if (x == 2)
	{
		if ((s->stackb->top + 1) / 2 > s->stacka->maxnum)
		{
			while (sortedcheck(s->stacka) != 1)
				rb(s);
		}
		else
		{
			while (sortedcheck(s->stacka) != 1)
				rrb(s);
		}
	}
}
