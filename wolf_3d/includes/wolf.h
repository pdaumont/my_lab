/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollet <acollet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 17:38:18 by acollet           #+#    #+#             */
/*   Updated: 2015/05/12 15:09:21 by acollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# define RES_X	1280
# define RES_Y	800
# define WNAME	"wolf3d"
# define SPEED	1

# define SETI2D(x,y) ((t_int2d){(x), (y)})
# define SETD2D(x,y) ((t_pt2d){(x), (y)})

enum			e_err
{
	NUL,
	E_INIT,
	E_USG,
	E_MAP
};

typedef struct	s_int2d
{
	int	x;
	int	y;
}				t_int2d;

typedef struct	s_pt2d
{
	double	x;
	double	y;
}				t_pt2d;

typedef struct	s_line2d
{
	t_int2d	p1;
	t_int2d	p2;
}				t_line2d;

typedef struct	s_cam
{
	t_pt2d	plane;
}				t_cam;

typedef struct	s_img
{
	char	*data;
	int		lsize;
	int		bpp;
	int		endian;
}				t_img;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
}				t_env;

typedef struct	s_player
{
	t_pt2d	pos;
	t_pt2d	dir;
	double	move_speed;
	double	rot_speed;
	int		move_forward;
	int		move_backward;
	int		strafe_left;
	int		strafe_right;
	int		turn_left;
	int		turn_right;
	int		run;
}				t_player;

typedef struct	s_map
{
	int		rows;
	int		**tab;
}				t_map;

typedef struct	s_ray
{
	t_pt2d		rpos;
	t_pt2d		rdir;
	t_pt2d		deltadist;
	t_pt2d		sidedist;
	t_int2d		map;
	t_int2d		step;
	int			hit;
	int			side;
	int			lineheight;
	int			drawstart;
	int			drawend;
	int			color;
}				t_ray;

typedef struct	s_app
{
	t_env		env;
	t_map		map;
	void		*img;
	t_cam		cam;
	t_player	player;
	t_ray		ray;
}				t_app;

int				checkmap(char *s, int i, int rows);
int				load_data(char *fname, t_map *map);
void			freetab(t_map *map);

int				expose_event(t_app *app);
int				key_press(int keycode, t_app *app);
int				key_release(int keycode, t_app *app);
int				loop_event(t_app *app);

void			raycasting_loop(t_app *app);
void			draw_line(t_line2d line, t_app *app, unsigned int color);
void			draw_point(t_int2d pt, t_app *app, unsigned int color);

void			turn_right(t_app *app);
void			turn_left(t_app *app);
void			move_forward(t_app *app);
void			move_backward(t_app *app);

#endif
