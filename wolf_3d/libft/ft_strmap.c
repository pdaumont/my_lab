/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 21:13:13 by acollet           #+#    #+#             */
/*   Updated: 2014/11/11 15:11:35 by acollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*dst;

	i = 0;
	if (!(dst = ft_strnew(ft_strlen(s))))
		return (NULL);
	while (s[i] != '\0')
	{
		dst[i] = (*f)(s[i]);
		i++;
	}
	return (dst);
}
