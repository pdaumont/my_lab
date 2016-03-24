/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 11:17:59 by acollet           #+#    #+#             */
/*   Updated: 2014/12/03 13:33:15 by acollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int	i_s1;
	int	i_s2;
	int	diff;

	if (!s2 || ft_strlen(s2) == 0)
		return ((char *)s1);
	i_s1 = 0;
	while (s1[i_s1] != '\0')
	{
		diff = 0;
		i_s2 = 0;
		while ((s2[i_s2] != '\0') && !diff)
		{
			if (s2[i_s2] != s1[i_s1 + i_s2])
				diff = 1;
			if (s1[i_s1 + i_s2] == '\0')
				return (NULL);
			i_s2++;
		}
		if (!diff)
			return ((char *)&(s1[i_s1]));
		i_s1++;
	}
	return (NULL);
}
