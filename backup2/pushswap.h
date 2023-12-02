/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 15:45:57 by fmaqdasi          #+#    #+#             */
/*   Updated: 2023/12/02 18:03:24 by fmaqdasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "libft/libft.h"
# include "printf/ft_printf.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list3
{
	int		*array;
	int		top;
	int		max_size;
	int		maxnum;
	int		minnum;
	int		rot;
	int		num;
	int		between;
}			t_Stack;

typedef struct s_list2
{
	t_Stack	*stacka;
	t_Stack	*stackb;
}			t_Stacks_op;

// stack
t_Stack		*stack(int size);
int			size(t_Stack *stack);
int			push(t_Stack *stack, int x);
int			pop(t_Stack *stack);
int			peek(t_Stack *stack);
void		freestack(t_Stack *s);
void		freestacks(t_Stacks_op *s);
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
char		**mergeall(int argc, char **argv);
void		freemergedall(char **val);
int			checker(int argc, char **argv);
int			checknumeric(int argc, char **argv);
int			checkdup(char **argv);
void		addall(t_Stack *s, char **argv);
// sorting algo
int			sortedcheck(t_Stack *s);
void		s3(t_Stacks_op *s);
void		s5(t_Stacks_op *s);
void		sorting(t_Stacks_op *s);
int			costcomp(t_Stacks_op *s);
int			counterstack(t_Stacks_op *s, int i);
void		movetoa(t_Stacks_op *s);
int			maxa(t_Stacks_op *s);
int			mina(t_Stacks_op *s);
void		between_ra(t_Stacks_op *s, int count);
void		between_rra(t_Stacks_op *s, int count);
int			exct(t_Stacks_op *s, int j, int x);
void		betweenmaxmin(t_Stacks_op *s, int i);
int			coststack(t_Stacks_op *s, int i);
int			exct2(t_Stacks_op *s, int j, int x);
void		fixmove(t_Stacks_op *s, int i, int x);
int			bottomfix(t_Stacks_op *s, int j);
void		chunking(t_Stacks_op *s);
void		normalize(t_Stacks_op *s);
int			next_mina(t_Stacks_op *s, int val);

#endif