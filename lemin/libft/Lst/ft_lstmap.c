/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdaumont <pdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/14 18:23:48 by pdaumont          #+#    #+#             */
/*   Updated: 2015/03/14 18:23:51 by pdaumont         ###   ########.fr       */
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
