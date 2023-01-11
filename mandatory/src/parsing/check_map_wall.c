/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_wall.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaruell <llaruell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 07:49:38 by llaruell          #+#    #+#             */
/*   Updated: 2023/01/03 07:49:38 by llaruell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_walls_1(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[0][i + 1])
		i++;
	while (map[j])
	{
		if ((map[j][0] != ' ' && map[j][0] != '1')
			|| (map[j][i] != ' ' && map[j][i] != '1'))
			return (1);
		j++;
	}
	j--;
	i = 0;
	while (map[j][i])
	{
		if ((map[j][i] != ' ' && map[j][i] != '1')
			|| (map[0][i] != ' ' && map[0][i] != '1'))
			return (1);
		i++;
	}
	return (0);
}

int	check_walls_2(char **map)
{
	int	i;
	int	j;

	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == ' ' && check_around(map, i, j) != 0)
				return (1);
			i++;
		}
		j++;
	}
	return (0);
}

int	check_around(char **map, int i, int j)
{
	int	height;
	int	width;

	height = 0;
	width = 0;
	while (map[height + 1])
		height++;
	while (map[height][width + 1])
		width++;
	if (j - 1 >= 0 && map[j - 1][i]
		&& map[j - 1][i] != ' ' && map[j - 1][i] != '1')
		return (1);
	if (j + 1 <= height && map[j + 1][i]
		&& map[j + 1][i] != ' ' && map[j + 1][i] != '1')
		return (1);
	if (i - 1 >= 0 && map[j][i - 1]
		&& map[j][i - 1] != ' ' && map[j][i - 1] != '1')
		return (1);
	if (i + 1 <= width && map[j][i + 1]
		&& map[j][i + 1] != ' ' && map[j][i + 1] != '1')
		return (1);
	return (0);
}
