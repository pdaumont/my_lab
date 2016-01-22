/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdaumont <pdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 12:04:01 by pdaumont          #+#    #+#             */
/*   Updated: 2014/11/17 14:07:37 by pdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_isspace(int c)
{
	if (c == '\n' || c == '\t' || c == '\v'
	|| c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

int				ft_atoi(const char *str)
{
	int op;
	int i;

	op = 1;
	i = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
		op = -1;
	if (*str == '+' || *str == '-')
		str++;
	while (ft_isdigit(*str))
	{
		i = i * 10 + *str - 48;
		str++;
	}
	return (op * i);
}
