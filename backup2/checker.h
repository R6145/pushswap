/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 00:36:17 by fmaqdasi          #+#    #+#             */
/*   Updated: 2023/12/04 19:36:55 by fmaqdasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "libft/libft.h"
# include "printf/ft_printf.h"
# include "pushswap.h"

char	*readline(void);
int		check_checker(char **ins, char **list, char *line);
int		vaildinst(char **ins);
int		checkalpha(char *line);
void	freeall(char *line, char **inst, char **list, t_Stacks_op *s);
void	do_op(char **inst, t_Stacks_op *s);
void	do_op2(char *inst, t_Stacks_op *s);

#endif