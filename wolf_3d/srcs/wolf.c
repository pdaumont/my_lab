/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollet <acollet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 17:34:54 by acollet           #+#    #+#             */
/*   Updated: 2015/05/12 15:41:24 by acollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mlx.h"
#include "libft.h"
#include "wolf.h"

static void		error(int errnu)
{
	if (errnu == E_USG)
		ft_putendl_fd("usage: ./wolf map_file", 2);
	else if (errnu == E_INIT)
		ft_putendl_fd("Init Error", 2);
	else if (errnu == E_MAP)
		ft_putendl_fd("Map Error", 2);
	exit(0);
}

static int		init(char *fname, t_app *app)
{
	if (load_data(fname, &(app->map)) != 1
		|| !(app->env.mlx = mlx_init())
		|| !(app->env.win = mlx_new_window(app->env.mlx, RES_X, RES_Y, WNAME)))
		return (0);
	mlx_do_key_autorepeatoff(app->env.mlx);
	mlx_hook(app->env.win, 2, (1L << 0), &key_press, app);
	mlx_hook(app->env.win, 3, (1L << 1), &key_release, app);
	app->cam.plane = SETD2D(0.0, 0.66);
	app->player.dir = SETD2D(1.0, 1.0);
	app->player.pos = SETD2D(3.0, 3.0);
	app->player.move_backward = 0;
	app->player.move_forward = 0;
	app->player.strafe_right = 0;
	app->player.strafe_left = 0;
	app->player.turn_right = 0;
	app->player.turn_left = 0;
	app->player.move_speed = 0.08;
	app->player.rot_speed = 0.03;
	return (1);
}

int				checkmap(char *s, int i, int rows)
{
	int		j;
	int		len;

	j = 0;
	len = ft_strlen(s);
	if (rows <= 2)
		return (-1);
	while (s[j] != '\0')
	{
		if (((i == 0 || i == rows - 1) && (s[j] != '1' && s[j] != ' '))
			|| ((i > 0 && i < rows && (j == 0 || j == len - 1))
			&& (s[j] != '1' && s[j] != ' '))
			|| ((i > 0 && i < rows) && (s[j] != '0'
				&& s[j] != '1' && s[j] != ' ')))
		{
			error(E_MAP);
			return (-1);
		}
		j++;
	}
	if (j <= 2)
		return (-1);
	return (1);
}

int				main(int argc, char **argv)
{
	t_app	app;

	if (argc != 2)
		error(E_USG);
	if (!init(argv[1], &app))
		error(E_INIT);
	mlx_expose_hook(app.env.win, &expose_event, &app);
	mlx_loop_hook(app.env.mlx, &loop_event, &app);
	mlx_loop(app.env.mlx);
	freetab(&(app.map));
	return (0);
}
