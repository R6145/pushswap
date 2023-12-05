/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 15:54:56 by fmaqdasi          #+#    #+#             */
/*   Updated: 2023/12/04 18:10:45 by fmaqdasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	pa(t_Stacks_op *s, int x)
{
	int	z;

	if (s->stackb->top == -1)
		return ;
	z = pop(s->stackb);
	push(s->stacka, z);
	if (x == 1)
		ft_printf("%s", "pa\n");
}

void	pb(t_Stacks_op *s, int x)
{
	int	z;

	if (s->stacka->top == -1)
		return ;
	z = pop(s->stacka);
	push(s->stackb, z);
	if (x == 1)
		ft_printf("%s", "pb\n");
}
