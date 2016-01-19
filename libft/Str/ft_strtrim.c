/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdaumont <pdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 16:53:10 by pdaumont          #+#    #+#             */
/*   Updated: 2014/12/04 19:52:48 by pdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int			ft_isspace(int c)
{
	if (c == '\n' || c == '\t' || c == ' ')
		return (1);
	return (0);
}

char				*ft_strtrim(char const *s)
{
	size_t	start;
	size_t	end;
	size_t	i;
	char	*dst;

	if (!s)
		return (NULL);
	start = 0;
	end = ft_strlen(s);
	while (ft_isspace(s[start]))
		start++;
	while (ft_isspace(s[end - 1]))
		end--;
	if ((int)(end - start) < 0)
		return ("");
	if (!(dst = ft_strnew(end - start)))
		return (NULL);
	if (end - start <= 0)
		return (ft_strnew(0));
	i = -1;
	while (++i <= end - start - 1)
		dst[i] = s[start + i];
	return (dst);
}
