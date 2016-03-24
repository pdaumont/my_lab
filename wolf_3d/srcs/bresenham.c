/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollet <acollet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/07 11:56:19 by acollet           #+#    #+#             */
/*   Updated: 2015/05/07 14:37:54 by acollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void		bsh_init(t_line2d line, t_int2d *d, t_int2d *inc)
{
	d->x = line.p2.x - line.p1.x;
	d->y = line.p2.y - line.p1.y;
	if (d->x < 0)
		d->x = -d->x;
	if (d->y < 0)
		d->y = -d->y;
	inc->x = 1;
	if (line.p2.x < line.p1.x)
		inc->x = -1;
	inc->y = 1;
	if (line.p2.y < line.p1.y)
		inc->y = -1;
}

static void		bsh_asc(t_line2d line, t_app *app, unsigned int color)
{
	t_int2d		i;
	t_int2d		d;
	t_int2d		inc;
	t_int2d		inc2;

	bsh_init(line, &d, &inc);
	draw_point(line.p1, app, color);
	i.y = 2 * d.y - d.x;
	inc2.x = 2 * (d.y - d.x);
	inc2.y = 2 * d.y;
	i.x = 0;
	while (i.x++ < d.x)
	{
		if (i.y >= 0)
		{
			line.p1.y += inc.y;
			i.y += inc2.x;
		}
		else
			i.y += inc2.y;
		line.p1.x += inc.x;
		draw_point(line.p1, app, color);
	}
}

static void		bsh_desc(t_line2d line, t_app *app, unsigned int color)
{
	t_int2d		i;
	t_int2d		d;
	t_int2d		inc;
	t_int2d		inc2;

	bsh_init(line, &d, &inc);
	draw_point(line.p1, app, color);
	i.y = 2 * d.x - d.y;
	inc2.x = 2 * (d.x - d.y);
	inc2.y = 2 * d.x;
	i.x = 0;
	while (i.x++ < d.y)
	{
		if (i.y >= 0)
		{
			line.p1.x += inc.x;
			i.y += inc2.x;
		}
		else
			i.y += inc2.y;
		line.p1.y += inc.y;
		draw_point(line.p1, app, color);
	}
}

void			draw_line(t_line2d line, t_app *app, unsigned int color)
{
	t_int2d		d;
	t_int2d		inc;

	bsh_init(line, &d, &inc);
	if (d.x > d.y)
		bsh_asc(line, app, color);
	else
		bsh_desc(line, app, color);
}
