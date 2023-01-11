/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_mouse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaruell <llaruell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 14:50:54 by llaruell          #+#    #+#             */
/*   Updated: 2022/12/30 14:50:56 by llaruell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	mouse_hide(void)
{
	mac_mouse_hide();
	return (0);
}

int	mouse_move(int x, int y)
{
	mac_mouse_move(x, y);
	return (0);
}
