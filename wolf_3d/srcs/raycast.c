/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollet <acollet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/07 10:14:05 by acollet           #+#    #+#             */
/*   Updated: 2015/05/12 15:32:20 by acollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "libft.h"
#include "wolf.h"

static void	init_ray(t_app *app, int *x)
{
	double		camx;
	t_player	plr;

	plr = app->player;
	camx = 2 * (*x) / (double)RES_X - 1;
	app->ray.rpos = plr.pos;
	app->ray.rdir = SETD2D(plr.dir.x + app->cam.plane.x * camx,
							plr.dir.y + app->cam.plane.y * camx);
	app->ray.map = SETI2D((int)app->ray.rpos.x, (int)app->ray.rpos.y);
	app->ray.deltadist = SETD2D(sqrt(1 + (app->ray.rdir.y * app->ray.rdir.y)
									/ (app->ray.rdir.x * app->ray.rdir.x)),
								sqrt(1 + (app->ray.rdir.x * app->ray.rdir.x)
									/ (app->ray.rdir.y * app->ray.rdir.y)));
	app->ray.hit = 0;
	app->ray.step.x = app->ray.rdir.x < 0 ? -1 : 1;
	app->ray.step.y = app->ray.rdir.y < 0 ? -1 : 1;
	app->ray.sidedist.x = app->ray.rdir.x < 0
		? (app->ray.rpos.x - app->ray.map.x) * app->ray.deltadist.x
		: (app->ray.map.x + 1.0 - app->ray.rpos.x) * app->ray.deltadist.x;
	app->ray.sidedist.y = app->ray.rdir.y < 0
		? (app->ray.rpos.y - app->ray.map.y) * app->ray.deltadist.y
		: (app->ray.map.y + 1.0 - app->ray.rpos.y) * app->ray.deltadist.y;
}

static void	dda(t_app *app)
{
	while (app->ray.hit == 0)
	{
		if (app->ray.sidedist.x < app->ray.sidedist.y)
		{
			app->ray.sidedist.x += app->ray.deltadist.x;
			app->ray.map.x += app->ray.step.x;
			app->ray.side = 0;
		}
		else
		{
			app->ray.sidedist.y += app->ray.deltadist.y;
			app->ray.map.y += app->ray.step.y;
			app->ray.side = 1;
		}
		if ((app->map.tab)[app->ray.map.x][app->ray.map.y] > 0)
			app->ray.hit = 1;
	}
}

static void	calc_dist(t_app *app)
{
	double	walldist;

	walldist = (app->ray.side == 0)
		? fabs(((double)app->ray.map.x - app->ray.rpos.x
			+ (1 - (double)app->ray.step.x) / 2) / app->ray.rdir.x)
		: fabs(((double)app->ray.map.y - app->ray.rpos.y
			+ (1 - (double)app->ray.step.y) / 2) / app->ray.rdir.y);
	app->ray.lineheight = abs((int)(RES_Y / walldist));
	app->ray.drawstart = -(app->ray.lineheight) / 2 + RES_Y / 2;
	if (app->ray.drawstart < 0)
		app->ray.drawstart = 0;
	app->ray.drawend = (int)(app->ray.lineheight / 2 + RES_Y / 2);
	if (app->ray.drawend >= RES_Y)
		app->ray.drawend = RES_Y - 1;
	if (app->ray.side == 0 && (int)app->player.pos.x >= app->ray.map.x)
		app->ray.color = 0xAAA0000;
	else if (app->ray.side == 0 && (int)app->player.pos.x < app->ray.map.x)
		app->ray.color = 0x005500;
	else if (app->ray.side == 1 && (int)app->player.pos.y >= app->ray.map.y)
		app->ray.color = 0x000055;
	else if (app->ray.side == 1 && (int)app->player.pos.y < app->ray.map.y)
		app->ray.color = 0x5500AA;
}

void		raycasting_loop(t_app *app)
{
	int			x;
	t_line2d	line;

	x = 0;
	while (++x < RES_X)
	{
		init_ray(app, &x);
		dda(app);
		calc_dist(app);
		line.p1.x = x;
		line.p1.y = app->ray.drawstart;
		line.p2.x = x;
		line.p2.y = app->ray.drawend;
		draw_line(line, app, app->ray.color);
		line.p1.y = 0;
		line.p2.y = app->ray.drawstart;
		app->ray.color = 0x008db8;
		draw_line(line, app, app->ray.color);
		line.p1.y = app->ray.drawend;
		line.p2.y = RES_Y;
		app->ray.color = 0x777777;
		draw_line(line, app, app->ray.color);
	}
}
