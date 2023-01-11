/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaruell <llaruell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 07:50:32 by llaruell          #+#    #+#             */
/*   Updated: 2023/01/03 07:50:32 by llaruell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Vérifie si la position passée est dans la map
 * 
 * @param map Carte du jeu
 * @param x Position en abscisse
 * @param y Position en ordonnée
 * @return -1 si la position ne fait pas partie de la carte, sinon 1
 */
int	in_map(char **map, int x, int y)
{
	int	i;
	int	j;

	if (x < 0 || y < 0)
		return (-1);
	i = get_array(map);
	if (i < y)
		return (-1);
	j = ft_strlen(map[0]);
	if (j <= x)
		return (-1);
	return (1);
}
