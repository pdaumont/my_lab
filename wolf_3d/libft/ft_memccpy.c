/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 18:05:30 by acollet           #+#    #+#             */
/*   Updated: 2014/12/03 13:40:18 by acollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*ptr_dst;
	const unsigned char	*ptr_src;
	size_t				i;

	i = 0;
	ptr_dst = (unsigned char *)dst;
	ptr_src = (const unsigned char *)src;
	while (i < n)
	{
		ptr_dst[i] = ptr_src[i];
		if (ptr_src[i] == (unsigned char)c)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
