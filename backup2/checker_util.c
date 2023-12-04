/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 19:37:20 by fmaqdasi          #+#    #+#             */
/*   Updated: 2023/12/04 21:51:16 by fmaqdasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

char	*readline(void)
{
	char	*st;
	char	*line;
	char	*linetemp;
	int		x;

	x = 1;
	st = malloc(2);
	line = ft_strdup("");
	while (x > 0)
	{
		x = read(STDIN_FILENO, st, 1);
		if (x < 0)
		{
			free(st);
			return (NULL);
		}
		if (x == 0)
			break ;
		linetemp = line;
		line = ft_strjoin(line, st);
		free(linetemp);
	}
	free(st);
	return (line);
}

void	freeall(char *line, char **inst, char **list, t_Stacks_op *s)
{
	freestacks(s);
	freemergedall(list);
	free(line);
	freemergedall(inst);
}

void	do_op(char **inst, t_Stacks_op *s)
{
	int	i;

	i = 0;
	while (inst[i] != NULL)
	{
		do_op2(inst[i], s);
		i++;
	}
}

void	do_op2(char *inst, t_Stacks_op *s)
{
	if (ft_strncmp(inst, "sa\0", 10) == 0)
		sa(s, 0);
	else if (ft_strncmp(inst, "sb\0", 10) == 0)
		sb(s, 0);
	else if (ft_strncmp(inst, "ss\0", 10) == 0)
		ss(s, 0);
	else if (ft_strncmp(inst, "ra\0", 10) == 0)
		ra(s, 0);
	else if (ft_strncmp(inst, "rb\0", 10) == 0)
		rb(s, 0);
	else if (ft_strncmp(inst, "rr\0", 10) == 0)
		rr(s, 0);
	else if (ft_strncmp(inst, "rra\0", 10) == 0)
		rra(s, 0);
	else if (ft_strncmp(inst, "rrb\0", 10) == 0)
		rrb(s, 0);
	else if (ft_strncmp(inst, "rrr\0", 10) == 0)
		rrr(s, 0);
	else if (ft_strncmp(inst, "pa\0", 10) == 0)
		pa(s, 0);
	else if (ft_strncmp(inst, "pb\0", 10) == 0)
		pb(s, 0);
}