/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaruell <llaruell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 10:39:03 by bvernimm          #+#    #+#             */
/*   Updated: 2022/12/30 14:55:58 by llaruell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

/*parsing.c*/
int		parsing(int argc, char **argv, t_game *game);
void	check_file(int fd, t_game *game);
int		get_texture(char *file, t_game *game, int recursif, int i);
int		get_path(char *file, int i, t_game *game, int wall);
int		get_color(char *file, int i, unsigned int *color);

/*check_map.c*/
int		check_map(char *file, t_game *game, int i);
int		hole_in_map(char **map);
int		line_is_empty(char *file, int i);
int		check_char(char **map);
int		find_player(char **map, t_game *game);

/*check_map_wall.c*/
int		check_walls_1(char **map);
int		check_walls_2(char **map);
int		check_around(char **map, int i, int j);

/*make_map.c*/
char	**get_map(char *file);

/*color.c*/
int		rgb_to_int(t_rgb color);

/*utils.c*/

char	*read_file(int fd);
char	*ft_strjoin(char *file, char *tmp, int indic);
int		ft_atoi_from(char *str, int i);
int		line_len(char *file);

/*error.c*/
void	ft_error(char *str, t_game *game);
void	ft_free(t_game *game);

// -- PARSING UTILS

void	init_camera(t_camera *cam, t_vector player, int orientation);
int		init_windows(t_windows *win, void *mlx);
void	init_move_and_speed(t_move *move, t_speed *speed);
void	init_control_value(t_control *control);

// -- PARSING SPRITES

void	check_sprites(t_game *game);
int		get_index_enemy(t_sprite *sprites, int count, t_game *game);
int		is_sprite_case(char c);

// -- CHECK CARACTER

int		check_caracter(char c);

#endif