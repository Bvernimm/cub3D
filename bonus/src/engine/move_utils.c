/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaruell <llaruell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 14:50:49 by llaruell          #+#    #+#             */
/*   Updated: 2022/12/30 14:50:49 by llaruell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	same_coord(t_vector coord, int x, int y)
{
	int	coord_x;
	int	coord_y;

	coord_x = (int)floor(coord.x);
	coord_y = (int)floor(coord.y);
	if (x == coord_x && y == coord_y)
		return (1);
	return (0);
}

static int	get_collectible(t_game *game, int y, int x)
{
	int	i;

	i = -1;
	while (++i < game->nb_sprites)
	{
		if (same_coord(game->sprites[i].coord, x, y))
		{
			game->map[y][x] = '0';
			game->sprites[i].is_visible = 0;
			game->control.nb_key++;
		}
	}
	return (0);
}

/**
 * @brief Permet de vérifier si la nouvelle position est
 * 			correcte
 * 
 * @param game Variable stockant les differentes infos sur le jeu
 * @param map Matrice représentant la map
 * @param posx Position en x
 * @param posy Position en y
 * @return 1 si la position est correcte, sinon 0
 */
int	check_pos(char **map, double posx, double posy, t_game *game)
{
	int	x;
	int	y;
	int	columns;
	int	rows;

	x = (int)floor(posx);
	y = (int)floor(posy);
	if (x < 0 && y < 0)
		return (1);
	rows = get_array(map);
	if (y >= rows)
		return (1);
	columns = ft_strlen(map[0]);
	if (x >= columns)
		return (1);
	if (map[y][x] == '1' || map[y][x] == '2'
		|| (is_sprite_case(map[y][x]) && map[y][x] != '5'))
		return (1);
	if (map[y][x] == '5')
		return (get_collectible(game, y, x));
	if (map[y][x] == 'e')
		return (change_map(game, 1));
	return (0);
}

/**
 * @brief Permet d'effectuer le calcul lié aux dimensions 
 * 		de la direction et du plan de la caméra
 * 
 * @param rot Vecteur contenant les valeurs à modifier 
 * @param speed Vitesse de rotation
 */
void	cos_sin(t_vector *rot, double speed)
{
	double	x;
	double	y;

	x = rot->x * cos(speed) - rot->y * sin(speed);
	y = rot->y * cos(speed) + rot->x * sin(speed);
	set_vector(rot, x, y);
}
