/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 14:40:22 by fmaqdasi          #+#    #+#             */
/*   Updated: 2023/08/28 17:56:49 by fmaqdasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_Stacks_op	*stacks(t_Stack *s1, t_Stack *s2)
{
	t_Stacks_op	*stackop;

	stackop = (t_Stacks_op *)malloc(sizeof(t_Stacks_op));
	stackop->stacka = s1;
	stackop->stackb = s2;
	return (stackop);
}

void static	swap(t_Stack *s1)
{
	int	x;
	int	y;

	if (s1->top < 2)
		return ;
	x = pop(s1);
	y = pop(s1);
	push(s1, x);
	push(s1, y);
}

void	sa(t_Stacks_op *s)
{
	swap(s->stacka);
}

void	sb(t_Stacks_op *s)
{
	swap(s->stackb);
}

void	ss(t_Stacks_op *s)
{
	sa(s);
	sb(s);
}
