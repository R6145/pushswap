/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:24:53 by fmaqdasi          #+#    #+#             */
/*   Updated: 2023/12/03 00:41:54 by fmaqdasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	main(int argc, char **argv)
{
	t_Stack		*sa;
	t_Stack		*sb;
	t_Stacks_op	*s;
	char		**temp;

	if (argc == 1)
		return (0);
	sa = stack(argc);
	sb = stack(argc);
	s = stacks(sa, sb);
	temp = mergeall(argc, argv);
	if (checker(argc, temp) == 0)
		return (freestacks(s), freemergedall(temp), 0);
	addall(sa, temp);
	// ft_printf("|||||||||||||||||||||\n");
	// ft_printf("%d\n", pop(s->stacka));
	// ft_printf("%d\n", pop(s->stacka));
	// ft_printf("%d\n", pop(s->stacka));
	// ft_printf("%d\n", pop(s->stacka));
	// ft_printf("%d\n", pop(s->stacka));
	// ft_printf("%d\n", pop(s->stacka));
	// ft_printf("|||||||||||||||||||||\n");
	// ft_printf("%d\n", pop(s->stackb));
	// ft_printf("%d\n", pop(s->stackb));
	// ft_printf("%d\n", pop(s->stackb));
	// ft_printf("%d\n", pop(s->stackb));
	// ft_printf("%d\n", pop(s->stackb));
	// ft_printf("%d\n", pop(s->stackb));
	normalize(s);
	if (sortedcheck(s->stacka) == 1)
		return (freestacks(s), freemergedall(temp), 0);
	if (sa->top == 2)
		s3(s);
	else if (sa->top <= 4)
		s5(s);
	else
		sorting(s);
	freestacks(s);
	freemergedall(temp);
	return (0);
}
// fix this pge
// fix 5-
// fix long
// fix "45 6 7" -"6" not working