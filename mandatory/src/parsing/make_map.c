/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaruell <llaruell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 07:49:54 by llaruell          #+#    #+#             */
/*   Updated: 2023/01/03 07:49:54 by llaruell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	count_words(char *str, char c)
{
	int	i;
	int	word;

	i = 0;
	word = 1;
	while (str[i])
	{
		if (str[i] == c && str[i + 1] == c)
			return (word);
		if (str[i] == c && str[i + 1])
		{
			word++;
			i++;
		}
		i++;
	}
	return (word);
}

static char	**error(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

static int	tab_add(char *tab, char *from, char c, int j)
{
	int	i;
	int	added;

	i = 0;
	added = 0;
	while (from[i] != c && from[i] != '\0')
	{
		tab[i] = from[i];
		i++;
		added++;
	}
	while (i < j)
	{
		tab[i] = ' ';
		i++;
	}
	tab[i] = '\0';
	return (added);
}

static int	fill(char **tab, char *str, char c)
{
	int	added;
	int	i;
	int	linelen;
	int	k;

	i = 0;
	k = 0;
	linelen = line_len(str);
	while (str[i])
	{
		if (str[i] == c)
			i++;
		else
		{
			tab[k] = (char *) malloc (sizeof(char) * (linelen + 1));
			if (!tab[k])
				return (1);
			added = tab_add(tab[k], str + i, c, linelen);
			k++;
			i = i + added;
		}
	}
	return (0);
}

char	**get_map(char *file)
{
	char	**map;
	int		count;

	count = 0;
	while (file[count])
		count++;
	count = count_words(file, '\n');
	map = (char **) malloc (sizeof(char *) * (count + 1));
	if (!map)
		return (NULL);
	if (fill(map, file, '\n') != 0)
	{
		error(map);
		return (NULL);
	}
	map[count] = 0;
	return (map);
}
