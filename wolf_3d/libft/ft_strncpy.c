/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 17:17:21 by acollet           #+#    #+#             */
/*   Updated: 2014/11/06 20:22:41 by acollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t	i;

	if (dst && src)
	{
		i = 0;
		while (i < n && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
		if (i < n)
			while (i < n)
				dst[i++] = '\0';
	}
	return (dst);
}
