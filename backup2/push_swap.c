/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:24:53 by fmaqdasi          #+#    #+#             */
/*   Updated: 2023/12/02 03:01:20 by fmaqdasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	main(int argc, char **argv)
{
	t_Stack		*sa;
	t_Stack		*sb;
	t_Stacks_op	*s;

	if (checker(argc, argv) == 0)
		return (0);
	sa = stack(argc);
	sb = stack(argc);
	addall(sa, argv, argc);
	s = stacks(sa, sb);
	normalize(s);
	if (sortedcheck(s->stacka) == 1)
	{
		freestacks(s);
		return (0);
	}
	if (sa->top == 2)
		s3(s);
	else if (sa->top <= 4)
		s5(s);
	else
		sorting(s);
	freestacks(s);
	return (0);
}

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