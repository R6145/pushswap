/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smallalgo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 14:01:54 by fmaqdasi          #+#    #+#             */
/*   Updated: 2023/11/09 19:06:05 by fmaqdasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	s3(t_Stacks_op *s)
{
	int	*j;

	j = s->stacka->array;
	if (j[1] > j[0] && j[1] > j[2])
	{
		rra(s);
		if (j[2] > j[1])
			sa(s);
	}
	if (j[2] > j[0])
		ra(s);
	if (j[2] > j[1])
		sa(s);
}

// void	s6(t_Stacks_op *s)
// {
// 	if (s->stacka->top > 2)
// 		pb(s);
// 	if (s->stacka->top > 2 && sortedcheck(s->stacka))
// 		pb(s);
// 	while (s->stacka->top > 2)
// 	{
// 	}
// }
