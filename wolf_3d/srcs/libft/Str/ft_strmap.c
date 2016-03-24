/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdaumont <pdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 15:31:47 by pdaumont          #+#    #+#             */
/*   Updated: 2014/12/04 18:19:42 by pdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*dst;
	size_t	i;

	i = 0;
	if (!s || !(*f))
		return (NULL);
	if (!(dst = ft_strnew(ft_strlen(s))))
		return (NULL);
	while (s[i])
	{
		dst[i] = (*f)(s[i]);
		i++;
	}
	return (dst);
}
