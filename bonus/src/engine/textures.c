/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaruell <llaruell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 14:49:25 by llaruell          #+#    #+#             */
/*   Updated: 2023/01/03 10:57:10 by llaruell         ###   ########.fr       */
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
void	load_textures(t_game *game, int id)
{
	load_texture(game, game->wall[0].path, &game->wall[0]);
	load_texture(game, game->wall[1].path, &game->wall[1]);
	load_texture(game, game->wall[2].path, &game->wall[2]);
	load_texture(game, game->wall[3].path, &game->wall[3]);
	load_texture(game, game->wall[4].path, &game->wall[4]);
	if (id == 0)
	{
		load_texture(game, "Textures/floor_sky/night_sky.xpm", &game->t_sky);
		load_texture(game, "Textures/floor_sky/black.xpm", &game->t_floor);
	}
	else if (id == 1)
	{
		load_texture(game, "Textures/floor_sky/cave_sky.xpm", &game->t_sky);
		load_texture(game, "Textures/floor_sky/cave_floor.xpm", &game->t_floor);
	}
}

void	load_sprites_tex(t_game *game, t_sprite *sprite)
{
	if (sprite->type == '4')
		load_texture(game, "Textures/sprite/barrel.xpm", &sprite->tex);
	else if (sprite->type == '5')
		load_texture(game, "Textures/sprite/key.xpm", &sprite->tex);
	else if (sprite->type == '6')
		load_texture(game, "Textures/sprite/paper.xpm", &sprite->tex);
	else if (sprite->type == '7')
		load_texture(game, "Textures/sprite/cage.xpm", &sprite->tex);
	else if (sprite->type == '8')
		load_texture(game, "Textures/sprite/chair.xpm", &sprite->tex);
	else if (sprite->type == '9')
		load_texture(game, "Textures/sprite/table.xpm", &sprite->tex);
	else if (sprite->type == 'C')
		load_texture(game, "Textures/sprite/col_i.xpm", &sprite->tex);
	else if (sprite->type == 'c')
		load_texture(game, "Textures/sprite/col_e.xpm", &sprite->tex);
	else if (sprite->type == 'B')
		load_texture(game, "Textures/sprite/col_b.xpm", &sprite->tex);
	else if (sprite->type == 'b')
		load_texture(game, "Textures/sprite/bed.xpm", &sprite->tex);
	else if (sprite->type == 'V')
		load_texture(game, "Textures/Enemy/Enemy_1.xpm", &sprite->tex);
	else if (sprite->type == 'K')
		load_texture(game, "Textures/sprite/Kastel.xpm", &sprite->tex);
}

void	load_enemy_tex(t_game *game, t_sprite *sprite, int id)
{
	if (id == 0)
		load_texture(game, "Textures/Enemy/Enemy_1.xpm", &sprite->tex);
	if (id == 1)
		load_texture(game, "Textures/Enemy/Enemy_2.xpm", &sprite->tex);
	if (id == 2)
		load_texture(game, "Textures/Enemy/Enemy_1.xpm", &sprite->tex);
	if (id == 3)
		load_texture(game, "Textures/Enemy/Enemy_3.xpm", &sprite->tex);
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
