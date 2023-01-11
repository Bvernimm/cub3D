/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvernimm <bvernimm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 15:03:45 by llaruell          #+#    #+#             */
/*   Updated: 2023/01/05 11:11:41 by bvernimm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_H
# define STRUCTURE_H

# include <pthread.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

typedef struct s_rgb
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
}	t_rgb;

typedef struct s_coord
{
	int	x;
	int	y;
}				t_coord;

typedef struct s_vector
{
	double	x;
	double	y;
}				t_vector;

typedef struct s_speed
{
	double	move;
	double	rotation;
	double	q_move;
	double	q_rota;
}	t_speed;

typedef struct s_move
{
	int	forward;
	int	backward;
	int	walk_left;
	int	walk_right;
	int	left;
	int	right;
}	t_move;

typedef struct s_tex
{
	void	*img;
	char	*path;
	int		height;
	int		width;
	char	*ptr;
	int		nb_pxl;
	int		bpp;
	int		size_line;
	int		endian;
	int		x;
	int		y;
	t_coord	start;
	t_coord	end;
}		t_tex;

typedef struct s_calcul_sp
{
	t_vector	transform;
	t_vector	pos;
	t_coord		start;
	t_coord		end;
	int			width;
	int			height;
	int			screen_x;
}	t_calcul_sp;

typedef struct s_sprite
{
	t_tex		tex;
	t_vector	coord;
	double		distance;
	int			number;
	char		type;
	int			is_visible;
}	t_sprite;

typedef struct s_camera
{
	t_vector	direction;
	t_vector	position;
	t_vector	plane;
}	t_camera;

typedef struct s_event
{
	char		type;
	t_vector	coord;
	int			is_draw;
}	t_event;

typedef struct s_control
{
	int				endgame;
	int				menu;
	int				mouse;
	int				use_mouse;
	int				sprint;
	int				start;
	int				is_thread;
	int				nb_key;
	int				level;
	int				shade;
	int				id_doc;
	int				is_reading;
	int				cutscene;
}	t_control;

typedef struct s_player
{
	int				is_play;
	int				id_song;
	int				duration;
	int				end;
	pthread_mutex_t	end_td;
	pthread_mutex_t	play;
	pthread_mutex_t	song;
	pthread_t		thread;
	pthread_cond_t	cond_signal;
}	t_player;

typedef struct s_raycast
{
	t_vector	direction;
	t_vector	delta;
	t_vector	side_dist;
	t_coord		step;
	t_vector	map;
	double		perp_wall_dist;
	int			side;
	int			door;
	double		wall_x;
	double		cam_x;
	int			wall_direction;
	int			column;
	int			height;
}	t_raycast;

typedef struct s_windows
{
	void	*mlx_ptr;
	void	*img;
	void	*addr;
	int		bitesparpixel;
	int		sizeline;
	int		endian;
	int		height;
	int		width;
}	t_windows;

typedef struct s_game
{
	void			*mlx;
	char			**map;
	t_windows		win;
	t_camera		camera;
	t_raycast		ray;
	t_tex			wall[5];
	unsigned int	sky;
	unsigned int	floor;
	t_move			move;
	t_speed			speed;
	int				start_orientation;
	int				frametime;
	int				frames;
	int				nb_sprites;
	double			*perp_wall;
	t_sprite		*sprites;
	int				nb_enemies;
	int				index_enemy;
	t_control		control;
	t_player		player;
	int				thread;
	t_tex			t_sky;
	t_tex			t_floor;
}		t_game;

#endif