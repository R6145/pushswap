/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 14:40:22 by fmaqdasi          #+#    #+#             */
/*   Updated: 2023/12/07 15:51:15 by fmaqdasi         ###   ########.fr       */
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

static void	swap(t_Stack *s1)
{
	int	x;
	int	y;

	if (s1->top < 1)
		return ;
	x = pop(s1);
	y = pop(s1);
	push(s1, x);
	push(s1, y);
}

void	sa(t_Stacks_op *s, int x)
{
	swap(s->stacka);
	if (x == 1)
		ft_printf("%s", "sa\n");
}

void	sb(t_Stacks_op *s, int x)
{
	swap(s->stackb);
	if (x == 1)
		ft_printf("%s", "sb\n");
}

void	ss(t_Stacks_op *s, int x)
{
	swap(s->stacka);
	swap(s->stackb);
	if (x == 1)
		ft_printf("%s", "ss\n");
}
