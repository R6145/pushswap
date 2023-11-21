/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:57:02 by fmaqdasi          #+#    #+#             */
/*   Updated: 2023/11/21 17:51:09 by fmaqdasi         ###   ########.fr       */
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
		x = costcomp(s);
		s->stacka->maxnum = maxa(s);
		s->stacka->minnum = mina(s);
		ft_printf("%d   : %d\n", s->stackb->array[x], counterstack(s, x));
		if (counterstack(s, x) == 1)
			pa(s);
		else
			movetoa(s, x);
	}
	while (sortedcheck(s->stacka) != 1)
	{
		ft_printf("|||||||||||||||||||||\n");
		ft_printf("%d\n", pop(s->stacka));
		ft_printf("%d\n", pop(s->stacka));
		ft_printf("%d\n", pop(s->stacka));
		ft_printf("%d\n", pop(s->stacka));
		ft_printf("%d\n", pop(s->stacka));
		ft_printf("%d\n", pop(s->stacka));
		ft_printf("|||||||||||||||||||||\n");
		ft_printf("%d\n", pop(s->stackb));
		ft_printf("%d\n", pop(s->stackb));
		ft_printf("%d\n", pop(s->stackb));
		ft_printf("%d\n", pop(s->stackb));
		ft_printf("%d\n", pop(s->stackb));
		ft_printf("%d\n", pop(s->stackb));
		rra(s);
	}
}

// void	between(t_Stacks_op *s, int i, int count)
// {
// 	if (ra_or_rra(s, i) == 0 && count != 0)
// 		between_ra(s, count);
// 	else if (count != 0)
// 		between_rra(s, count);
// }

void	movetoa(t_Stacks_op *s, int i)
{
	int	temp;
	int	count;

	temp = s->stackb->array[i];
	while (temp != s->stackb->array[s->stackb->top])
		rb(s);
	count = counter(s, temp);
	// ft_printf("%d\n", counterstack(s, i));
	if (counterstack(s, i) == 1)
		pa(s);
	// else if (counterstack(s, i) == 2)
	// {
	// 	pa(s);
	// 	ra(s);
	// }
	else
	{
		if (ra_or_rra(s, i) == 0 && counterstack(s, i) != 0)
			between_ra(s, counterstack(s, i));
		else if (count != 0)
			between_rra(s, counterstack(s, i));
	}
}
