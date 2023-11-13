/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 14:39:04 by fmaqdasi          #+#    #+#             */
/*   Updated: 2023/11/13 15:53:56 by fmaqdasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	checker(int argc, char **argv)
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
			if (!((argv[i][j] >= 48 && argv[i][j] <= 57) || argv[i][j] == '-')) //half done for - ex: 2- still cosidreed 5%0
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

	i = argc - 1;
	while (i > 0)
	{
		push(s, ft_atoi(argv[i]));
		i--;
	}
}
//push_swap "45 6 6" "6" dosent work