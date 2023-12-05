/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:32:41 by fmaqdasi          #+#    #+#             */
/*   Updated: 2023/12/04 18:09:07 by fmaqdasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

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
	while (x > 0)
	{
		ra(s, 1);
		x--;
	}
	pa(s, 1);
}

void	between_rra(t_Stacks_op *s, int count)
{
	int	x;

	x = count;
	while (x > 0)
	{
		rra(s, 1);
		x--;
	}
	pa(s, 1);
}
