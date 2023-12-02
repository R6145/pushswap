/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freemem.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 17:14:46 by fmaqdasi          #+#    #+#             */
/*   Updated: 2023/12/02 17:15:29 by fmaqdasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	freestacks(t_Stacks_op *s)
{
	freestack(s->stacka);
	freestack(s->stackb);
	free(s);
}

void	freestack(t_Stack *s)
{
	free(s->array);
	free(s);
}

void	freemergedall(char **val)
{
	int	i;

	i = 0;
	while (val[i] != NULL)
	{
		free(val[i]);
		i++;
	}
	free(val);
}