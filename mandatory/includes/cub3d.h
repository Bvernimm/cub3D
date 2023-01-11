/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvernimm <bvernimm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 07:51:08 by llaruell          #+#    #+#             */
/*   Updated: 2023/01/03 13:49:37 by bvernimm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <sys/types.h>
# include <sys/stat.h>
# include "mlx.h"
# include <stdio.h>
# include <sys/time.h>
# include <fcntl.h>

# include "structure.h"
# include "constantes.h"
# include "parsing.h"

// ==== ENGINE ====
// -- CAMERA

void	move_pos(t_game *game, t_camera *cam, int id);
void	decal_pos(t_game *game, t_camera *cam, int id);
void	rotate_cam(t_game *game, int id);

// -- DRAW

void	draw(t_game *game);
void	draw_font(t_game *game);
void	draw_floor_sky(t_game *game, t_raycast *ray);
void	pixel_draw(int x, int y, int color, t_game *game);

// -- MOVE

void	move(t_game *game);

// -- MOVE_UTILS

int		check_pos(char **map, double posx, double posy);
void	cos_sin(t_vector *rot, double speed);

// -- RAYCAST

void	update_raycast(t_game *game, t_raycast *ray, t_camera *cam, int i);

// -- SCREEN

void	update_screen(t_game *game, int i, int h);

// -- SPEED

void	update_speed(t_game *game);

// -- TEXTURES

void	load_textures(t_game *game);
int		get_color_tex(t_tex *tex);

// -- WALL

void	draw_wall(t_game *game, t_raycast *ray);

// ---- KEY
// -- HANDLE_KEY

int		is_moving_key(int key);
int		is_special_key(int key);

// -- KEY_PRESSED

int		key_pressed(int key, t_game *game);

// -- KEY_RELEASED

int		key_released(int key, t_game *game);

// ==== GENERAL
// -- ERROR

void	free_matrice(char **matrice);
void	print_simple_error(char *err);
void	print_error(t_game *game, char *err);
int		exit_game(t_game *game);

// -- LOOP

int		loop(t_game *game);

// == UTILS

// -- GET_POS_PLAYER

void	get_pos_player(t_game *game, char **map);

// -- MAP_UTILS

int		in_map(char **map, int x, int y);

// -- SET_NATIF

void	set_int_value(int *old, int new);
void	set_double_value(double	*old, double new);

// -- SET_STRUCT

void	set_vector(t_vector *vector, double x, double y);
void	set_coord(t_coord *coord, int x, int y);
void	copy_vector(t_vector *old, t_vector new);
void	copy_coord(t_coord *old, t_coord new);

// == STRING

// -- MATRICE_MANIP

int		get_array(char **array);

// -- STRING_MANIP

int		ft_strlen(const char *str);
char	*ft_strdup(const char *s1);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);

#endif