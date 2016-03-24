/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdaumont <pdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/14 18:22:47 by pdaumont          #+#    #+#             */
/*   Updated: 2015/03/14 18:22:49 by pdaumont         ###   ########.fr       */
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
