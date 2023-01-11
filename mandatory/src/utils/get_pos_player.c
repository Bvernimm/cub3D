/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pos_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaruell <llaruell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 07:50:28 by llaruell          #+#    #+#             */
/*   Updated: 2023/01/03 07:50:28 by llaruell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Vérifie si le caractère correspond à l'un 
 * 			réservé au joueur
 * 
 * @param player Caractère à tester
 * @return 1 s'il s'agit d'un caractère réservé au joueur
 * 			sinon 0
 */
static int	check_player(char player)
{
	if (player == 'N' || player == 'S'
		|| player == 'W' || player == 'E')
		return (1);
	return (0);
}

/**
 * @brief Set the pos player object
 * 
 * @param game Structure contenant nos données générales
 * @param y Abscisse du joueur
 * @param x Ordonné du joueur
 * @param player Caractère représentant l'orientation du joueur
 */
static void	set_pos_player(t_game *game, int y, int x, char player)
{
	set_vector(&game->camera.position, x + 0.5, y + 0.5);
	if (player == 'N')
		game->start_orientation = 'N';
	else if (player == 'S')
		game->start_orientation = 'S';
	else if (player == 'W')
		game->start_orientation = 'W';
	else if (player == 'E')
		game->start_orientation = 'E';
}

/**
 * @brief Permet de récupérer la position de départ du joueur
 * 
 * @param game Structure contenant nos données générales
 * @param map Matrice représentant la carte du jeu
 */
void	get_pos_player(t_game *game, char **map)
{
	int	i;
	int	j;
	int	presence;

	i = -1;
	presence = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (check_player(map[i][j]))
			{
				++presence;
				set_pos_player(game, i, j, map[i][j]);
			}
		}
	}
	if (presence > 1)
		print_error(game, "Trop de joueurs\n");
}
