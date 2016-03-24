/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/22 11:16:06 by acollet           #+#    #+#             */
/*   Updated: 2014/12/26 14:47:47 by acollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		hvalue(int x, int caps)
{
	if (x >= 0 && x <= 9)
		return (x + 48);
	if (x >= 10 && x <= 16)
		return ((x - 10) + (!caps ? 97 : 65));
	return (0);
}

char			*ft_htoa(unsigned long n, int caps)
{
	char	*s;
	int		x;
	int		i;

	x = n;
	i = 0;
	while (x != 0)
	{
		x /= 16;
		i++;
	}
	s = ft_strnew(i);
	while (i)
	{
		s[i - 1] = hvalue(n % 16, caps);
		n /= 16;
		i--;
	}
	return (s);
}
