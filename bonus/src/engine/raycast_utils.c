/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaruell <llaruell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 14:48:46 by llaruell          #+#    #+#             */
/*   Updated: 2022/12/30 14:48:46 by llaruell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Check si le rayon touche un mur
 * 
 * @param ray Variable stockant les differentes infos sur le raycasting
 * @param map Map du jeu
 * @return 1 si on touche un mur, sinon 0
 */
int	check_hit(t_raycast *ray, char **map)
{
	if (in_map(map, ray->map.x, ray->map.y) == -1)
	{
		if (ray->side)
			ray->map.y -= ray->step.y;
		else
			ray->map.x -= ray->step.x;
		return (1);
	}
	else if (map[(int)ray->map.y][(int)ray->map.x] == '1')
		return (1);
	else if (map[(int)ray->map.y][(int)ray->map.x] == '2')
	{
		ray->door = 1;
		return (1);
	}
	return (0);
}
