/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortingutil.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:32:41 by fmaqdasi          #+#    #+#             */
/*   Updated: 2023/11/21 17:53:33 by fmaqdasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ra_or_rra(t_Stacks_op *s, int i)
{
	if ((s->stacka->top + 1) / 2 > i)
		return (1);
	return (0);
}

int	maxa(t_Stacks_op *s)
{
	int	temp;
	int	i;

	i = s->stacka->top;
	temp = i--;
	while (i != -1)
	{
		if (s->stacka->array[temp] < s->stacka->array[i])
			temp = i;
		i--;
	}
	return (temp);
}

int	mina(t_Stacks_op *s)
{
	int	temp;
	int	i;

	i = s->stacka->top;
	temp = i--;
	while (i != -1)
	{
		if (s->stacka->array[temp] > s->stacka->array[i])
			temp = i;
		i--;
	}
	return (temp);
}

void	between_ra(t_Stacks_op *s, int count)
{
	int	x;

	x = count;
	// ft_printf("%d\n",x);
	while (x != 0)
	{
		ra(s);
		x--;
	}
	// x = count;
	pa(s);
	// while (x != 0)
	// {
	// 	rra(s);
	// 	x--;
	// }
}

void	between_rra(t_Stacks_op *s, int count)
{
	int	x;

	x = count;
	while (x != 0)
	{
		rra(s);
		x--;
	}
	// x = count + 1;
	pa(s);
	// while (x != 0)
	// {
	// 	ra(s);
	// 	x--;
	// }
}
