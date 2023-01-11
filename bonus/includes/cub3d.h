/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvernimm <bvernimm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 14:59:17 by llaruell          #+#    #+#             */
/*   Updated: 2023/01/05 10:26:46 by bvernimm         ###   ########.fr       */
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
# include <pthread.h>
# include <time.h>

# include "structure.h"
# include "constantes.h"
# include "parsing.h"

// ==== ENGINE ================================================================

// -- CAMERA

void	move_pos(t_game *game, t_camera *cam, int id);
void	decal_pos(t_game *game, t_camera *cam, int id);
void	rotate_cam(t_game *game, int id);

// -- CUTSCENE

void	cutscene(t_game *game, int frames);

// -- DA_DOOR

void	open_da_door(t_game *game);

// -- MOUSE
int		mac_mouse_hide(void);
int		mac_mouse_move(int x, int y);
int		mouse_hook(int x, int y, t_game *game);
int		mouse_move(int x, int y);
int		mouse_hide(void);

// -- CHANGE MAP

int		change_map(t_game *game, int id);

// -- DISPLAY MENU

void	menu(t_game *game);

// -- DRAW

void	draw(t_game *game);
void	draw_font(t_game *game, int color);
void	draw_floor_sky(t_game *game, t_raycast *ray);
void	pixel_draw(int x, int y, int color, t_game *game);

// -- DRAW DOCUMENT

void	draw_document(t_game *game);

// -- ENDING

void	bad_ending(t_game *game, int frames);

// -- MINIMAP

void	draw_minimap(t_game *game);

// -- MOVE

void	move(t_game *game);

// -- MOVE_UTILS

int		check_pos(char **map, double posx, double posy, t_game *game);
void	cos_sin(t_vector *rot, double speed);

// -- RAYCAST

void	update_raycast(t_game *game, t_raycast *ray, t_camera *cam, int i);

// -- RAYCAST UTILS

int		check_hit(t_raycast *ray, char **map);

// -- SCREEN

void	update_screen(t_game *game);

// -- SHADER

int		shader(double distance, int color, int shade);

// -- SKY_FLOOR

void	draw_textured_sky_floor(t_game *game, t_raycast *ray);

// -- SPEED

void	update_speed(t_game *game);

// -- TEXTURES

void	load_textures(t_game *game, int id);
void	load_sprites_tex(t_game *game, t_sprite *sprite);
int		get_color_tex(t_tex *tex);
void	load_enemy_tex(t_game *game, t_sprite *sprite, int id);

// -- WALL

void	draw_wall(t_game *game, t_raycast *ray);

// ---- DOCUMENT --------------------------------------------------------------

// -- TUTO

void	tuto1(t_game *game);
void	tuto2(t_game *game);

// -- DOCUMENT

void	document1(t_game *game);
void	document2(t_game *game);
void	document3(t_game *game);
void	document4(t_game *game);
void	document5(t_game *game);
void	document6(t_game *game);
void	document7(t_game *game);
void	document8(t_game *game);
void	document9(t_game *game);
void	document10(t_game *game);

// -- CHECK DOCUMENT

void	check_doc(t_game *game, int x, int y);

// ---- KEY -------------------------------------------------------------------

// -- ACTION KEY

void	check_event(t_game *game);

// -- HANDLE_KEY

int		is_moving_key(int key);
int		is_special_key(int key);

// -- KEY_PRESSED

int		key_pressed(int key, t_game *game);

// -- KEY_RELEASED

int		key_released(int key, t_game *game);

// ---- SPRITES ---------------------------------------------------------------

// -- ENEMY MOVE

void	handle_enemy_move(t_game *game, t_sprite *enemy);
int		handle_enemy(t_game *game, t_sprite *enemy, int frames);

// -- ENEMY MOVE UTILS

int		get_move_direction(t_coord player, t_coord *coord, int *k, int *l);
int		get_interval(int x, int y, int id);
int		player_around(t_coord player, t_coord coord);
int		collision_player(t_coord enemy, t_vector player);
int		check_move_enemy(char **map, int x, int y);

// -- SPRITES DRAW

void	draw_sprites(t_game *game);

// -- SPRITES LOAD

void	load_sprites(t_game *game);

// -- SPRITES UTILS

void	sort_sprites(t_game *game);
int		sprite_case(t_sprite *sprites, t_game *game, t_coord coord, int k);

// -- SPRITES UTILS 2

int		min_dist_sp(t_sprite a, t_sprite b, int nb_el, t_sprite *res);
int		check_already_in(t_sprite a, t_sprite *b, int count);
int		get_min(t_game *game, t_sprite *b, int count, float minimum);
void	sprites_distances(t_vector pos, t_sprite *sp, int count);
int		check_limite(int value, t_coord start, t_coord end, int id);

// ---- PLAYER ----------------------------------------------------------------

// -- CONTROLER

void	play(char *path);
void	stop(void);
void	pause_song(t_game *game);
void	resume_song(t_game *game);

// -- CHANGE SONG

void	change_song(t_game *game, int id);

// -- PLAYER_UTILS

int		get_duration(int id);
char	*get_path_song(int id);
void	init_player(t_game *game);
void	on_off_song(t_game *game);
void	change_id_song(t_game *game, int id);

// -- WAIT PLAYER

int		wait_player(t_game *game, int i);

// -- ROUTINE

void	*launch_song(void *arg);

// ==== GENERAL ===============================================================

// -- DESTROY

void	destroy_thread(t_game *game);
void	destroy_init_mutex(t_game *game);
void	exit_game_mutex(t_game *game);

// -- ERROR

void	print_simple_error(char *err);
void	print_error(t_game *game, char *err);
int		exit_game(t_game *game);
void	free_matrice(char **matrice);

// -- LOOP

int		loop(t_game *game);

// ==== UTILS =================================================================

// -- FT_SPLIT

char	**ft_split(char const *s, char c);

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

// ==== STRING ================================================================

// -- MATRICE_MANIP

int		get_array(char **array);

// -- STRING_MANIP

int		ft_strlen(const char *str);
char	*ft_strdup(const char *s1);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);

#endif