/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_struct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaruell <llaruell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 14:56:57 by llaruell          #+#    #+#             */
/*   Updated: 2022/12/30 14:56:57 by llaruell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Modifie les valeurs du vecteur
 * 
 * @param vector Vecteur
 * @param x Abscisse
 * @param y Ordonnée
 */
void	set_vector(t_vector *vector, double x, double y)
{
	vector->x = x;
	vector->y = y;
}

/**
 * @brief Modifie les valeurs des coordonnées
 * 
 * @param coord Coordonnées
 * @param x Abscisse
 * @param y Ordonnée
 */
void	set_coord(t_coord *coord, int x, int y)
{
	coord->x = x;
	coord->y = y;
}

/**
 * @brief Copie les données du vecteur new dans le vecteur old
 * 
 * @param old Ancien vecteur
 * @param new Nouveau vecteur
 */
void	copy_vector(t_vector *old, t_vector new)
{
	old->x = new.x;
	old->y = new.y;
}

/**
 * @brief Copie les valeurs des coordonnées new dans old
 * 
 * @param old Ancienne coordonnées
 * @param new Nouvelles coordonnées
 */
void	copy_coord(t_coord *old, t_coord new)
{
	old->x = new.x;
	old->y = new.y;
}
