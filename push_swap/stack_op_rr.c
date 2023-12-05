/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op_rr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 12:06:25 by fmaqdasi          #+#    #+#             */
/*   Updated: 2023/12/04 18:06:18 by fmaqdasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	rev_rotate(t_Stack *s1)
{
	t_Stack	*x;
	int		y;

	x = stack(s1->max_size);
	while (s1->top != 0)
		push(x, pop(s1));
	y = pop(s1);
	while (x->top != -1)
		push(s1, pop(x));
	push(s1, y);
	freestack(x);
}

void	rra(t_Stacks_op *s, int x)
{
	rev_rotate(s->stacka);
	if (x == 1)
		ft_printf("%s", "rra\n");
}

void	rrb(t_Stacks_op *s, int x)
{
	rev_rotate(s->stackb);
	if (x == 1)
		ft_printf("%s", "rrb\n");
}

void	rrr(t_Stacks_op *s, int x)
{
	rev_rotate(s->stacka);
	rev_rotate(s->stackb);
	if (x == 1)
		ft_printf("%s", "rrr\n");
}
