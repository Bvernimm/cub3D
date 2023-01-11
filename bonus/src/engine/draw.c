/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaruell <llaruell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 14:48:36 by llaruell          #+#    #+#             */
/*   Updated: 2022/12/30 14:48:36 by llaruell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Permet de dessiner un pixel sur l'image du jeu
 * 
 * @param x Position en x
 * @param y Position en y
 * @param color Code couleur 
 * @param game Structure contenant nos données générales
 */
void	pixel_draw(int x, int y, int color, t_game *game)
{
	int	pos;

	pos = game->win.sizeline * y + x * (game->win.bitesparpixel / 8);
	if (x >= 0 && y >= 0 && x <= game->win.width && y <= game->win.height)
		*(int *)(game->win.addr + pos) = color;
}

/**
 * @brief Permet de dessiner un fond
 * 
 * @param game Structure contenant nos données générales
 */
void	draw_font(t_game *game, int color)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->win.height)
	{
		j = -1;
		while (++j < game->win.width)
			pixel_draw(j, i, color, game);
	}
}

/**
 * @brief Dessine le ciel et le sol
 * 
 * @param game Variable stockant les differentes infos sur le jeu
 * @param ray Variable stockant les differentes infos sur le raycasting
 */
void	draw_floor_sky(t_game *game, t_raycast *ray)
{
	int		i;
	int		j;
	double	w;

	i = (game->win.height / 2) + (ray->height / 2.);
	j = ray->column;
	while (i < game->win.height)
	{
		pixel_draw(j, i, game->floor, game);
		w = game->win.height - i;
		i++;
		pixel_draw(j, w, game->sky, game);
	}
}

/**
 * @brief Permet d'afficher le jeu sur la fenêtre
 * 
 * @param game Structure contenant nos données générales
 */
void	draw(t_game *game)
{
	mlx_clear_window(game->mlx, game->win.mlx_ptr);
	mlx_put_image_to_window(game->mlx, game->win.mlx_ptr, game->win.img, 0, 0);
}
