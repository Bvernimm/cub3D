/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_natif.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaruell <llaruell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 07:50:36 by llaruell          #+#    #+#             */
/*   Updated: 2023/01/03 07:50:36 by llaruell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Modifie la valeur d'un réel
 * 
 * @param old Ancienne valeur
 * @param new Nouvelle valeur
 */
void	set_double_value(double	*old, double new)
{
	*old = new;
}

/**
 * @brief Modifie la valeur d'un entier
 * 
 * @param old Ancienne valeur
 * @param new Nouvelle valeur
 */
void	set_int_value(int *old, int new)
{
	*old = new;
}
