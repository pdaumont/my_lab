/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 12:08:50 by acollet           #+#    #+#             */
/*   Updated: 2014/11/11 18:08:23 by acollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	len_dst;
	size_t	len_src;
	size_t	size_o;

	size_o = size;
	len_src = ft_strlen(src);
	len_dst = ft_strlen(dst) + len_src;
	i = 0;
	j = 0;
	while (dst[i] && size)
	{
		size--;
		i++;
	}
	if (size == 0)
		return (size_o + len_src);
	while (src[j] && size > 1)
	{
		dst[i++] = src[j++];
		size--;
	}
	dst[i] = '\0';
	return (len_dst);
}
