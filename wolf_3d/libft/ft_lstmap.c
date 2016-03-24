/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 20:25:40 by acollet           #+#    #+#             */
/*   Updated: 2014/11/12 17:53:57 by acollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*next;
	t_list	*temp;

	if (!lst)
		return (NULL);
	if (!(new = (*f)(ft_lstnew(lst->content, lst->content_size))))
		return (NULL);
	next = new;
	while ((lst = lst->next))
	{
		if (!(temp = (*f)(ft_lstnew(lst->content, lst->content_size))))
			return (NULL);
		next->next = temp;
		next = temp;
	}
	return (new);
}
