/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdaumont <pdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/14 18:27:12 by pdaumont          #+#    #+#             */
/*   Updated: 2015/03/14 18:27:14 by pdaumont         ###   ########.fr       */
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
