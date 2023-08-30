/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 15:54:56 by fmaqdasi          #+#    #+#             */
/*   Updated: 2023/08/28 17:58:29 by fmaqdasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	pa(t_Stacks_op *s)
{
	int	x;

	if (s->stackb->top == -1)
		return ;
	x = pop(s->stackb);
	push(s->stacka, x);
}

void	pb(t_Stacks_op *s)
{
	int	x;

	if (s->stacka->top == -1)
		return ;
	x = pop(s->stacka);
	push(s->stackb, x);
}
