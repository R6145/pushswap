/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 14:39:04 by fmaqdasi          #+#    #+#             */
/*   Updated: 2023/11/30 17:38:56 by fmaqdasi         ###   ########.fr       */
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

int	max(t_Stack *s)
{
	int	temp;
	int	i;

	i = s->top;
	temp = i--;
	while (i != -1)
	{
		if (s->array[temp] < s->array[i])
			temp = i;
		i--;
	}
	return (temp);
}

int	next_mina(t_Stack *s, int val)
{
	int	temp;
	int	i;

	i = s->top;
	temp = max(s);
	while (i != -1)
	{
		if (s->array[temp] > s->array[i] && s->array[i] > val)
			temp = i;
		i--;
	}
	return (temp);
}

int	min(t_Stack *s)
{
	int	temp;
	int	i;

	i = s->top;
	temp = i--;
	while (i != -1)
	{
		if (s->array[temp] > s->array[i])
			temp = i;
		i--;
	}
	return (temp);
}

void	normalize(t_Stack *s){
	int val;
	int	i;
	int minindex;
	int  temp[s->top + 1];
	
	i = 0;
	val = s->array[min(s)] - 1;
	while(i <= s->top)
	{
		minindex = next_mina(s, val);
		val = s->array[minindex];
		temp[minindex] = i;
		i++;
	}
	i = 0;
	while(i <= s->top)
	{
		s->array[i] = temp[i];
		i++;
	}
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
	normalize(s);
}
//push_swap "45 6 6" -"6" dosent work