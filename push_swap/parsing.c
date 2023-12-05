/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 14:39:04 by fmaqdasi          #+#    #+#             */
/*   Updated: 2023/12/05 16:54:25 by fmaqdasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	checker(char **temp, int argc, char **argv)
{
	if (checkempty(argc, argv) == 0)
		return (ft_printf("Error\n"), 0);
	else if (checkspace(argc, argv) == 0)
		return (ft_printf("Error\n"), 0);
	else if (checknumeric(temp) == 0)
		return (ft_printf("Error\n"), 0);
	else if (checksign(temp) == 0)
		return (ft_printf("Error\n"), 0);
	else if (checkint(temp) == 0)
		return (ft_printf("Error\n"), 0);
	else if (checkdup(temp) == 0)
		return (ft_printf("Error\n"), 0);
	return (1);
}

int	checkempty(int argc, char **argv)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	j = 0;
	flag = 0;
	while (i < argc)
	{
		flag = 0;
		if (argv[i][0] == ' ')
		{
			while (argv[i][j] != '\0')
			{
				if ((argv[i][j] >= 48 && argv[i][j] <= 57))
					flag = (1);
				j++;
			}
			if (flag == 0)
				return (0);
		}
		i++;
	}
	return (1);
}

int	checkspace(int argc, char **argv)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		if (ft_strncmp(argv[i], "", 10) == 0)
			return (0);
		i++;
	}
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
