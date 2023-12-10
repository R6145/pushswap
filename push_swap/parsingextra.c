/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsingextra.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 13:34:22 by fmaqdasi          #+#    #+#             */
/*   Updated: 2023/12/07 15:41:12 by fmaqdasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	checksign(char **argv)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	while (0 <= checksignu_util(argv) - i)
	{
		j = 0;
		flag = 0;
		while (argv[i][j] != '\0')
		{
			if (argv[i][j] == '-')
			{
				if (flag == 1 || argv[i][j + 1] == '\0')
					return (0);
				flag = 1;
			}
			else if (!((argv[i][j] >= 48 && argv[i][j] <= 57)))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	checkint(char **argv)
{
	int		i;
	long	*templong;
	long	*temp;
	int		z;

	i = 0;
	z = 0;
	while (argv[z] != NULL)
		z++;
	z--;
	temp = malloc(sizeof(long) * (z + 1));
	if (!temp)
		return (0);
	templong = malloc(sizeof(long) * (z + 1));
	if (!templong)
		return (0);
	while (i <= z)
	{
		temp[i] = ft_atoi(argv[i]);
		templong[i] = ft_atoilong(argv[i]);
		if (temp[i] != templong[i] || ft_strlen(argv[i]) > 13)
			return (free(temp), free(templong), 0);
		i++;
	}
	return (free(temp), free(templong), 1);
}
