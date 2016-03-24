/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ntoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/26 14:21:58 by acollet           #+#    #+#             */
/*   Updated: 2014/12/26 14:38:04 by acollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ntoa(unsigned long n, int base, int caps)
{
	static char		buf[65];
	char			*ptr;

	ptr = &buf[sizeof(buf) - 1];
	*ptr = '\0';
	while (1)
	{
		*--ptr = "0123456789abcdef"[n % base];
		n /= base;
		if (n == 0)
			break ;
	}
	return (caps ? ft_strtoupper(ptr) : ptr);
}
