/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprevious.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/21 18:34:05 by acollet           #+#    #+#             */
/*   Updated: 2014/11/21 18:35:53 by acollet          ###   ########.fr       */
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
