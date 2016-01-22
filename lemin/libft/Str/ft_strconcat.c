/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strconcat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdaumont <pdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/14 18:25:28 by pdaumont          #+#    #+#             */
/*   Updated: 2015/03/14 18:25:30 by pdaumont         ###   ########.fr       */
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
