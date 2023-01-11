/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvernimm <bvernimm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 14:40:33 by bvernimm          #+#    #+#             */
/*   Updated: 2023/01/04 14:44:52 by bvernimm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_file(int fd, t_game *game)
{
	char	*file;
	int		i;

	file = read_file(fd);
	i = get_texture(file, game, 1, 0);
	check_map(file, game, i);
	free (file);
}

int	check_file_name(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (str[len - 4] != '.' || str[len - 3] != 'c'
		|| str[len - 2] != 'u' || str[len - 1] != 'b')
		return (1);
	return (0);
}
