/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:57:02 by fmaqdasi          #+#    #+#             */
/*   Updated: 2023/11/30 15:56:36 by fmaqdasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sorting(t_Stacks_op *s)
{
	int	x;

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
	int	num;
	int	count;

	temp = s->stackb->array[i];
	num = costcomp(s);
	count = counterstack(s, num);
	s->stacka->num = num;
	ft_printf("count = %d\n", count);
	ft_printf("num = %d\n", num);
	while (num != s->stackb->top)
		rb(s);
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
