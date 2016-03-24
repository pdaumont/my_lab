/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 21:23:16 by acollet           #+#    #+#             */
/*   Updated: 2014/11/11 15:19:45 by acollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*dst;

	i = 0;
	if (!(dst = ft_strnew(ft_strlen(s))))
		return (NULL);
	while (s[i] != '\0')
	{
		dst[i] = (*f)(i, s[i]);
		i++;
	}
	return (dst);
}
