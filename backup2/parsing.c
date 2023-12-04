/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 14:39:04 by fmaqdasi          #+#    #+#             */
/*   Updated: 2023/12/04 20:07:59 by fmaqdasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	checker(char **temp)
{
	if (checknumeric(temp) == 0)
		return (ft_printf("Error1\n"), 0);
	else if (checksign(temp) == 0)
		return (ft_printf("Error2\n"), 0);
	else if (checkint(temp) == 0)
		return (ft_printf("Error3\n"), 0);
	else if (checkdup(temp) == 0)
		return (ft_printf("Error4\n"), 0);
	return (1);
}

int	checknumeric(char **argv)
{
	int	i;
	int	j;
	int	z;

	j = 0;
	i = 0;
	z = 0;
	while (argv[z] != NULL)
		z++;
	z--;
	while (i <= z)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (!((argv[i][j] >= 48 && argv[i][j] <= 57) || argv[i][j] == '-'
					|| argv[i][j] == ' '))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	checkdup(char **argv)
{
	int	i;
	int	j;
	int	*temp;
	int	z;

	i = 0;
	z = 0;
	while (argv[z] != NULL)
		z++;
	z--;
	temp = malloc(sizeof(int) * (z + 1));
	if (!temp)
		return (0);
	while (i <= z)
	{
		temp[i] = ft_atoi(argv[i]);
		j = 0;
		while (j < i)
		{
			if (temp[i] == temp[j++])
				return (free(temp), 0);
		}
		i++;
	}
	return (free(temp), 1);
}

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
		if (temp[i] != templong[i])
			return (free(temp), free(templong), 0);
		i++;
	}
	return (free(temp), free(templong), 1);
}
