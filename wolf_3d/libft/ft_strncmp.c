/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 11:58:59 by acollet           #+#    #+#             */
/*   Updated: 2014/11/11 19:29:22 by acollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t len_s1;
	size_t len_s2;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	len_s1 = (len_s1 <= len_s2) ? len_s1 + 1 : len_s2 + 1;
	len_s1 = (len_s1 <= n) ? len_s1 : n;
	return (ft_memcmp(s1, s2, len_s1));
}
