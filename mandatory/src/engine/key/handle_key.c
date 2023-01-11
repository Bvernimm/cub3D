/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaruell <llaruell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 07:49:13 by llaruell          #+#    #+#             */
/*   Updated: 2023/01/03 07:49:13 by llaruell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Check si la touche est une touche de direction
 * 
 * @param key La touche
 * @return 1 si il s'agit d'unt touche de direction, 0 sinon
 */
int	is_moving_key(int key)
{
	if (key == KEY_W || key == KEY_S || key == KEY_A || key == KEY_D
		|| key == KEY_UP || key == KEY_DOWN || key == KEY_LEFT
		|| key == KEY_RIGHT || key == KEY_SHIFT)
		return (1);
	return (0);
}

/**
 * @brief Check si la touche est une touche spéciale
 * 
 * @param key La touche
 * @return 1 si il s'agit d'unt touche spéciale, 0 sinon
 */
int	is_special_key(int key)
{
	if (key == KEY_ESC || key == KEY_SPACE)
		return (1);
	return (0);
}
