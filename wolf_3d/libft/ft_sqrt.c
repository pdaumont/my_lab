/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 12:02:59 by acollet           #+#    #+#             */
/*   Updated: 2014/11/12 17:16:14 by acollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double	ft_sqrt(double x)
{
	double	val;
	int		i;
	int		loop;

	val = 1;
	i = 0;
	loop = 20;
	while (i < loop)
	{
		val = (val + x / val) / 2;
		i++;
	}
	return (val);
}