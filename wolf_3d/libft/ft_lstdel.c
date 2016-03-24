/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 20:42:41 by acollet           #+#    #+#             */
/*   Updated: 2014/11/18 19:48:33 by acollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	if (alst != NULL && *alst != NULL)
	{
		ft_lstdel(&(*alst)->next, del);
		ft_lstdelone(&(*alst), del);
	}
}
