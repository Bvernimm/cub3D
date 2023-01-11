/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaruell <llaruell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 14:50:29 by llaruell          #+#    #+#             */
/*   Updated: 2022/12/30 14:50:29 by llaruell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// 	**** NOTE RAYCAST
// 	side distance = distance que le rayon doit effectuer de la position 
//					de depart jusqu'au premier side x et le premier y side.
// 	delta = distance que le rayon doit traverser d'un x-side a un autre,
//			ou d'un y-side a un autre
// 	perp Wall Dist = distance équivalente à la longueur de la perpendiculaire
//					 entre le plan de caméra et le mur

/**
 * @brief Calcul les données de bases du raycast
 * 
 * @param game Variable stockant les differentes infos sur le jeu
 * @param ray Variable stockant les differentes infos sur le raycasting
 * @param cam Variable stockant les differentes infos sur la caméra
 * @param x Colonne
 */
static void	init_ray(t_game *game, t_raycast *ray, t_camera *cam, int x)
{
	double	camx;

	camx = ((2 * (double)x) / (double)game->win.width) - 1;
	set_vector(&ray->direction, cam->direction.x + cam->plane.x * camx,
		cam->direction.y + cam->plane.y * camx);
	set_vector(&ray->delta, fabs(1. / ray->direction.x),
		fabs(1. / ray->direction.y));
	set_vector(&ray->map, (int)cam->position.x, (int)cam->position.y);
	ray->step.x = 1;
	if (ray->direction.x < 0)
	{
		ray->side_dist.x = (cam->position.x - ray->map.x) * ray->delta.x;
		ray->step.x = -1;
	}
	else
		ray->side_dist.x = (ray->map.x + 1. - cam->position.x) * ray->delta.x;
	ray->step.y = 1;
	if (ray->direction.y < 0)
	{
		ray->step.y = -1;
		ray->side_dist.y = (cam->position.y - ray->map.y) * ray->delta.y;
	}
	else
		ray->side_dist.y = (ray->map.y + 1. - cam->position.y) * ray->delta.y;
}

/**
 * @brief Calcul l'orientation
 * 
 * @param ray Variable stockant les differentes infos sur le raycasting
 */
void	get_orientation(t_raycast *ray)
{
	if (ray->side)
	{
		if (ray->direction.y < 0)
			ray->wall_direction = 1;
		else
			ray->wall_direction = 2;
	}
	else
	{
		if (ray->direction.x < 0)
			ray->wall_direction = 3;
		else
			ray->wall_direction = 4;
	}
	if (ray->door == 1)
		ray->wall_direction = 5;
}

/**
 * @brief Calcul la distance perpendiculaire par rapport au mur
 * 
 * @param ray Variable stockant les differentes infos sur le raycasting
 * @param cam Variable stockant les differentes infos sur la caméra
 * @return La distance perpendiculaire par rapport au mur
 */
double	get_perp_distance(t_raycast *ray, t_camera *cam)
{
	double	pos;

	if (ray->side)
	{
		pos = (ray->map.y - cam->position.y + (1. - ray->step.y) / 2.);
		return (fabs(pos / ray->direction.y));
	}
	else
	{
		pos = (ray->map.x - cam->position.x + (1. - ray->step.x) / 2.);
		return (fabs(pos / ray->direction.x));
	}
}

/**
 * @brief Lance l'algorithme DDA
 * 
 * @param game Variable stockant les differentes infos sur le jeu
 * @param ray Variable stockant les differentes infos sur le raycasting
 * @param cam Variable stockant les differentes infos sur la caméra
 * @param hit 0
 */
void	dda(t_game *game, t_raycast *ray, int hit)
{
	ray->door = 0;
	while (!hit)
	{
		if (ray->side_dist.x < ray->side_dist.y)
		{
			ray->side_dist.x += ray->delta.x;
			ray->map.x += ray->step.x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist.y += ray->delta.y;
			ray->map.y += ray->step.y;
			ray->side = 1;
		}
		hit = check_hit(ray, game->map);
	}
}

/**
 * @brief Permet d'effectuer le raycasting
 * 
 * @param game Variable stockant les differentes infos sur le jeu
 * @param ray Variable stockant les differentes infos sur le raycasting
 * @param cam Variable stockant les differentes infos sur la caméra
 * @param x Colonne
 */
void	update_raycast(t_game *game, t_raycast *ray, t_camera *cam, int x)
{
	int	hit;

	init_ray(game, ray, cam, x);
	hit = 0;
	dda(game, ray, hit);
	ray->perp_wall_dist = get_perp_distance(ray, cam);
	get_orientation(ray);
}
