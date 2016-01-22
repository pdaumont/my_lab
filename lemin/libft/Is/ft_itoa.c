/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdaumont <pdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 14:07:57 by pdaumont          #+#    #+#             */
/*   Updated: 2014/12/04 19:52:49 by pdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_intlen(int i)
{
	int len;
	int temp;

	len = 1;
	temp = i;
	if (i < 0)
	{
		len++;
		temp = temp * -1;
	}
	while (temp / 10 != 0)
	{
		len++;
		temp = temp / 10;
	}
	return (len + 1);
}

char				*ft_itoa(int i)
{
	char	*s;
	int		j;
	int		temp;
	int		len;

	if (i == -2147483648)
		return ("-2147483648");
	j = 0;
	len = ft_intlen(i);
	s = (char*)malloc(sizeof(char) * len);
	if (i < 0)
	{
		s[j++] = '-';
		i = i * -1;
		len--;
	}
	while (len - 1)
	{
		temp = i / ft_pow(10, len - 2);
		s[j++] = temp + 48;
		i = i - temp * ft_pow(10, len - 2);
		len--;
	}
	s[j] = '\0';
	return (s);
}
