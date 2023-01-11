/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constantes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaruell <llaruell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 07:51:03 by llaruell          #+#    #+#             */
/*   Updated: 2023/01/03 07:51:03 by llaruell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTANTES_H

# define CONSTANTES_H

// Fenetre 640-440 1280 1080

# define SCREEN_WIDTH 1280
# define SCREEN_HEIGHT 1080
# define CELL_SIZE 32

// GESTION DES TOUCHES

# define KEY_ESC 53

# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_DOWN 125
# define KEY_UP 126

# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_W 13

# define KEY_SHIFT 257

# define KEY_SPACE 49
# define KEY_ENTER 36

// GESTION DES MLX HOOK

# define MLX_KEY_PRESS 2
# define MLX_KEY_RELEASE 3
# define MLX_DESTROY_NOTIF 17

// FOV

# define FOV 0.66

// ORIENTATION

# define NORTH 1
# define SOUTH 2
# define EAST 3
# define WEST 4

// SPEED MOVE-ROT

# define Q_MOVE 2.5
# define Q_ROTA 2.
# define Q_MOVE_SPRINT 5.
# define Q_ROTA_SPRINT 3.
#endif