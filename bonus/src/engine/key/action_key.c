/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaruell <llaruell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 14:33:42 by llaruell          #+#    #+#             */
/*   Updated: 2023/01/03 10:31:57 by llaruell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_area(t_game *game, int x, int y, char c)
{
	int	i;
	int	j;

	i = y - 1;
	while (i < y + 2)
	{
		j = x - 1;
		while (j < x + 2)
		{
			if (game->map[i][j] == c)
			{
				check_doc(game, j, i);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (-1);
}

void	check_event(t_game *game)
{
	int		x;
	int		y;
	t_coord	coord;
	char	ret;

	x = (int)floor(game->camera.position.x);
	y = (int)floor(game->camera.position.y);
	coord.x = (int)floor(game->camera.position.x);
	coord.y = (int)floor(game->camera.position.y);
	ret = check_area(game, x, y, '6');
	if (ret != 1)
		open_da_door(game);
}
