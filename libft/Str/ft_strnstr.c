/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdaumont <pdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/14 18:26:51 by pdaumont          #+#    #+#             */
/*   Updated: 2015/03/14 18:26:53 by pdaumont         ###   ########.fr       */
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
