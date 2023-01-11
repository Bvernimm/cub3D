/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   da_door.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaruell <llaruell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 14:48:30 by llaruell          #+#    #+#             */
/*   Updated: 2023/01/03 11:31:56 by llaruell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	can_open(t_game *game, int y, int x)
{
	if (game->control.nb_key > 0)
	{
		if (game->control.level == 1)
		{
			if ((x == 34 && y == 36) || (x == 23 && y == 32)
				|| (x == 14 && y == 28) || (x == 16 && y == 26)
				|| (x == 30 && y == 13) || (x == 57 && y == 26)
				|| (x == 66 && y == 3) || (x == 78 && y == 16)
				|| (x == 94 && y == 36))
			{
				game->control.nb_key--;
				return (1);
			}
		}
		else if (game->control.level == 0)
		{
			if (x == 11 && y == 3)
			{
				game->control.nb_key--;
				return (1);
			}
		}
	}
	return (0);
}

static int	detect_da_closed_door(t_game *game, int x, int y)
{
	int		modx;
	int		mody;
	float	dirx;
	float	diry;

	modx = 0;
	mody = 0;
	dirx = game->camera.direction.x;
	diry = game->camera.direction.y;
	if (dirx >= 0.5 && diry > -0.5 && diry <= 0.5)
		modx = 1;
	else if (dirx <= -0.5 && diry >= -0.5 && diry < 0.5)
		modx = -1;
	else if (diry >= 0.5 && dirx >= -0.5 && dirx < 0.5)
		mody = 1;
	else if (diry <= -0.5 && dirx > -0.5 && dirx <= 0.5)
		mody = -1;
	if (can_open(game, y + mody, x + modx) == 1)
	{
		game->map[y + mody][x + modx] = '3';
		return (1);
	}
	return (0);
}

static int	detect_da_open_door(t_game *game, int x, int y)
{
	int		modx;
	int		mody;
	float	dirx;
	float	diry;

	modx = 0;
	mody = 0;
	dirx = game->camera.direction.x;
	diry = game->camera.direction.y;
	if (dirx >= 0.5 && diry > -0.5 && diry <= 0.5)
		modx = 1;
	else if (dirx <= -0.5 && diry >= -0.5 && diry < 0.5)
		modx = -1;
	else if (diry >= 0.5 && dirx >= -0.5 && dirx < 0.5)
		mody = 1;
	else if (diry <= -0.5 && dirx > -0.5 && dirx <= 0.5)
		mody = -1;
	if (game->map[y + mody][x + modx] == '3')
	{
		game->map[y + mody][x + modx] = '2';
		game->control.nb_key++;
		return (1);
	}
	return (0);
}

void	open_da_door(t_game *game)
{
	int	x;
	int	y;
	int	columns;
	int	rows;

	x = (int)floor(game->camera.position.x);
	y = (int)floor(game->camera.position.y);
	rows = get_array(game->map);
	columns = ft_strlen(game->map[0]);
	if (detect_da_closed_door(game, x, y) == 1)
		play("afplay -v 0.2 -q 1 Sound/door_open.mp3");
	else if (detect_da_open_door(game, x, y) == 1)
		play("afplay -v 0.7 -q 1 Sound/door_close.mp3");
}
