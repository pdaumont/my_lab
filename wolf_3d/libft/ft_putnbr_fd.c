/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 15:27:49 by acollet           #+#    #+#             */
/*   Updated: 2014/11/21 18:23:47 by acollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int	limit;

	limit = (n == -2147483648) ? 1 : 0;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	if (limit)
	{
		ft_putnbr_fd(214748364, fd);
		ft_putnbr_fd(8, fd);
	}
	else if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else
		ft_putchar_fd(n + 48, fd);
}
