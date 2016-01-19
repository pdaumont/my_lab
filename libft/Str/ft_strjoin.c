/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdaumont <pdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 16:42:45 by pdaumont          #+#    #+#             */
/*   Updated: 2014/12/04 18:55:22 by pdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *dst;

	if (!s1 && !s2)
		return (NULL);
	dst = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (!s1)
		return (dst = ft_strcpy(dst, s2));
	else if (!s2)
		return (dst = ft_strcpy(dst, s1));
	if (!dst)
		return (NULL);
	dst = ft_strcpy(dst, s1);
	dst = ft_strcat(dst, s2);
	return (dst);
}
