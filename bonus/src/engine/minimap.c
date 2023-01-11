/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaruell <llaruell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 14:51:56 by llaruell          #+#    #+#             */
/*   Updated: 2023/01/03 11:19:11 by llaruell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Retourne le couleur de la case en fonction de sa position sur la carte
 * 
 * @param game Structure contenant nos données générales
 * @param x 
 * @param y 
 * @return Couleur de la case
 */
static int	get_case_color(t_game *game, int x, int y)
{
	char	case_map;

	case_map = 0;
	if (in_map(game->map, x, y) == 1)
		case_map = game->map[y][x];
	if (case_map == '1' || case_map == ' ')
		return (0x182026);
	else if (case_map == '2' || case_map == '3')
		return (0xbf6c5a);
	else if (case_map == '4' || case_map == 'c' || case_map == 'C'
		|| case_map == 'b' || case_map == 'B' || case_map == '7'
		|| case_map == '8' || case_map == '9')
		return (0x264026);
	else if (case_map == '5')
		return (0xf2c095);
	else if (x == (int)game->camera.position.x
		&& y == (int)game->camera.position.y)
		return (0xb0433f);
	if (game->camera.direction.x < 0. && game->camera.direction.y > 1.)
		return (0x383e42);
	return (0x2e6268);
}

/**
 * @brief Permet de dessiner une case de la minimap
 * 
 * @param game Structure contenant nos données générales
 * @param start Coordonnées de début de dessin
 * @param end Coordonnées de fin de dessin
 * @param color Code couleur 
 */
static void	draw_case(t_game *game, t_coord start, t_coord end, int color)
{
	int	i;
	int	j;

	i = start.y;
	while (++i <= end.y)
	{
		j = start.x;
		while (++j <= end.x)
			pixel_draw(j, i, color, game);
	}
}

/**
 * @brief Get the pos drawing object
 * 
 * @param game Structure contenant nos données générales 
 * @param x Position en abscisse
 * @param y Position en ordonnée
 * @param color Code couleur
 */
void	get_pos_drawing(t_game *game, int x, int y, int color)
{
	t_coord	start;
	t_coord	end;
	int		rows;
	int		columns;

	rows = get_array(game->map);
	columns = ft_strlen(game->map[0]);
	set_coord(&start,
		game->win.width - (columns * 5) - 5 + (x * 5),
		game->win.height - (rows * 5) - 5 + (y * 5));
	set_coord(&end,
		game->win.width - (columns * 5) + (x * 5),
		game->win.height - (rows * 5) + (y * 5));
	draw_case(game, start, end, color);
}

/**
 * @brief Permet de dessiner une minimap
 * 
 * @param game Structure contenant nos données générales
 */
void	draw_minimap(t_game *game)
{
	int	i;
	int	j;
	int	rows;
	int	columns;

	i = -1;
	rows = get_array(game->map);
	columns = ft_strlen(game->map[0]);
	while (++i < rows)
	{
		j = -1;
		while (++j < columns)
			get_pos_drawing(game, j, i, get_case_color(game, j, i));
	}
}
