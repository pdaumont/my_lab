/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddqueue.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdaumont <pdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/14 18:22:36 by pdaumont          #+#    #+#             */
/*   Updated: 2015/03/14 18:22:38 by pdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddqueue(t_list **alst, t_list *n)
{
	t_list	*last;

	if (!*alst)
		*alst = n;
	else
	{
		last = ft_lstlast(*alst);
		last->next = n;
	}
}
