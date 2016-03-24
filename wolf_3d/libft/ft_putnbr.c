/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 15:13:51 by acollet           #+#    #+#             */
/*   Updated: 2014/11/12 17:14:54 by acollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	int	limit;

	limit = (n == -2147483648) ? 1 : 0;
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (limit)
	{
		ft_putnbr(214748364);
		ft_putnbr(8);
	}
	else if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
		ft_putchar(n + 48);
}
