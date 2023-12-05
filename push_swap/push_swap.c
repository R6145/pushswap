/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:24:53 by fmaqdasi          #+#    #+#             */
/*   Updated: 2023/12/05 13:17:52 by fmaqdasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	main(int argc, char **argv)
{
	t_Stacks_op	*s;
	char		**temp;

	if (argc == 1)
		return (0);
	temp = mergeall(argc, argv);
	s = inti(temp);
	if (checker(temp, argc, argv) == 0)
		return (freestacks(s), freemergedall(temp), 0);
	addall(s->stacka, temp);
	normalize(s);
	if (sortedcheck(s->stacka) == 1)
		return (freestacks(s), freemergedall(temp), 0);
	if (s->stacka->top == 2)
		s3(s);
	else if (s->stacka->top <= 4)
		s5(s);
	else
		sorting(s);
	freestacks(s);
	freemergedall(temp);
	return (0);
}
