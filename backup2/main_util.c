/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:25:43 by fmaqdasi          #+#    #+#             */
/*   Updated: 2023/12/04 13:26:15 by fmaqdasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_Stacks_op	*inti(char **temp)
{
	t_Stack	*sa;
	t_Stack	*sb;
	int		z;

	z = 0;
	while (temp[z] != NULL)
		z++;
	sa = stack(z);
	sb = stack(z);
	return (stacks(sa, sb));
}

void	addall(t_Stack *s, char **argv)
{
	int	j;

	j = 0;
	while (argv[j] != NULL)
		j++;
	j--;
	while (j >= 0)
	{
		push(s, ft_atoi(argv[j]));
		j--;
	}
}