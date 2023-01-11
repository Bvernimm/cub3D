/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaruell <llaruell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 14:54:06 by llaruell          #+#    #+#             */
/*   Updated: 2022/12/30 14:54:06 by llaruell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
