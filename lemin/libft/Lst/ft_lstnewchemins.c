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

t_chemins	*ft_lstnewchemins(int *content, size_t content_size)
{
	t_chemins *new;

	if (!(new = (t_chemins*)malloc(sizeof(t_chemins))))
		return NULL;
	if (content == NULL)
	{
				new->content = NULL;
				new->content_size = 0;
	}
	else
	{
		if (!(new->content = ft_memalloc(content_size)))
			return (NULL);
		new->content = ft_memcpy(new->content, content, content_size);
		new->content_size = content_size;
	}
	new->next = NULL;
	return (new);
}
