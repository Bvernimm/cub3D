/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaruell <llaruell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 07:48:52 by llaruell          #+#    #+#             */
/*   Updated: 2023/01/03 07:48:52 by llaruell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Permet d'appliquer une image sur une texture
 * 
 * @param game Variable stockant les differentes infos sur le jeu
 * @param path Chemin d'acces de l'image de la texture, 
                    situe dans le dossier Textures
 * @param t texture qui va recevoir l'image qui lui ai associe
 */
static void	load_texture(t_game *game, char *path, t_tex *t)
{
	t->img = mlx_xpm_file_to_image(game->mlx, path, &t->width, &t->height);
	if (!t->img)
		print_error(game, "Impossible charger la texture");
	t->ptr = mlx_get_data_addr(t->img, &t->bpp, &t->size_line, &t->endian);
}

/**
 * @brief  Permet d'instancier toutes les textures pour les objets du jeu
 * 
 * @param game Variable stockant les differentes infos sur le jeu
 */
void	load_textures(t_game *game)
{
	load_texture(game, game->wall[0].path, &game->wall[0]);
	load_texture(game, game->wall[1].path, &game->wall[1]);
	load_texture(game, game->wall[2].path, &game->wall[2]);
	load_texture(game, game->wall[3].path, &game->wall[3]);
}

/**
 * @brief Retourne la couleur d'un pixel à un endroit précis de la texture
 * 
 * @param tex Texture
 * @return Couleur du pixel
 */
int	get_color_tex(t_tex *tex)
{
	char	*pixel;

	pixel = tex->ptr + (tex->size_line * tex->y) + (tex->bpp / 8 * tex->x);
	return (*(unsigned int *)pixel);
}
