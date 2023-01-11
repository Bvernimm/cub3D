/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaruell <llaruell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 14:53:33 by llaruell          #+#    #+#             */
/*   Updated: 2023/01/02 12:40:32 by llaruell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Libère la mémoire allouée à une matrice 
 * 
 * @param matrice Matrice de caractères
 */
void	free_matrice(char **matrice)
{
	int	i;

	if (matrice)
	{
		i = -1;
		while (matrice[++i])
			free(matrice[i]);
		free(matrice);
	}
}

/**
 * @brief Libère la mémoire allouée aux données de la structure Game
 * 
 * @param game Structure contenant nos données générales
 */
void	free_game(t_game *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (game->wall[i].path)
			free(game->wall[i].path);
		i++;
	}
	if (game->map)
		free_matrice(game->map);
	if (game->win.img)
		mlx_destroy_image(game->mlx, game->win.img);
	if (game->win.mlx_ptr)
		mlx_destroy_window(game->mlx, game->win.mlx_ptr);
	if (game->sprites)
		free(game->sprites);
	if (game->control.is_thread)
		destroy_thread(game);
	else if (game->player.is_play)
		destroy_init_mutex(game);
}

/**
 * @brief Affiche l'erreur survenue et quitte le programme
 * 
 * @param err Message d'erreur
 */
void	print_simple_error(char *err)
{
	printf("%s", err);
	exit(EXIT_FAILURE);
}

/**
 * @brief Affiche l'erreur survenue, libère la mémoire et quitte le programme
 * 
 * @param game Structure contenant nos données générales
 * @param err Message d'erreur
 */
void	print_error(t_game *game, char *err)
{
	free_game(game);
	printf("%s", err);
	exit(EXIT_FAILURE);
}

/**
 * @brief Quitte le programme normalement
 * 
 * @param game Structure contenant nos données générales
 */
int	exit_game(t_game *game)
{
	free_game(game);
	system(KILL);
	exit(EXIT_SUCCESS);
	return (0);
}
