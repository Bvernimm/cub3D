/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvernimm <bvernimm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 10:23:16 by bvernimm          #+#    #+#             */
/*   Updated: 2023/01/05 10:43:03 by bvernimm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	count_words(char const *s, char c)
{
	int	wc;

	wc = 0;
	if (*s && *s != c)
		wc++;
	if (*s)
		s++;
	while (*s)
	{
		if (*(s - 1) == c && *s != c)
			wc++;
		s++;
	}
	return (wc);
}

static char	const	*get_word_ptr(char const *s, char c, int n)
{
	int	wc;

	wc = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (wc == n)
			return (s);
		while (*s != c)
			s++;
		wc++;
	}
	return (NULL);
}

static char	*get_word(char const *s, char c, int n)
{
	int			len;
	const char	*ptr;
	char		*dst;
	int			i;

	len = 0;
	ptr = get_word_ptr(s, c, n);
	while (ptr[len] && ptr[len] != c)
		len++;
	dst = malloc(len + 1);
	if (!dst)
		return (NULL);
	i = -1;
	while (++i < len)
		dst[i] = ptr[i];
	dst[i] = '\0';
	return (dst);
}

static void	free_split(char **arr)
{
	int	i;

	i = -1;
	while (arr[++i])
		free(arr[i]);
	free(arr);
}

char	**ft_split(char const *s, char c)
{
	char	**dst;
	int		wc;
	int		i;

	if (!s)
		return (NULL);
	wc = count_words(s, c) + 1;
	dst = malloc(wc * sizeof(char *));
	if (!dst)
		return (NULL);
	i = -1;
	while (++i < wc - 1)
	{
		dst[i] = get_word(s, c, i);
		if (!dst[i])
		{
			free_split(dst);
			return (NULL);
		}
	}
	dst[i] = NULL;
	return (dst);
}
