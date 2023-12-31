/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 00:35:59 by fmaqdasi          #+#    #+#             */
/*   Updated: 2023/12/06 14:06:17 by fmaqdasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int argc, char **argv)
{
	char		*line;
	char		**inst;
	char		**list;
	t_Stacks_op	*s;

	if (argc < 2)
		return (0);
	line = readline();
	inst = ft_split(line, '\n');
	list = mergeall(argc, argv);
	s = inti(list);
	if (check_checker(inst, line) == 0 || checker(list, argc, argv) == 0)
		return (freeall(line, inst, list, s), 0);
	addall(s->stacka, list);
	if (sortedcheck(s->stacka) == 1 && checknumeric(inst) == 0)
		return (freeall(line, inst, list, s), ft_printf("Error\n"), 0);
	normalize(s);
	do_op(inst, s);
	if (sortedcheck(s->stacka) == 1 && s->stackb->top == -1)
		return (freeall(line, inst, list, s), ft_printf("OK\n"), 0);
	else
		return (freeall(line, inst, list, s), ft_printf("KO\n"), 0);
	freeall(line, inst, list, s);
	return (0);
}
