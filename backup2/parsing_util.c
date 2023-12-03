/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 17:22:11 by fmaqdasi          #+#    #+#             */
/*   Updated: 2023/12/03 17:29:42 by fmaqdasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

long	ft_atoilong(const char *str)
{
	long	sign;
	int		i;
	long	tot;

	i = 0;
	sign = 1;
	tot = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		str++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		str++;
	}
	while (str[i] == '0')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		tot = tot * 10 + str[i] - '0';
		i++;
	}
	return (tot * sign);
}

int	checksignu_util(char **argv)
{
	int	z;

	z = 0;
	while (argv[z] != NULL)
		z++;
	z--;
	return (z);
}

char	**mergeall(int argc, char **argv)
{
	int		i;
	char	**temp;
	char	*merged;
	char	*mergedtemp;

	i = 1;
	merged = ft_strdup(" ");
	while (i < argc)
	{
		mergedtemp = merged;
		merged = ft_strjoin(merged, " ");
		free(mergedtemp);
		mergedtemp = merged;
		merged = ft_strjoin(merged, argv[i]);
		i++;
		free(mergedtemp);
	}
	temp = ft_split(merged, 32);
	free(merged);
	return (temp);
}
