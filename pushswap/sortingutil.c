/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortingutil.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:32:41 by fmaqdasi          #+#    #+#             */
/*   Updated: 2023/11/19 14:21:39 by fmaqdasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ra_or_rra(t_Stacks_op *s, int i)
{
	int	*arr;
	int	j;
	int	temp;

	j = s->stacka->top;
	arr = s->stacka->array;
	temp = arr[j--];
	while (j != -1)
	{
		if (temp < i && arr[j] > i)
		{
			// ft_printf("%d\n",temp);
			// ft_printf("%d\n",arr[j]);
			// ft_printf("%d\n",s->stackb->array[i]);
			// ft_printf("%d\n",i);
			// ft_printf("%d\n",s->stacka->top);
			// ft_printf("%d\n",j);
			if ((s->stacka->top + 1)/2 > j)
				return (1);
			else
				return (0);
		}
		temp = arr[j];
		j--;
	}
	return (0);
}
