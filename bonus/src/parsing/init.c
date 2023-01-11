/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaruell <llaruell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 14:54:11 by llaruell          #+#    #+#             */
/*   Updated: 2023/01/02 15:00:03 by llaruell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Permet les variables directionnelles à zéro 
 * 
 * @param move Structure contenant nos variable directionnelles
 */
void	init_move_and_speed(t_move *move, t_speed *speed)
{
	move->forward = 0;
	move->backward = 0;
	move->left = 0;
	move->right = 0;
	move->walk_left = 0;
	move->walk_right = 0;
	speed->q_move = 2.5;
	speed->q_rota = 2.;
}

/**
 * @brief Initialise la fenêtre de jeu
 * 
 * @param win Structure représentant la fenêtre de jeu
 * @param mlx Pointeur MLX
 * @return 1 en cas d'erreur, sinon 0 
 */
int	init_windows(t_windows *win, void *mlx)
{
	win->img = mlx_new_image(mlx, win->width, win->height);
	win->addr = mlx_get_data_addr(win->img, &win->bitesparpixel,
			&win->sizeline, &win->endian);
	win->mlx_ptr = mlx_new_window(mlx, win->width, win->height,
			"CUB3D");
	if (!win->img || !win->addr || !win->mlx_ptr)
		return (1);
	return (0);
}

/**
 * @brief Initialise les valeurs de la caméra
 * 
 * @param cam Structure représentant la caméra
 * @param player Position du joueur
 * @param orientation Orientation du joueur
 */
void	init_camera(t_camera *cam, t_vector player, int orientation)
{
	if (orientation == 'N')
	{
		set_vector(&cam->direction, 0., -1.);
		set_vector(&cam->plane, FOV, 0);
	}
	else if (orientation == 'S')
	{
		set_vector(&cam->direction, 0., 1.);
		set_vector(&cam->plane, -FOV, 0);
	}
	else if (orientation == 'E')
	{
		set_vector(&cam->direction, 1., 0.);
		set_vector(&cam->plane, 0., FOV);
	}
	else if (orientation == 'W')
	{
		set_vector(&cam->direction, -1., 0.);
		set_vector(&cam->plane, 0., -FOV);
	}
	copy_vector(&cam->position, player);
}

/**
 * @brief Initialise les différentes valeurs des controleurs
 * 
 * @param control Variable stockant les differentes infos
 * 		sur les controleurs
 */
void	init_control_value(t_control *control)
{
	control->endgame = 0;
	control->menu = 1;
	control->mouse = 0;
	control->use_mouse = 0;
	control->sprint = 0;
	control->start = 1;
	control->is_thread = 0;
	control->nb_key = 0;
	control->level = 0;
	control->shade = 0;
	control->is_reading = 0;
	control->cutscene = 0;
}
