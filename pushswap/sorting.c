/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:57:02 by fmaqdasi          #+#    #+#             */
/*   Updated: 2023/11/17 17:20:22 by fmaqdasi         ###   ########.fr       */
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
		x = costcomp(s);
		// ft_printf("%d\n",counterstack(s, x));
		if (counterstack(s, x) == 1)
			pa(s);
		else
			movetoa(s, x);
	}
}

// int reached(t_Stacks_op *s , )
// {

// } //code of rr when ra and rb
// void	stcases(t_Stacks_op *s, int i, int count)
// {
// 	int	x;

// 	x = count;
// 	if (s->stackb->array[i] < s->stacka->array[s->stacka->top])
// 		pa(s);
// 	else if (s->stackb->array[i] > s->stacka->array[0])
// 	{
// 		pa(s);
// 		ra(s);
// 	}
// 	else
// 	{
// 		between(s, i, count);
// 	}
// }

void	between(t_Stacks_op *s, int i, int count)
{
	int	x;

	x = count;
	// ft_printf("%d\n",x);
	if (ra_or_rra(s, i) == 0 && x != 0)
	{
		while (x != 0)
		{
			ra(s);
			x--;
		}
		x = count;
		pa(s);
		while (x != 0)
		{
			rra(s);
			x--;
		}
	}
	else if (x != 0)
	{
		while (x != 0)
		{
			rra(s);
			x--;
		}
		x = count + 1;
		pa(s);
		while (x != 0)
		{
			ra(s);
			x--;
		}
	}
}

void	movetoa(t_Stacks_op *s, int i)
{
	int	temp;
	int	count;

	temp = s->stackb->array[i];
	while (temp != s->stackb->array[s->stackb->top])
		rb(s);
	count = counter(s, temp);
	// ft_printf("%d\n",count);
	// ft_printf("%d\n",temp);
	// ft_printf("%d\n",s->stacka->array[0]);

	if (temp < s->stacka->array[s->stacka->top])
		pa(s);
	else if (temp > s->stacka->array[0])
	{
		pa(s);
		ra(s);
	}
	else
	{
		between(s, i, count);
	}
}
