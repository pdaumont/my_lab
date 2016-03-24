/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstinsert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/21 18:52:21 by acollet           #+#    #+#             */
/*   Updated: 2015/03/27 18:17:37 by acollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstinsert(t_list *list, t_list **bef, t_list **node)
{
	if (list != NULL)
	{
		(*node)->prev = *bef;
		(*node)->next = (*bef)->next;
		(*node)->next->prev = *node;
		(*bef)->next = *node;
	}
}
