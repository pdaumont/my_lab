/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdaumont <pdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/14 18:27:00 by pdaumont          #+#    #+#             */
/*   Updated: 2015/03/14 18:27:03 by pdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strpos(const char *str, int c)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (unsigned char)c)
			return (i);
		i++;
	}
	return (-1);
}
