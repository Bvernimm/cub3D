/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaruell <llaruell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 14:33:00 by llaruell          #+#    #+#             */
/*   Updated: 2022/12/30 14:33:00 by llaruell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	min_dist_sp(t_sprite a, t_sprite b, int nb_el, t_sprite *res)
{
	int	i;

	i = -1;
	while (++i < nb_el)
	{
		if (b.distance == res[i].distance)
			return (0);
	}
	return (a.distance < b.distance);
}

int	check_already_in(t_sprite a, t_sprite *b, int count)
{
	int	i;

	i = -1;
	while (++i < count)
	{
		if (b[i].number == a.number)
			return (1);
	}
	return (0);
}

int	get_min(t_game *game, t_sprite *b, int count, float minimum)
{
	int		i;
	int		res;
	float	min;

	i = -1;
	min = 2147483647.;
	res = 0;
	while (++i < game->nb_sprites)
	{
		if (game->sprites[i].distance < min
			&& game->sprites[i].distance >= minimum)
		{
			if (check_already_in(game->sprites[i], b, count) == 0)
			{
				min = game->sprites[i].distance;
				res = i;
			}
		}
	}
	return (res);
}

void	sprites_distances(t_vector pos, t_sprite *sp, int count)
{
	int	i;

	i = -1;
	while (++i < count)
		sp[i].distance = pow(pos.x - sp[i].coord.x, 2)
			+ pow(pos.y - sp[i].coord.y, 2);
}

int	check_limite(int value, t_coord start, t_coord end, int id)
{
	if (id)
		return (value > start.x && value < end.x);
	else
		return (value > start.y && value < end.y);
}
