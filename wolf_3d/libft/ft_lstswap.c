/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/21 18:21:19 by acollet           #+#    #+#             */
/*   Updated: 2015/03/27 18:25:22 by acollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstswap(t_list **head, t_list **node1, t_list **node2)
{
	t_list	*tmp;

	tmp = (*node2)->next;
	(*node2)->next = *node1;
	(*node2)->prev = (*node1)->prev;
	tmp->prev = *node1;
	(*node1)->prev = *node2;
	if ((*head) == (*node1))
		*head = *node2;
	else if ((*head) == (*node2))
		*head = *node1;
	(*node1)->next = tmp;
	return (1);
}
