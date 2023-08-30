/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_A.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 11:37:04 by fmaqdasi          #+#    #+#             */
/*   Updated: 2023/08/28 12:51:55 by fmaqdasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_list	*stack(int x)
{
	t_list	*new_node;
	int		*y;

	y = (int *)malloc(sizeof(int));
	if (y == NULL)
		return (NULL);
	*y = x;
	new_node = ft_lstnew(y);
	if (new_node == NULL)
	{
		free(y);
		return (NULL);
	}
	return (new_node);
}

int	push(t_list **lst, int x)
{
	t_list	*new;
	int		*y;

	y = (int *)malloc(sizeof(int));
	if (y == NULL)
		return (-1);
	*y = x;
	new = ft_lstnew(y);
	if (new == NULL)
	{
		free(y);
		return (-1);
	}
	ft_lstadd_front(lst, new);
	return (x);
}

int	peek(t_list *lst)
{
	if (lst == NULL)
		return (-1);
	return (*(int *)(lst->content));
}

int	pop(t_list **lst)
{
	t_list	*lst2;
	int		x;

	if (*lst == NULL)
		return (-1);
	lst2 = *lst;
	*lst = lst2->next;
	x = (*(int *)(lst2->content));
	free(lst2->content);
	free(lst2);
	return (x);
}

int	isempty(t_list *lst)
{
	return (lst == NULL);
}

// int	main(void)
// {
// 	t_list	*s;

// 	s = stack(1);
// 	if (s == NULL)
// 		return (1);
// 	push(&s, 2);
// 	push(&s, 3);
// 	printf("%d\n", push(&s, 4));
// 	printf("%d\n", ft_lstsize(s));
// 	printf("%d\n", pop(&s));
// 	printf("%d\n", peek(s));
// 	printf("%d\n", pop(&s));
// 	while (s != NULL)
// 		pop(&s);
// 	return (0);
// }
