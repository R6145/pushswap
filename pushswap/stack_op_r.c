/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op_r.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 18:34:35 by fmaqdasi          #+#    #+#             */
/*   Updated: 2023/11/06 10:54:32 by fmaqdasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void static	rotate(t_Stack *s1)
{
	t_Stack	*x;
	int		y;

	x = stack(s1->max_size);
	y = pop(s1);
	while (s1->top != -1)
		push(x, pop(s1));
	push(s1, y);
	while (x->top != -1)
		push(s1, pop(x));
	free(x);
}

void	ra(t_Stacks_op *s)
{
	rotate(s->stacka);
	ft_printf("%s", "ra\n");
}

void	rb(t_Stacks_op *s)
{
	rotate(s->stackb);
	ft_printf("%s", "rb\n");
}

void	rr(t_Stacks_op *s)
{
	rotate(s->stacka);
	rotate(s->stackb);
	ft_printf("%s", "rr\n");
}
