/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortedcheck.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 14:05:33 by fmaqdasi          #+#    #+#             */
/*   Updated: 2023/11/09 17:26:17 by fmaqdasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	sortedcheck(t_Stack *s)
{
	int	x;
	int	*j;
	int	z;

	x = s->top;
	j = s->array;
	z = j[x];
	x--;
	if (s->top == -1 || s->top == 0)
		return (1);
	while (x > -1)
	{
		if (z > j[x])
			return (0);
		z = j[x];
		x--;
	}
	return (1);
}
