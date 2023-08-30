/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 14:39:04 by fmaqdasi          #+#    #+#             */
/*   Updated: 2023/08/29 14:30:34 by fmaqdasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include <stdio.h>

int static	checker(int argc, char **argv)
{
	int	i;
	int	j;

	j = 0;
	i = 1;
	if (argc < 2)
		return (0);
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (!(argv[i][j] >= 48 && argv[i][j] <= 57))
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

void	addall(t_Stack *s, char **argv, int argc)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		push(s, ft_atoi(argv[i]));
		i++;
	}
}

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
	sorting(s);
	printf("%d\n", pop(s->stacka));
	printf("%d\n", pop(s->stacka));
	printf("%d\n", pop(s->stacka));
	printf("%d\n", pop(s->stacka));
	printf("%d\n", pop(s->stacka));
	printf("|||||||||||||||||||||\n");
	printf("%d\n", pop(s->stackb));
	printf("%d\n", pop(s->stackb));
	printf("%d\n", pop(s->stackb));
	printf("%d\n", pop(s->stackb));
	printf("%d\n", pop(s->stackb));
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
