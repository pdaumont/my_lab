/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollet <acollet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/14 19:08:02 by acollet           #+#    #+#             */
/*   Updated: 2015/05/07 14:38:49 by acollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mlx.h"
#include "libft.h"
#include "wolf.h"
#include "keys.h"

static void	refresh(t_app *app)
{
	app->img = mlx_new_image(app->env.mlx, RES_X, RES_Y);
	raycasting_loop(app);
	mlx_put_image_to_window(app->env.mlx, app->env.win, app->img, 0, 0);
	mlx_destroy_image(app->env.mlx, app->img);
}

int			expose_event(t_app *app)
{
	refresh(app);
	return (0);
}

int			key_press(int keycode, t_app *app)
{
	t_player	*plr;

	plr = &(app->player);
	keycode == LSHIFT ? plr->run = 1 : 0;
	keycode == UP && !app->player.move_backward
		? app->player.move_forward = 1 : 0;
	keycode == DOWN && !app->player.move_forward
		? app->player.move_backward = 1 : 0;
	keycode == RIGHT && !app->player.turn_right
		? app->player.turn_right = 1 : 0;
	keycode == LEFT && !app->player.turn_left ? app->player.turn_left = 1 : 0;
	return (0);
}

int			key_release(int keycode, t_app *app)
{
	keycode == LSHIFT ? app->player.run = 0 : 0;
	keycode == UP ? app->player.move_forward = 0 : 0;
	keycode == DOWN ? app->player.move_backward = 0 : 0;
	keycode == LEFT ? app->player.turn_left = 0 : 0;
	keycode == RIGHT ? app->player.turn_right = 0 : 0;
	keycode == ESC ? exit(0) : 0;
	return (0);
}

int			loop_event(t_app *app)
{
	if (app->player.move_forward == 1)
		move_forward(app);
	if (app->player.move_backward == 1)
		move_backward(app);
	if (app->player.turn_left == 1)
		turn_left(app);
	if (app->player.turn_right == 1)
		turn_right(app);
	refresh(app);
	return (0);
}
