/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdaumont <pdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/14 18:24:17 by pdaumont          #+#    #+#             */
/*   Updated: 2015/03/14 18:24:19 by pdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstswap(t_list **head, t_list **node1, t_list **node2)
{
	t_list	*tmp;
	t_list	*prev1;
	t_list	*prev2;

	if (!(*head) || !(*node1) || !(*node2))
		return (0);
	prev1 = ft_lstprevious(*head, *node1);
	prev2 = ft_lstprevious(*head, *node2);
	if (prev1)
		prev1->next = *node2;
	if (prev2)
		prev2->next = *node1;
	tmp = (*node1)->next;
	(*node1)->next = (*node2)->next;
	(*node2)->next = tmp;
	if ((*head) == (*node1))
		*head = *node2;
	else if ((*head) == (*node2))
		*head = *node1;
	return (1);
}
