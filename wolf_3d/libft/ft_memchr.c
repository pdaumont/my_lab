/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 15:02:47 by acollet           #+#    #+#             */
/*   Updated: 2014/11/18 19:29:46 by acollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*ptr;

	if (s == NULL)
		return (NULL);
	ptr = (char *)s;
	while (n--)
	{
		if (*ptr == (char)c)
			return ((void *)&(*ptr));
		ptr++;
	}
	return (NULL);
}
