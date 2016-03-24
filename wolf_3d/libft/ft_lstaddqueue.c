/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddqueue.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 15:25:34 by acollet           #+#    #+#             */
/*   Updated: 2015/03/27 18:25:48 by acollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddqueue(t_list **alst, t_list *new)
{
	t_list	*last;

	if (!*alst)
		*alst = new;
	else
	{
		last = ft_lstlast(*alst);
		last->next = new;
		new->prev = last;
	}
}
