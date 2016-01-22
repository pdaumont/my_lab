/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrevert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdaumont <pdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/14 18:24:08 by pdaumont          #+#    #+#             */
/*   Updated: 2015/03/14 18:24:11 by pdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstrevert(t_list **lst)
{
	t_list	*prev;
	t_list	*cur;
	t_list	*next;

	if (!lst)
		return ;
	prev = NULL;
	cur = NULL;
	cur = *lst;
	while (cur != NULL)
	{
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
		next = NULL;
	}
	*lst = prev;
}
