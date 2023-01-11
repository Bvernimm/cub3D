/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvernimm <bvernimm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 14:31:22 by llaruell          #+#    #+#             */
/*   Updated: 2023/01/05 11:43:31 by bvernimm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Permet de jouer un son
 * 
 * @param path Chemin d'accés au son
 * @param game Variable stockant les differentes infos sur le jeu
 */
void	play(char *path)
{
	char	**cmd_arg;
	pid_t	child1;

	child1 = fork();
	if (child1 < 0)
		return (perror("Fork error"));
	cmd_arg = ft_split(path, ' ');
	if (!child1)
	{
		execve(AFPLAYCMD, cmd_arg, NULL);
		exit(0);
	}
	free_matrice(cmd_arg);
}

/**
 * @brief Permet de stopper un son
 * 
 */
void	stop(void)
{
	system(KILL);
}

/**
 * @brief Permet de mettre en pause un son
 * 
 */
void	pause_song(t_game *game)
{
	system(PAUSE);
	pthread_mutex_lock(&(game->player.play));
	game->player.is_play = 2;
	pthread_mutex_unlock(&(game->player.play));
	pthread_cond_signal(&(game->player.cond_signal));
}

/**
 * @brief Permet de reprendre un son
 * 
 */
void	resume_song(t_game *game)
{
	system(RESUME);
	pthread_mutex_lock(&(game->player.play));
	game->player.is_play = 1;
	pthread_mutex_unlock(&(game->player.play));
	pthread_cond_signal(&(game->player.cond_signal));
}
