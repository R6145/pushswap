/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:57:02 by fmaqdasi          #+#    #+#             */
/*   Updated: 2023/11/22 14:35:17 by fmaqdasi         ###   ########.fr       */
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
	while (s->stackb->top > -1)
	{
		x = s->stackb->top;
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

void	between(t_Stacks_op *s, int i, int count)
{
	if (ra_or_rra(s, i) == 0 && count != 0)
		between_ra(s, count);
	else if (count != 0)
		between_rra(s, count);
}

void	movetoa(t_Stacks_op *s, int i)
{
	int	temp;
	int	count;

	temp = s->stackb->array[i];
	count = counterstack(s, temp);
	if (temp < s->stacka->array[s->stacka->top])
		pa(s);
	else if (temp > s->stacka->array[0])
	{
		pa(s);
		ra(s);
	}
	else
	{
		between(s, temp, count);
	}
}
