/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 17:51:54 by acollet           #+#    #+#             */
/*   Updated: 2014/11/06 20:21:29 by acollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	len;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	while (s[len] != (char)c && len >= 0)
		len--;
	return (len < 0 ? NULL : (char *)s + len);
}
