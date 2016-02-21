/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdaumont <pdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/14 18:22:24 by pdaumont          #+#    #+#             */
/*   Updated: 2015/03/14 18:22:27 by pdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstaddchemins(t_chemins **alst, t_chemins *new)
{
	if (new)
	{
		new->next = *alst;
		*alst = new;
	}
}
