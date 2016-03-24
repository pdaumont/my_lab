/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strconcat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/05 18:37:37 by acollet           #+#    #+#             */
/*   Updated: 2014/12/05 18:38:30 by acollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strconcat(char **s1, const char *s2)
{
	char	*temp;

	if (s2 == NULL)
		return ;
	if (*s1 == NULL)
		*s1 = ft_strdup(s2);
	else
	{
		temp = ft_strdup(*s1);
		ft_strdel(s1);
		*s1 = ft_strjoin(temp, s2);
		ft_strdel(&temp);
	}
}
