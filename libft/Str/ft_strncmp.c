/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdaumont <pdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 11:42:23 by pdaumont          #+#    #+#             */
/*   Updated: 2014/11/17 14:13:27 by pdaumont         ###   ########.fr       */
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
