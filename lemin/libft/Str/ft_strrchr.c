/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdaumont <pdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 19:18:01 by pdaumont          #+#    #+#             */
/*   Updated: 2014/12/04 18:00:06 by pdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;
	char	*t;

	t = (char *)s;
	len = ft_strlen((char *)s);
	while ((int)len >= 0)
	{
		if (t[len] == (char)c)
		{
			t = &t[len];
			return (t);
		}
		len--;
	}
	return (NULL);
}
