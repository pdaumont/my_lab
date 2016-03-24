/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 14:33:15 by acollet           #+#    #+#             */
/*   Updated: 2014/11/06 20:23:07 by acollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	size_t len;

	if (dst && src)
	{
		len = ft_strlen(src);
		dst = (char *)ft_memcpy((void *)dst, (void *)src, len);
		dst[len] = '\0';
	}
	return (dst);
}
