/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollet <acollet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/07 13:21:44 by acollet           #+#    #+#             */
/*   Updated: 2015/05/07 14:37:33 by acollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "wolf.h"

void	move_forward(t_app *app)
{
	if (!(app->map.tab)[(int)(app->player.pos.x + app->player.dir.x
		* app->player.move_speed)][(int)app->player.pos.y])
		app->player.pos.x += app->player.dir.x * app->player.move_speed;
	if (!(app->map.tab)[(int)(app->player.pos.x)][(int)(app->player.pos.y
		+ app->player.dir.y * app->player.move_speed)])
		app->player.pos.y += app->player.dir.y * app->player.move_speed;
}

void	move_backward(t_app *app)
{
	if (!(app->map.tab)[(int)(app->player.pos.x - app->player.dir.x
		* app->player.move_speed)][(int)app->player.pos.y])
		app->player.pos.x -= app->player.dir.x * app->player.move_speed;
	if (!(app->map.tab)[(int)(app->player.pos.x)][(int)(app->player.pos.y
		- app->player.dir.y * app->player.move_speed)])
		app->player.pos.y -= app->player.dir.y * app->player.move_speed;
}

void	turn_left(t_app *app)
{
	double		dx;
	double		px;

	dx = app->player.dir.x;
	app->player.dir.x = app->player.dir.x * cos(-app->player.rot_speed)
		- app->player.dir.y * sin(-app->player.rot_speed);
	app->player.dir.y = dx * sin(-app->player.rot_speed)
		+ app->player.dir.y * cos(-app->player.rot_speed);
	px = app->cam.plane.x;
	app->cam.plane.x = app->cam.plane.x * cos(-app->player.rot_speed)
		- app->cam.plane.y * sin(-app->player.rot_speed);
	app->cam.plane.y = px * sin(-app->player.rot_speed) + app->cam.plane.y *
		cos(-app->player.rot_speed);
}

void	turn_right(t_app *app)
{
	double		dx;
	double		px;

	dx = app->player.dir.x;
	app->player.dir.x = app->player.dir.x * cos(app->player.rot_speed)
		- app->player.dir.y * sin(app->player.rot_speed);
	app->player.dir.y = dx * sin(app->player.rot_speed)
		+ app->player.dir.y * cos(app->player.rot_speed);
	px = app->cam.plane.x;
	app->cam.plane.x = app->cam.plane.x * cos(app->player.rot_speed)
		- app->cam.plane.y * sin(app->player.rot_speed);
	app->cam.plane.y = px * sin(app->player.rot_speed) + app->cam.plane.y *
		cos(app->player.rot_speed);
}
