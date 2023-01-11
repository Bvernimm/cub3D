/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   speed.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaruell <llaruell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 07:48:48 by llaruell          #+#    #+#             */
/*   Updated: 2023/01/03 07:48:49 by llaruell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Permet de retourner la valeur de l'heure actuelle en milliseconde
 * 
 * @return La valeur de l'heure actuelle en milliseconde
 */
static int	get_time(void)
{
	struct timeval	time;
	int				i;

	gettimeofday(&time, NULL);
	i = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (i);
}

/**
 * @brief Permet de mettre à jour les différentes vitesses
 * 
 * @param game Structure contenant nos données
 */
void	update_speed(t_game *game)
{
	int		oldtime;
	double	calcul_frame;

	oldtime = game->frametime;
	game->frametime = get_time();
	calcul_frame = (game->frametime - oldtime) / 1000.0;
	set_double_value(&game->speed.move, calcul_frame * game->speed.q_move);
	set_double_value(&game->speed.rotation, calcul_frame * game->speed.q_rota);
	if (game->speed.move > 0.3000)
		set_double_value(&game->speed.move, 0.3000);
	if (game->speed.rotation > 0.300)
		set_double_value(&game->speed.rotation, 0.300);
}
