/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 15:54:56 by fmaqdasi          #+#    #+#             */
/*   Updated: 2023/11/06 10:54:38 by fmaqdasi         ###   ########.fr       */
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
	ft_printf("%s", "pa\n");
}

void	pb(t_Stacks_op *s)
{
	int	x;

	if (s->stacka->top == -1)
		return ;
	x = pop(s->stacka);
	push(s->stackb, x);
	ft_printf("%s", "pb\n");
}
