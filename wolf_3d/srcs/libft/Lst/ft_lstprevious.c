/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprevious.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdaumont <pdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/14 18:23:58 by pdaumont          #+#    #+#             */
/*   Updated: 2015/03/14 18:24:00 by pdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstprevious(t_list *head, t_list *srch)
{
	t_list	*current;

	if (!head || !srch)
		return (NULL);
	if (head == srch)
		return (NULL);
	current = head;
	while (current->next)
	{
		if (current->next == srch)
			return (current);
		current = current->next;
	}
	return (NULL);
}
