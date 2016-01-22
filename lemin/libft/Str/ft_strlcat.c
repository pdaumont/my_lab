/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdaumont <pdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 17:15:57 by pdaumont          #+#    #+#             */
/*   Updated: 2014/11/17 14:22:26 by pdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	len_sd;
	size_t	len_src;
	size_t	size_o;

	size_o = size;
	len_src = ft_strlen(src);
	len_sd = ft_strlen(dst) + len_src;
	i = 0;
	while (dst[i] && size)
	{
		size--;
		i++;
	}
	if (size == 0)
		return (size_o + len_src);
	j = 0;
	while (src[j] && size > 1)
	{
		dst[i++] = src[j++];
		size--;
	}
	dst[i] = 0;
	return (len_sd);
}
