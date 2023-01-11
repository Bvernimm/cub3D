/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   document_tuto.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaruell <llaruell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 14:29:24 by llaruell          #+#    #+#             */
/*   Updated: 2023/01/03 10:29:57 by llaruell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	tuto1(t_game *game)
{
	mlx_string_put(game->mlx, game->win.mlx_ptr, DOC_X, DOC_Y,
		C_DOC, "Pour passer, je vais avoir besoin d'une clef ...");
}

void	tuto2(t_game *game)
{
	mlx_string_put(game->mlx, game->win.mlx_ptr, DOC_X, DOC_Y,
		C_DOC, "  Mia m'a demande de venir ici... Ce lieu est ... etrange");
	mlx_string_put(game->mlx, game->win.mlx_ptr, DOC_X, DOC_Y + DOC_INT,
		C_DOC, "J'entends des bruits... Brrr... C'est inquietant...");
	mlx_string_put(game->mlx, game->win.mlx_ptr, DOC_X, DOC_Y + DOC_INT * 2,
		C_DOC, " Heureusemment qu'elle est canon... J'ai si hate de la voir !");
}
