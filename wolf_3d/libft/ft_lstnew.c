/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 19:40:02 by acollet           #+#    #+#             */
/*   Updated: 2015/03/27 18:15:59 by acollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*e;

	e = (t_list *)ft_memalloc(sizeof(t_list));
	if (!e)
		return (NULL);
	if (!content)
	{
		e->content = NULL;
		e->content_size = 0;
	}
	else
	{
		if (!(e->content = ft_memalloc(content_size)))
			return (NULL);
		ft_memcpy(e->content, content, content_size);
		e->content_size = content_size;
	}
	e->next = NULL;
	e->prev = NULL;
	return (e);
}
