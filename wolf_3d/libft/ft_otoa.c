/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_otoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/17 18:40:53 by acollet           #+#    #+#             */
/*   Updated: 2014/12/26 14:40:22 by acollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_otoa(unsigned long n)
{
	char	*s;
	int		x;
	int		i;

	x = n;
	i = 0;
	while (x != 0)
	{
		x /= 8;
		i++;
	}
	s = ft_strnew(i);
	while (i)
	{
		s[i - 1] = (n % 8) + 48;
		n /= 8;
		i--;
	}
	return (s);
}
