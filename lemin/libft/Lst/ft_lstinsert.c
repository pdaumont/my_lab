/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstinsert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdaumont <pdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/14 18:23:13 by pdaumont          #+#    #+#             */
/*   Updated: 2015/03/14 18:23:17 by pdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstinsert(t_list *list, t_list **bef, t_list **node)
{
	if (list != NULL)
	{
		(*node)->next = (*bef)->next;
		(*bef)->next = *node;
	}
}
