/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdaumont <pdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/17 18:19:19 by pdaumont          #+#    #+#             */
/*   Updated: 2014/12/04 18:09:15 by pdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*s;

	if (size == 0)
		return (NULL);
	s = (void *)malloc(size);
	if (!s)
		return (NULL);
	ft_bzero(s, size);
	return (s);
}
