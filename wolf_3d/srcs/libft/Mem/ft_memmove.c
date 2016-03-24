/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 18:16:32 by acollet           #+#    #+#             */
/*   Updated: 2014/11/12 18:03:50 by acollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*temp;

	temp = (char *)malloc(sizeof(src) * (len));
	temp = ft_memcpy(temp, src, len);
	dst = (void *)ft_memcpy(dst, temp, len);
	free(temp);
	return (dst);
}
