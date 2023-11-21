/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 12:53:24 by fmaqdasi          #+#    #+#             */
/*   Updated: 2023/11/12 14:16:50 by fmaqdasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_Stack	*stack(int size)
{
	t_Stack	*s;

	s = (t_Stack *)malloc(sizeof(t_Stack));
	if (!s)
		return (NULL);
	s->array = (int *)malloc(sizeof(int) * (size + 1));
	if (!s->array)
		return (NULL);
	s->top = -1;
	s->max_size = size;
	return (s);
}

int	size(t_Stack *stack)
{
	return (stack->top + 1);
}

int	push(t_Stack *stack, int x)
{
	if (stack->top == stack->max_size - 1)
		return (-1);
	stack->top = stack->top + 1;
	return (stack->array[(stack->top)] = x);
}

int	pop(t_Stack *stack)
{
	if (stack->top == -1)
		return (-1);
	stack->top = stack->top - 1;
	return (stack->array[stack->top + 1]);
}

int	peek(t_Stack *stack)
{
	if (stack->top == -1)
		return (-1);
	return (stack->array[stack->top]);
}
