/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice_manip.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaruell <llaruell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 07:50:18 by llaruell          #+#    #+#             */
/*   Updated: 2023/01/03 07:50:18 by llaruell         ###   ########.fr       */
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
