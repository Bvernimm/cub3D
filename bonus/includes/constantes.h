/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constantes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvernimm <bvernimm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 15:04:48 by llaruell          #+#    #+#             */
/*   Updated: 2023/01/05 10:13:20 by bvernimm         ###   ########.fr       */
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

# define KEY_M 46
# define KEY_P 35

// GESTION DES MLX HOOK

# define MLX_KEY_PRESS 2
# define MLX_KEY_RELEASE 3
# define MLX_DESTROY_NOTIF 17

// FOV

// # define FOV  0.612562

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
# define Q_ROTA_MOUSE 8.

# define ENEMY_DETECTION 5
# define SPEED_ANIM 12

// COLOR

# define C_RED 0x850606
# define C_DARKCYAN 0x068585
# define C_GREY 0x545E5E
# define C_STAR 0xFFDF00
// PLAYER

# define AFPLAY "afplay -v 0.1 -q 1 "
# define AFPLAYCMD "/usr/bin/afplay"

# define KILL "pgrep afplay | awk '{print $1}' | xargs kill"
# define PAUSE "pgrep afplay | awk '{print $1}' | xargs kill -STOP"
# define RESUME "pgrep afplay | awk '{print $1}' | xargs kill -CONT"

# define TIME_WAIT 1
# define SOUND_0 "Sound/tuto.mp3"
# define DURATION_0 51
# define SOUND_1 "Sound/run.mp3"
# define DURATION_1 23

// -- FLAG AFPLAY --
// -v => Gère le volume, est compris entre 0.0 et 1.0.
//			Le son est géré de manière logarithmiques
// -q => Qualité du son.
//			Par défaut (0) faible qualité, 1 Meilleure qualité

// -- FLAG KILL --
// -TSTP => Permet d'envoyer un signal stop à un processus
//			(N'arrête pas le processus)
// -CONT => Permet de continuer un processus stoppé par -TSTP

// DOCUMENT

# define C_DOC 0x303030
# define C_DOC2 0x850606

# define B_FONT_X 256
# define B_FONT_Y 216
# define W_FONT_X 276
# define W_FONT_Y 236
# define B_FONT 0x987A33
# define W_FONT 0xF4E3AE

# define DOC_X 296
# define DOC_Y 356
# define DOC_INT 45

# define CAVE_MAP "maps/cave.cub"

// FONT

# define TUTO_FONT 0x545E5E
# define CAVE_FONT 0x545E5E
#endif