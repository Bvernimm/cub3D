/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_manip.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaruell <llaruell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 14:56:12 by llaruell          #+#    #+#             */
/*   Updated: 2022/12/30 14:56:12 by llaruell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Permet de retourner la longueur d'une chaîne de caractères
 * 
 * @param str Chaîne de caractères
 * @return Longueur de la chaîne de caractères
 */
int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

/**
 * @brief Permet de dupliquer une chaîne de caractères
 * 
 * @param s1 Chaîne de caractères à dupliquer
 * @return Clone de la chaîne de caractères
 */
char	*ft_strdup(const char *s1)
{
	char	*res;
	int		i;

	i = 0;
	while (s1[i])
		++i;
	res = (char *) malloc(sizeof (char) * (i + 1));
	if (!res)
		return (NULL);
	*res = 0;
	i = 0;
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

/**
 * @brief Permet de comparer deux chaînes de caractères selon une taille donnée
 * 
 * @param s1 Premier chaîne de caractères à comparer
 * @param s2 Second chaîne de caractères à comparer
 * @param n Nombre de caractères à comparer
 * @return La différence entre le caractère de la première chaîne et la seconde
 */
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] == s2[i] && s1[i] != '\0' && i < n - 1)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

/**
 * @brief Permet de chercher la première occurence d'un caractère dans une
			chaîne de caractères
 * 
 * @param s Chaîne de caractère
 * @param c Code ASCII du caractère à trouver
 * @return NULL si le caractère n'a pas été trouvé, sinon un pointeur vers 
			la première occurence du caractère
*/
char	*ft_strchr(const char *s, int c)
{	
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char) c)
		{
			return ((char *)s);
		}
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}

/**
 * @brief Permet de chercher la dernière occurence d'un caractère dans une
			chaîne de caractères
 * 
 * @param s Chaîne de caractère
 * @param c Code ASCII du caractère à trouver
 * @return NULL si le caractère n'a pas été trouvé, sinon un pointeur vers 
			la dernière occurence du caractère
*/
char	*ft_strrchr(const char *s, int c)
{
	char	*res;

	res = 0;
	while (*s != '\0')
	{
		if (*s == (char) c)
			res = (char *)s;
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (res);
}
