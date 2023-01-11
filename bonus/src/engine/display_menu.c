/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_menu.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaruell <llaruell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 14:48:26 by llaruell          #+#    #+#             */
/*   Updated: 2022/12/30 14:48:26 by llaruell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	display_menu(t_game *game, int x, int y)
{
	mlx_string_put(game->mlx, game->win.mlx_ptr, x + 232, y - 50,
		C_RED, "  DUCK THE ISSUE ");
	mlx_string_put(game->mlx, game->win.mlx_ptr, x + 232, y,
		C_DARKCYAN, "    COMMANDES ");
	mlx_string_put(game->mlx, game->win.mlx_ptr, x + 232, y + 20,
		C_DARKCYAN, "-----------------");
	mlx_string_put(game->mlx, game->win.mlx_ptr, x, y + 50, C_DARKCYAN,
		"* -------------------------------------------------------------- *");
	mlx_string_put(game->mlx, game->win.mlx_ptr, x, y + 80, C_DARKCYAN,
		"| Se deplacer                  |  WASD / Touches directionnelles |");
	mlx_string_put(game->mlx, game->win.mlx_ptr, x, y + 110, C_DARKCYAN,
		"| Faire tourner la camera      |         Touches directionnelles |");
	mlx_string_put(game->mlx, game->win.mlx_ptr, x, y + 140, C_DARKCYAN,
		"| Quitter le jeu               |                             ESC |");
	mlx_string_put(game->mlx, game->win.mlx_ptr, x, y + 170, C_DARKCYAN,
		"| Ouvrir / Quitter Menu        |                               P |");
	mlx_string_put(game->mlx, game->win.mlx_ptr, x, y + 200, C_DARKCYAN,
		"| Action                       |                           SPACE |");
	mlx_string_put(game->mlx, game->win.mlx_ptr, x, y + 230, C_DARKCYAN,
		"| Sprint                       |                    SHIFT GAUCHE |");
	mlx_string_put(game->mlx, game->win.mlx_ptr, x, y + 260, C_DARKCYAN,
		"| Activer / Desactiver Souris  |                               M |");
	mlx_string_put(game->mlx, game->win.mlx_ptr, x, y + 290, C_DARKCYAN,
		"* -------------------------------------------------------------- *");
}

void	menu(t_game *game)
{
	int	x;
	int	y;

	x = game->win.width / 2 - 302;
	y = game->win.height / 2 - 128;
	mlx_clear_window(game->mlx, game->win.mlx_ptr);
	display_menu(game, x, y);
}
