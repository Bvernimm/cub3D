/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaruell <llaruell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 14:54:26 by llaruell          #+#    #+#             */
/*   Updated: 2023/01/03 10:47:01 by llaruell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parsing(int argc, char **argv, t_game *game)
{
	int	fd;

	if (argc != 2)
		ft_error("bad argument\n", game);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		ft_error("Could not open the map\n", game);
	check_file(fd, game);
	close (fd);
	game->mlx = mlx_init();
	if (!game->mlx)
		ft_error("MLX: Issues during initiating\n", game);
	game->win.width = SCREEN_WIDTH;
	game->win.height = SCREEN_HEIGHT;
	if (init_windows(&game->win, game->mlx))
		ft_error("MLX: Issues during creating window\n", game);
	init_camera(&game->camera, game->camera.position, game->start_orientation);
	load_textures(game, 0);
	init_move_and_speed(&game->move, &game->speed);
	check_sprites(game);
	mouse_move(game->win.width / 2 + 100, game->win.height / 2 + 100);
	init_control_value(&game->control);
	mouse_hide();
	return (0);
}

void	check_file(int fd, t_game *game)
{
	char	*file;
	int		i;

	file = read_file(fd);
	if (!file)
		ft_error("Empty File\n", game);
	i = get_texture(file, game, 1, 0);
	check_map(file, game, i);
	free (file);
}

int	get_texture(char *file, t_game *game, int recursif, int i)
{
	while (file[i] && (file[i] == ' ' || file[i] == '\n'))
		i++;
	if (file[i + 1] && file[i] == 'N' && file[i + 1] == 'O')
		i = get_path(file, i, game, 0);
	else if (file[i + 1] && file[i] == 'S' && file[i + 1] == 'O')
		i = get_path(file, i, game, 1);
	else if (file[i + 1] && file[i] == 'W' && file[i + 1] == 'E')
		i = get_path(file, i, game, 2);
	else if (file[i + 1] && file[i] == 'E' && file[i + 1] == 'A')
		i = get_path(file, i, game, 3);
	else if (file[i + 1] && file[i] == 'D' && file[i + 1] == 'O')
		i = get_path(file, i, game, 4);
	else if (file[i] && file[i] == 'F')
		i = get_color(file, i, &game->floor);
	else if (file[i] && file[i] == 'C')
		i = get_color(file, i, &game->sky);
	else
		ft_error("bad identifier\n", game);
	if (recursif < 7)
		i = get_texture(file, game, recursif + 1, i);
	return (i);
}

int	get_color(char *file, int i, unsigned int *color)
{
	t_rgb	tmp;

	tmp.r = ft_atoi_from(file, i + 1);
	while (file[i] && file[i - 1] != ',')
		i++;
	tmp.g = ft_atoi_from(file, i);
	i++;
	while (file[i] && file[i - 1] != ',')
		i++;
	tmp.b = ft_atoi_from(file, i);
	while ((file[i] >= '0' && file[i] <= '9') || file[i] == ','
		|| file[i] == ' ')
		i++;
	*color = (tmp.r << 16 | tmp.g << 8 | tmp.b);
	return (i);
}

int	get_path(char *file, int i, t_game *game, int wall)
{
	char	*path;
	int		len;

	len = 0;
	i = i + 2;
	while (file[i] == ' ')
		i++;
	while (file[i + len] && (file[i + len] != ' ' && file[i + len] != '\n'))
		len++;
	path = malloc(sizeof(char) * len + 1);
	if (!path)
		ft_error("malloc failed in get_path", game);
	len = 0;
	while (file[i + len] && (file[i + len] != ' ' && file[i + len] != '\n'))
	{	
		path[len] = file [i + len];
		len++;
	}
	path[len] = '\0';
	i = i + len;
	game->wall[wall].path = path;
	return (i);
}
