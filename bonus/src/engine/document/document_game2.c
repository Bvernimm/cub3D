/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   document_game2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvernimm <bvernimm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 14:28:07 by llaruell          #+#    #+#             */
/*   Updated: 2023/01/03 11:06:02 by bvernimm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	document6(t_game *game)
{
	mlx_string_put(game->mlx, game->win.mlx_ptr, 525, 256,
		C_DOC, "    Notes des developpeurs    ");
	mlx_string_put(game->mlx, game->win.mlx_ptr, 525, 256 + 30,
		C_DOC, " ---------------------------- ");
	mlx_string_put(game->mlx, game->win.mlx_ptr, DOC_X, DOC_Y,
		C_DOC, "Pas de bol... Tu as perdu !");
	mlx_string_put(game->mlx, game->win.mlx_ptr, DOC_X, DOC_Y + DOC_INT,
		C_DOC, "Evite de gacher tes cles ainsi a l'avenir...");
	mlx_string_put(game->mlx, game->win.mlx_ptr, DOC_X, DOC_Y + DOC_INT * 3,
		C_DOC, "=== Le sais-tu ? ===");
	mlx_string_put(game->mlx, game->win.mlx_ptr, DOC_X, DOC_Y + DOC_INT * 4,
		C_DOC, "Tu peux te deplacer sans utiliser les touches de mouvements.");
}

void	document7(t_game *game)
{
	mlx_string_put(game->mlx, game->win.mlx_ptr, 515, 256,
		C_DOC, "    Notes de l'intendante    ");
	mlx_string_put(game->mlx, game->win.mlx_ptr, 515, 256 + 30,
		C_DOC, " --------------------------- ");
	mlx_string_put(game->mlx, game->win.mlx_ptr, DOC_X, DOC_Y,
		C_DOC, "Ses cris me glacent le sang...");
	mlx_string_put(game->mlx, game->win.mlx_ptr, DOC_X, DOC_Y + DOC_INT,
		C_DOC, "Que realise le seigneur Faust avec ces enfants ?");
	mlx_string_put(game->mlx, game->win.mlx_ptr, DOC_X, DOC_Y + DOC_INT * 2,
		C_DOC, "Si seulement, il ne l'avait pas perdu...");
}

void	document8(t_game *game)
{
	mlx_string_put(game->mlx, game->win.mlx_ptr, 550, 256,
		C_DOC, "    Necrologie    ");
	mlx_string_put(game->mlx, game->win.mlx_ptr, 550, 256 + 30,
		C_DOC, " ---------------- ");
	mlx_string_put(game->mlx, game->win.mlx_ptr, DOC_X, DOC_Y,
		C_DOC, "Trois corps retrouves dans le Bois du Cerf");
	mlx_string_put(game->mlx, game->win.mlx_ptr, DOC_X, DOC_Y + DOC_INT,
		C_DOC, "Modus operandi est toujours identique : ");
	mlx_string_put(game->mlx, game->win.mlx_ptr, DOC_X, DOC_Y + DOC_INT * 2,
		C_DOC, " -> Poitrine arrachee");
	mlx_string_put(game->mlx, game->win.mlx_ptr, DOC_X, DOC_Y + DOC_INT * 3,
		C_DOC, " -> Jambes coupees");
	mlx_string_put(game->mlx, game->win.mlx_ptr, DOC_X, DOC_Y + DOC_INT * 4,
		C_DOC, " -> Tete deformee");
	mlx_string_put(game->mlx, game->win.mlx_ptr, DOC_X, DOC_Y + DOC_INT * 6,
		C_DOC, "Evitez autant que possible le Bois du Cerf !");
}

void	document9(t_game *game)
{
	mlx_string_put(game->mlx, game->win.mlx_ptr, 515, 256,
		C_DOC, "    Notes de l'intendante    ");
	mlx_string_put(game->mlx, game->win.mlx_ptr, 515, 256 + 30,
		C_DOC, " --------------------------- ");
	mlx_string_put(game->mlx, game->win.mlx_ptr, DOC_X, DOC_Y,
		C_DOC, "Cet imbecile est cense etre en chemin...");
	mlx_string_put(game->mlx, game->win.mlx_ptr, DOC_X, DOC_Y + DOC_INT,
		C_DOC, "Les hommes sont si manipulables...");
	mlx_string_put(game->mlx, game->win.mlx_ptr, DOC_X, DOC_Y + DOC_INT * 2,
		C_DOC, "Une paire de seins et le tour est joue !");
	mlx_string_put(game->mlx, game->win.mlx_ptr, DOC_X, DOC_Y + DOC_INT * 3,
		C_DOC, "J'ai quand meme un peu de peine...");
	mlx_string_put(game->mlx, game->win.mlx_ptr, DOC_X, DOC_Y + DOC_INT * 6,
		C_DOC, "Si seulement il savait ce qui l'attend...");
}

void	document10(t_game *game)
{
	mlx_string_put(game->mlx, game->win.mlx_ptr, 525, 256,
		C_DOC, "    Notes des developpeurs    ");
	mlx_string_put(game->mlx, game->win.mlx_ptr, 525, 256 + 30,
		C_DOC, " ---------------------------- ");
	mlx_string_put(game->mlx, game->win.mlx_ptr, DOC_X, DOC_Y,
		C_DOC, "Pas de bol... Tu as perdu !");
	mlx_string_put(game->mlx, game->win.mlx_ptr, DOC_X, DOC_Y + DOC_INT,
		C_DOC, "J'ai comme une sensation de deja-vu... Peu importe...");
	mlx_string_put(game->mlx, game->win.mlx_ptr, DOC_X, DOC_Y + DOC_INT * 2,
		C_DOC, "Tu cherches la sortie ? D'accord, un petit d'indice !");
	mlx_string_put(game->mlx, game->win.mlx_ptr, DOC_X, DOC_Y + DOC_INT * 4,
		C_DOC, " ~~ Sens-tu son coeur hurler maintenant");
	mlx_string_put(game->mlx, game->win.mlx_ptr, DOC_X, DOC_Y + DOC_INT * 5,
		C_DOC, " ~~ Et elle agite");
	mlx_string_put(game->mlx, game->win.mlx_ptr, DOC_X, DOC_Y + DOC_INT * 6,
		C_DOC, " ~~ Sens-tu ton corps m'emprisonner");
	mlx_string_put(game->mlx, game->win.mlx_ptr, DOC_X, DOC_Y + DOC_INT * 7,
		C_DOC, " ~~ Quand je me deverse en toi");
	mlx_string_put(game->mlx, game->win.mlx_ptr, DOC_X, DOC_Y + DOC_INT * 9,
		C_DOC, "Tu as aime ces quelques vers de Gouvart ?");
}
