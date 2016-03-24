/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdaumont <pdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 17:28:32 by pdaumont          #+#    #+#             */
/*   Updated: 2015/03/14 17:14:52 by pdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int i, int fd)
{
	if (i == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else
	{
		if (i < 0)
		{
			ft_putchar_fd('-', fd);
			i = -i;
		}
		if (i > 9)
		{
			ft_putnbr_fd(i / 10, fd);
			ft_putnbr_fd(i % 10, fd);
		}
		else
			ft_putchar_fd(i + 48, fd);
	}
}
