/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 14:38:53 by acollet           #+#    #+#             */
/*   Updated: 2014/12/03 13:39:25 by acollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

char			*ft_strtrim(char const *s)
{
	int		begin;
	int		end;
	char	*str;

	if (!s)
		return (NULL);
	begin = 0;
	end = ft_strlen(s);
	while (is_space(s[begin]) && begin < end)
		begin++;
	while (is_space(s[end - 1]) && end > 0)
		end--;
	if (end - begin <= 0)
		return (ft_strnew(0));
	str = ft_strsub(s, (unsigned int)begin, (size_t)(end - begin));
	return (str);
}
