/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdaumont <pdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 11:24:22 by pdaumont          #+#    #+#             */
/*   Updated: 2014/12/04 18:27:22 by pdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	size_t ls1;
	size_t ls2;
	size_t n;

	ls1 = ft_strlen((char *)s1);
	ls2 = ft_strlen((char *)s2);
	if (ls1 <= ls2)
		n = ls1;
	else
		n = ls2;
	return (ft_memcmp((void *)s1, (void*)s2, n + 1));
}
