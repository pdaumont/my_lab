/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 14:28:31 by acollet           #+#    #+#             */
/*   Updated: 2014/11/18 19:44:14 by acollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*var;

	var = (void *)malloc(size);
	if (var == NULL)
		return (NULL);
	ft_bzero(var, size == 0 ? 1 : size);
	return (var);
}
