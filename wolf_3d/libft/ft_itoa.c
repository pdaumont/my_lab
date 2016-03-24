/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 11:40:12 by acollet           #+#    #+#             */
/*   Updated: 2014/12/17 17:59:09 by acollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*limit(int n)
{
	char	*str;

	str = n == -2147483648 ? ft_strdup("-2147483648") : ft_strdup("2147483647");
	return (str);
}

char			*ft_itoa(int n)
{
	char	*str;
	size_t	len;
	size_t	i;
	int		isneg;
	double	pow;

	len = 1;
	pow = 0.0f;
	if (n == -2147483648 || n == 2147483647)
		return (limit(n));
	(isneg = (n < 0)) ? n *= -1 : 0;
	while ((int)ft_pow(10.0f, (double)len) <= n)
		len++;
	if (!(str = ft_strnew(isneg ? len + 1 : len)))
		return (NULL);
	(isneg) ? str[0] = '-' : 0;
	i = len;
	while (i)
	{
		pow = ft_pow(10.0f, (double)i - 1.0f);
		str[(len - i) + (isneg ? 1 : 0)] = n / pow + 48;
		n = n % (int)ft_pow(10.0f, (double)i - 1.0f);
		i--;
	}
	return (str);
}
