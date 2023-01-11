/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaruell <llaruell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 07:51:12 by llaruell          #+#    #+#             */
/*   Updated: 2023/01/03 07:51:12 by llaruell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_H
# define STRUCTURE_H

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
}		t_tex;

typedef struct s_camera
{
	t_vector	direction;
	t_vector	position;
	t_vector	plane;
}	t_camera;

typedef struct s_raycast
{
	t_vector	direction;
	t_vector	delta;
	t_vector	side_dist;
	t_coord		step;
	t_vector	map;
	double		perp_wall_dist;
	int			side;
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
	t_tex			wall[4];
	unsigned int	sky;
	unsigned int	floor;
	t_move			move;
	t_speed			speed;
	int				start_orientation;
	int				frametime;
}		t_game;

#endif