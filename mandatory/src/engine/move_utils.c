/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvernimm <bvernimm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 07:48:28 by llaruell          #+#    #+#             */
/*   Updated: 2023/01/03 13:44:38 by bvernimm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Permet de vérifier si la nouvelle position est
 * 			correcte
 * 
 * @param map Matrice représentant la map
 * @param posx Position en x
 * @param posy Position en y
 * @return 1 si la position est correcte, sinon 0
 */
int	check_pos(char **map, double posx, double posy)
{
	int	x;
	int	y;
	int	columns;
	int	rows;

	x = (int)floor(posx);
	y = (int)floor(posy);
	if (x < 0 && y < 0)
		return (0);
	rows = get_array(map);
	if (y >= rows)
		return (0);
	columns = ft_strlen(map[0]);
	if (x >= columns)
		return (0);
	if (map[y][x] == '1')
		return (0);
	return (1);
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
