/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollet <acollet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/07 12:03:20 by acollet           #+#    #+#             */
/*   Updated: 2015/05/07 14:38:07 by acollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "mlx.h"
#include "libft.h"
#include "wolf.h"

static int		getpos(int x, int y)
{
	if (x < 1 || x > RES_X - 1 || y < 1 || y > RES_Y - 1)
		return (-1);
	return (y * RES_X + x);
}

void			draw_point(t_int2d pt, t_app *app, unsigned int color)
{
	t_img	img;
	int		i;

	img.data = mlx_get_data_addr(app->img, &img.bpp, &img.lsize, &img.endian);
	i = getpos(pt.x, pt.y) * (img.bpp / 8);
	if (i >= 0)
	{
		img.data[i] = color & 0x0000FF;
		img.data[i + 1] = (color & 0x00FF00) >> 8;
		img.data[i + 2] = (color & 0xFF0000) >> 16;
		img.data[i + 3] = 0;
	}
}
