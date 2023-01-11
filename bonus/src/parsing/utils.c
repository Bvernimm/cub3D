/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaruell <llaruell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 14:54:35 by llaruell          #+#    #+#             */
/*   Updated: 2022/12/30 14:54:35 by llaruell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*read_file(int fd)
{
	char	*letter;
	char	*file;
	int		nbr_read;

	letter = malloc (sizeof(char) * 2);
	file = NULL;
	nbr_read = 1;
	while (nbr_read != 0)
	{
		nbr_read = read(fd, letter, 1);
		if (nbr_read < 0)
			ft_error("read failed\n", NULL);
		if (nbr_read == 0)
			break ;
		letter[1] = '\0';
		file = ft_strjoin(file, letter, 1);
		if (!file)
		{
			free (letter);
			ft_error("strjoin return NULL\n", NULL);
		}
	}
	free (letter);
	return (file);
}

char	*ft_strjoin(char *file, char *tmp, int indic)
{
	char	*str;
	int		i;
	int		j;

	if (!file)
	{
		file = malloc(sizeof(char) * 1);
		file[0] = '\0';
	}
	if (!file || !tmp)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(file) + ft_strlen(tmp)) + 1));
	if (!str)
		return (NULL);
	i = -1;
	j = 0;
	while (file[++i])
		str[i] = file[i];
	while (tmp[j])
		str[i++] = tmp[j++];
	str[i] = '\0';
	if (indic == 1)
		free(file);
	return (str);
}

int	ft_atoi_from(char *str, int i)
{
	int		nb;
	int		neg;

	nb = 0;
	neg = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			neg = -neg;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = (nb * 10) + (str[i] - '0');
		i++;
	}
	return (nb * neg);
}

int	line_len(char *file)
{
	int		longest;
	int		len;
	int		i;

	i = 0;
	len = 0;
	longest = 0;
	while (file[i])
	{
		while (file[i] && file[i] != '\n')
		{
			i++;
			len++;
		}
		if (len > longest)
			longest = len;
		len = 0;
		i++;
	}
	return (longest);
}
