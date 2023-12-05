/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 19:36:01 by fmaqdasi          #+#    #+#             */
/*   Updated: 2023/12/05 14:09:23 by fmaqdasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	check_checker(char **ins, char *line)
{
	if (checkalpha(line) == 0)
		return (ft_printf("Error\n"), 0);
	else if (vaildinst(ins) == 0)
		return (ft_printf("Error\n"), 0);
	return (1);
}

int	vaildinst(char **ins)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (ins[i] != NULL)
	{
		x = 0;
		if (ft_strncmp(ins[i], "sa\0", 10) == 0 || ft_strncmp(ins[i], "sb\0",
				10) == 0 || ft_strncmp(ins[i], "ss\0", 10) == 0)
			x = 1;
		if (ft_strncmp(ins[i], "ra\0", 10) == 0 || ft_strncmp(ins[i], "rb\0",
				10) == 0 || ft_strncmp(ins[i], "rr\0", 10) == 0)
			x = 1;
		if (ft_strncmp(ins[i], "rra\0", 10) == 0 || ft_strncmp(ins[i], "rrb\0",
				10) == 0 || ft_strncmp(ins[i], "rrr\0", 10) == 0)
			x = 1;
		if (ft_strncmp(ins[i], "pa\0", 10) == 0 || ft_strncmp(ins[i], "pb\0",
				10) == 0)
			x = 1;
		if (x == 0)
			return (0);
		i++;
	}
	return (1);
}

int	checkalpha(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (!((line[i] >= 97 && line[i] <= 122) || line[i] == '\n'))
			return (0);
		i++;
	}
	return (1);
}
