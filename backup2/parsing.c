/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 14:39:04 by fmaqdasi          #+#    #+#             */
/*   Updated: 2023/12/02 20:22:25 by fmaqdasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	checker(int argc, char **temp)
{
	if (checknumeric(argc, temp) == 0)
		return (ft_printf("Error\n"), 0);
	else if (checkdup(temp) == 0)
		return (ft_printf("Error\n"), 0);
	return (1);
}

int	checknumeric(int argc, char **argv)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (i < argc - 1)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (!((argv[i][j] >= 48 && argv[i][j] <= 57) || argv[i][j] == '-'))
			{
				return (0);
			}
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
