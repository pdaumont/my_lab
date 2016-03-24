/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrevert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/02 12:11:11 by acollet           #+#    #+#             */
/*   Updated: 2014/12/02 12:14:27 by acollet          ###   ########.fr       */
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
