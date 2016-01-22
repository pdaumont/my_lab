/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdaumont <pdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 18:33:53 by pdaumont          #+#    #+#             */
/*   Updated: 2014/11/25 18:21:20 by pdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	len;
	size_t	i;
	char	*t;

	if (!s)
		return (NULL);
	i = 0;
	t = (char *)s;
	len = ft_strlen((char *)s);
	while (i <= len)
	{
		if (t[i] == (char)c)
		{
			t = &t[i];
			return (t);
		}
		i++;
	}
	return (NULL);
}
