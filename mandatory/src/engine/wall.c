/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaruell <llaruell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 07:48:56 by llaruell          #+#    #+#             */
/*   Updated: 2023/01/03 07:48:56 by llaruell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Permet de récupérer l'abscisse de la couleur de la texture
 * 
 * @param game Structure contenant nos données générales
 * @param ray Structure contenant nos données concernant le raycasting
 * @param ray Structure contenant nos données concernant une texture
 */
static void	get_texture_x(t_game *game, t_raycast *ray, t_tex *tex)
{
	if (ray->side == 0)
	{
		ray->wall_x = game->camera.position.y
			+ ray->perp_wall_dist * ray->direction.y;
	}
	else
	{
		ray->wall_x = game->camera.position.x
			+ ray->perp_wall_dist * ray->direction.x;
	}
	set_double_value(&ray->wall_x, ray->wall_x - floor(ray->wall_x));
	tex->x = (int)(ray->wall_x * (tex->width));
	if (ray->side == 0 && ray->direction.x < 0.)
		tex->x = tex->width - tex->x - 1.;
	if (ray->side == 1 && ray->direction.y > 0.)
		tex->x = tex->width - tex->x - 1.;
}

int	clz(unsigned int i)
{
	int				z;
	unsigned int	n;

	z = 0;
	n = 1 << ((sizeof(unsigned int) << 3) - 1);
	while ((!(n & i)) && n > 0)
	{
		n >>= 1;
		z++;
	}
	return (z);
}

/**
 * @brief Permet de récupérer l'ordonnée de la couleur de la texture
 * 			et de l'ajouter à l'image
 * 
 * @param game Structure contenant nos données générales
 * @param ray Structure contenant nos données concernant le raycasting
 * @param ray Structure contenant nos données concernant une texture
 */
static void	get_texture_y(t_game *game, t_raycast *ray, t_tex *tex)
{
	int		i;
	int		mask;
	int		color;
	int		c;

	c = game->win.height / ray->perp_wall_dist;
	i = (game->win.height / 2) - (ray->height / 2);
	mask = 1 << ((sizeof(unsigned int) << 3) - clz(tex->height));
	if (i < 0)
		i = 0;
	while (++i < (game->win.height / 2) + (ray->height / 2)
		&& i < game->win.height)
	{
		tex->y = (((i - (-ray->height / 2 + game->win.height / 2)) * mask / c)
				& (mask - 1)) * ((double)tex->height / mask);
		color = get_color_tex(tex);
		pixel_draw(ray->column, i, color, game);
	}
}

void	draw_wall(t_game *game, t_raycast *ray)
{
	t_tex	*tex;

	tex = &game->wall[ray->wall_direction - 1];
	if (!tex)
		print_error(game, "MERDE TU ES\n");
	get_texture_x(game, ray, tex);
	get_texture_y(game, ray, tex);
}
