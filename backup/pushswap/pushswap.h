/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 15:45:57 by fmaqdasi          #+#    #+#             */
/*   Updated: 2023/11/19 16:43:21 by fmaqdasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "libft/libft.h"
# include "printf/ft_printf.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list3
{
	int		*array;
	int		top;
	int		max_size;
}			t_Stack;

typedef struct s_list2
{
	t_Stack	*stacka;
	t_Stack	*stackb;
	int		samesize;
}			t_Stacks_op;
// parsing
int			ft_atoi(const char *str);
// stack
t_Stack		*stack(int size);
int			size(t_Stack *stack);
int			push(t_Stack *stack, int x);
int			pop(t_Stack *stack);
int			peek(t_Stack *stack);
void		freestack(t_Stack *s);
// stack opeartions
t_Stacks_op	*stacks(t_Stack *s1, t_Stack *s2);
void		sa(t_Stacks_op *s);
void		sb(t_Stacks_op *s);
void		ss(t_Stacks_op *s);
void		pa(t_Stacks_op *s);
void		pb(t_Stacks_op *s);
void		ra(t_Stacks_op *s);
void		rb(t_Stacks_op *s);
void		rc(t_Stacks_op *s);
void		rra(t_Stacks_op *s);
void		rrb(t_Stacks_op *s);
void		rrr(t_Stacks_op *s);
// parsing
int			checker(int argc, char **argv);
void		addall(t_Stack *s, char **argv, int argc);
// sorting algo
int			sortedcheck(t_Stack *s);
void		s3(t_Stacks_op *s);
void		sorting(t_Stacks_op *s);
int			costcomp(t_Stacks_op *s);
int			counterstack(t_Stacks_op *s, int i);
int			countbetween(t_Stacks_op *s, int j);
int			counter(t_Stacks_op *s, int i);
int			ra_or_rra(t_Stacks_op *s, int j);
void		movetoa(t_Stacks_op *s, int i);
// void		between(t_Stacks_op *s, int i, int count);
void		between_ra(t_Stacks_op *s, int count);
void		between_rra(t_Stacks_op *s, int count);
int			samesize(t_Stacks_op *s, int *x);

#endif