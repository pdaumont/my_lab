/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdaumont <pdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/17 15:03:45 by pdaumont          #+#    #+#             */
/*   Updated: 2015/11/11 16:18:45 by pdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/libft.h"

t_list	*ft_lstnew(char *content, size_t content_size)
{
	t_list *new;

	if (!(new = (t_list*)malloc(sizeof(t_list))))
		return NULL;
	if (content == NULL)
	{
		new->content = NULL;
		new->num = 0;
		new->x = 0;
		new->y = 0;
		new->content_size = 0;
		new->arcs = NULL;
		new->start = 0;
		new->end = 0;
	}
	else
	{
		if (!(new->content = ft_memalloc(content_size)))
			return (NULL);
		new->content = ft_memcpy(new->content, content, content_size);
		new->content_size = content_size;
		new->num = 0;
		new->num = 0;
		new->x = 0;
		new->y = 0;
		new->arcs = NULL;
		new->start = 0;
		new->end = 0;
	}
	new->next = NULL;
	new->prev = NULL;
	return (new);
}
