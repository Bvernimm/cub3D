/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice_manip.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaruell <llaruell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 14:56:08 by llaruell          #+#    #+#             */
/*   Updated: 2022/12/30 14:56:08 by llaruell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Permet de récupérer le nombre de lignes
 * 			de la matrice
 * 
 * @param array Matrice de caractère
 * @return Nombre de lignes présents dans la matrice
 */
int	get_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}
