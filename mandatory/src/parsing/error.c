/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvernimm <bvernimm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 07:49:46 by llaruell          #+#    #+#             */
/*   Updated: 2023/01/04 14:47:16 by bvernimm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_simple_error(char *str, char *file)
{
	write (2, "Error\n", 6);
	write(2, str, ft_strlen(str));
	if (file)
		free(file);
	exit(1);
}

void	ft_error(char *str, t_game *game)
{
	write (2, "Error\n", 6);
	write(2, str, ft_strlen(str));
	if (game->map)
		free_matrice(game->map);
	exit(1);
}

void	ft_free(t_game *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (game->wall[i].path)
			free(game->wall[i].path);
		i++;
	}
	i = 0;
	if (game->map)
	{
		while (game->map[i])
		{
			free(game->map[i]);
			i++;
		}
		free(game->map);
	}
}
