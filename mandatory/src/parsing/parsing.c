/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvernimm <bvernimm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 07:49:58 by llaruell          #+#    #+#             */
/*   Updated: 2023/01/04 14:47:49 by bvernimm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parsing(int argc, char **argv, t_game *game)
{
	int	fd;

	if (argc != 2)
		print_simple_error("bad argument\n");
	if (check_file_name(argv[1]) == 1)
		print_simple_error("bad file name\n");
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		print_simple_error("Could not open the map\n");
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
	load_textures(game);
	init_move_and_speed(&game->move, &game->speed);
	return (0);
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
	else if (file[i] && file[i] == 'F')
		i = get_color(file, i + 1, &game->floor);
	else if (file[i] && file[i] == 'C')
		i = get_color(file, i + 1, &game->sky);
	else
		ft_simple_error("bad identifier\n", file);
	if (recursif < 6)
		i = get_texture(file, game, recursif + 1, i);
	return (i);
}

int	get_color(char *file, int i, unsigned int *color)
{
	t_rgb	tmp;

	while (file[i] == ' ' || file[i] == '\t')
		i++;
	tmp.r = ft_atoi_from(file, i);
	while (file[i] && file[i - 1] != ',')
		i++;
	tmp.g = ft_atoi_from(file, i);
	i++;
	while (file[i] && file[i - 1] != ',')
		i++;
	tmp.b = ft_atoi_from(file, i);
	while (file[i] >= '0' && file[i] <= '9')
		i++;
	if (file[i] != '\n')
		ft_simple_error("bad rgb number\n", file);
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
