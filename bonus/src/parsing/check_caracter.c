/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_caracter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaruell <llaruell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 14:53:53 by llaruell          #+#    #+#             */
/*   Updated: 2023/01/02 12:51:52 by llaruell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_caracter(char c)
{
	if (c != ' ' && c != '\n' && c != '0' && c != '1'
		&& c != 'N' && c != 'E' && c != 'W' && c != 'S'
		&& c != '2' && c != '3' && c != '4' && c != '5'
		&& c != '6' && c != '7' && c != '8' && c != '9'
		&& c != 'C' && c != 'c' && c != 'B' && c != 'b'
		&& c != 'e' && c != 'V' && c != 'K')
		return (1);
	return (0);
}
