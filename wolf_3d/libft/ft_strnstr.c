/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 12:06:04 by acollet           #+#    #+#             */
/*   Updated: 2014/11/06 20:21:47 by acollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	len;
	size_t	i;
	size_t	j;

	i = 0;
	len = ft_strlen(s2);
	if (!s2)
		return ((char *)s1);
	if (!n || n < len)
		return (NULL);
	j = (n > len) ? len : n;
	while (s1[i] != '\0' && i < n)
	{
		if (n - i < j)
			return (NULL);
		if (ft_strncmp(s1 + i, s2, j) == 0)
			return (char *)(&(s1[i]));
		i++;
	}
	return (NULL);
}
