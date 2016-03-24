/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 19:54:21 by acollet           #+#    #+#             */
/*   Updated: 2014/11/18 19:48:33 by acollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*list;

	if (alst != NULL && *alst != NULL)
	{
		list = *alst;
		*alst = (*alst)->next;
		(*del)(list->content, list->content_size);
		free(list);
	}
}
