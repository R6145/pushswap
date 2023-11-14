/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:24:53 by fmaqdasi          #+#    #+#             */
/*   Updated: 2023/11/14 18:41:28 by fmaqdasi         ###   ########.fr       */
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
	if (sortedcheck(s->stacka) == 1)
	{
		free(s);
		freestack(sa);
		freestack(sb);
		return (0);
	}
	if (sa->top == 2)
		s3(s);
	else
		sorting(s);
	ft_printf("|||||||||||||||||||||\n");
	ft_printf("%d\n", pop(s->stacka));
	ft_printf("%d\n", pop(s->stacka));
	ft_printf("%d\n", pop(s->stacka));
	ft_printf("%d\n", pop(s->stacka));
	ft_printf("%d\n", pop(s->stacka));
	ft_printf("%d\n", pop(s->stacka));
	ft_printf("|||||||||||||||||||||\n");
	ft_printf("%d\n", pop(s->stackb));
	ft_printf("%d\n", pop(s->stackb));
	ft_printf("%d\n", pop(s->stackb));
	ft_printf("%d\n", pop(s->stackb));
	ft_printf("%d\n", pop(s->stackb));
	ft_printf("%d\n", pop(s->stackb));
	free(s);
	freestack(sa);
	freestack(sb);
	return (0);
}
// int	main(int argc, char **argv)
// {
// 	t_Stack		*sa;
// 	t_Stack		*sb;
// 	t_Stacks_op	*s;

// 	if (checker(argc, argv) == 0)
// 		return (0);
// 	sa = stack(argc);
// 	sb = stack(argc);
// 	s = stacks(sa, sb);
// 	addall(sa, argv, argc);
// 	ra(s);
// 	printf("%d\n", pop(s->stacka));
// 	printf("%d\n", pop(s->stacka));
// 	printf("%d\n", pop(s->stacka));
// 	printf("%d\n", pop(s->stacka));
// 		printf("%d\n", pop(s->stacka));

// 	// printf("|||||%d", pop(s->stackb));
// 	// printf("|||||%d", pop(s->stackb));
// 	return (0);
// }
