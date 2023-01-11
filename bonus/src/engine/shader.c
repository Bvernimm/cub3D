/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaruell <llaruell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 14:47:41 by llaruell          #+#    #+#             */
/*   Updated: 2022/12/30 14:47:43 by llaruell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	shader(double divide, int color, int shade)
{
	if (shade == 0)
		return (color);
	if (divide <= 1.)
		return (color);
	return (((int)(((0xFF0000 & color) >> 16) / divide) << 16)
		+ ((int)(((0x00FF00 & color) >> 8) / divide) << 8)
		+ ((int)((0x0000FF & color) / divide)));
}
