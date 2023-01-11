/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   document_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaruell <llaruell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 14:23:34 by llaruell          #+#    #+#             */
/*   Updated: 2023/01/03 08:38:46 by llaruell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	document1(t_game *game)
{
	mlx_string_put(game->mlx, game->win.mlx_ptr, 550, 256,
		C_DOC, "     Depliant     ");
	mlx_string_put(game->mlx, game->win.mlx_ptr, 550, 256 + 30,
		C_DOC, " ---------------- ");
	mlx_string_put(game->mlx, game->win.mlx_ptr, DOC_X, DOC_Y,
		C_DOC, "Le chateau Geowind, bati au onzieme siecle par la famille");
	mlx_string_put(game->mlx, game->win.mlx_ptr, DOC_X, DOC_Y + DOC_INT,
		C_DOC, " Geowind, fut l'un de premiers bijoux de la region.");
	mlx_string_put(game->mlx, game->win.mlx_ptr, DOC_X, DOC_Y + DOC_INT * 2,
		C_DOC, "D'une superficie d'un peu plus de 40 metres carres,");
	mlx_string_put(game->mlx, game->win.mlx_ptr, DOC_X, DOC_Y + DOC_INT * 3,
		C_DOC, " il a servi de refuge pour la population lors des differentes");
	mlx_string_put(game->mlx, game->win.mlx_ptr, DOC_X, DOC_Y + DOC_INT * 4,
		C_DOC, " catastrophes de ces derniers siecles tel que durant");
	mlx_string_put(game->mlx, game->win.mlx_ptr, DOC_X, DOC_Y + DOC_INT * 5,
		C_DOC, " la Peste noire.");
	mlx_string_put(game->mlx, game->win.mlx_ptr, DOC_X, DOC_Y + DOC_INT * 6,
		C_DOC, "Transforme en domaine viticole dans les annees 1820");
	mlx_string_put(game->mlx, game->win.mlx_ptr, DOC_X, DOC_Y + DOC_INT * 7,
		C_DOC, " pour eviter une ruine, son vin est l'un des plus apprécies ");
	mlx_string_put(game->mlx, game->win.mlx_ptr, DOC_X, DOC_Y + DOC_INT * 8,
		C_DOC, " des amateurs.");
}

void	document2(t_game *game)
{
	mlx_string_put(game->mlx, game->win.mlx_ptr, 450, 256,
		C_DOC, "    Page d'un guide touristique     ");
	mlx_string_put(game->mlx, game->win.mlx_ptr, 450, 256 + 30,
		C_DOC, " ---------------------------------- ");
	mlx_string_put(game->mlx, game->win.mlx_ptr, DOC_X, DOC_Y,
		C_DOC, "Le chateau Geowind est reconnu pour son vin rouge");
	mlx_string_put(game->mlx, game->win.mlx_ptr, DOC_X, DOC_Y + DOC_INT,
		C_DOC, " d'excellente qualite.");
	mlx_string_put(game->mlx, game->win.mlx_ptr, DOC_X, DOC_Y + DOC_INT * 2,
		C_DOC, "D'un grenat fonce, il exhalent des aromes de framboises et de");
	mlx_string_put(game->mlx, game->win.mlx_ptr, DOC_X, DOC_Y + DOC_INT * 3,
		C_DOC, " fraises avec des notes d'amandes ameres en fonction");
	mlx_string_put(game->mlx, game->win.mlx_ptr, DOC_X, DOC_Y + DOC_INT * 4,
		C_DOC, " des recoltes.");
	mlx_string_put(game->mlx, game->win.mlx_ptr, DOC_X, DOC_Y + DOC_INT * 5,
		C_DOC, "Les vins jeunes peuvent etre austeres, cependant,");
	mlx_string_put(game->mlx, game->win.mlx_ptr, DOC_X, DOC_Y + DOC_INT * 6,
		C_DOC, " apres quelques annees, la bouche revele une grande finesse.");
}

void	document3(t_game *game)
{
	mlx_string_put(game->mlx, game->win.mlx_ptr, 425, 256,
		C_DOC, "    Message a l'attention de l'intendante    ");
	mlx_string_put(game->mlx, game->win.mlx_ptr, 425, 256 + 30,
		C_DOC, " ------------------------------------------- ");
	mlx_string_put(game->mlx, game->win.mlx_ptr, DOC_X, DOC_Y,
		C_DOC, "Miss Mia, je pars quelques temps.");
	mlx_string_put(game->mlx, game->win.mlx_ptr, DOC_X, DOC_Y + DOC_INT,
		C_DOC, " Veuillez penser a nourrir notre ami.");
	mlx_string_put(game->mlx, game->win.mlx_ptr, DOC_X, DOC_Y + DOC_INT * 8,
		C_DOC2, "Salopard... C'est toujours a moi de faire votre sale boulot");
	mlx_string_put(game->mlx, game->win.mlx_ptr, DOC_X, DOC_Y + DOC_INT * 9,
		C_DOC2, " A votre retour, c'est termine !");
}

void	document4(t_game *game)
{
	mlx_string_put(game->mlx, game->win.mlx_ptr, 475, 256,
		C_DOC, "    Message d'un prisonnier    ");
	mlx_string_put(game->mlx, game->win.mlx_ptr, 475, 256 + 30,
		C_DOC, " ----------------------------- ");
	mlx_string_put(game->mlx, game->win.mlx_ptr, DOC_X, DOC_Y,
		C_DOC, "Je ne sais pas ce qu'il m'arrive...");
	mlx_string_put(game->mlx, game->win.mlx_ptr, DOC_X, DOC_Y + DOC_INT,
		C_DOC, "         J'ai mal... J'ai tellement mal... ");
	mlx_string_put(game->mlx, game->win.mlx_ptr, DOC_X, DOC_Y + DOC_INT * 2,
		C_DOC, "   Ma poitrine me serre tant... ");
	mlx_string_put(game->mlx, game->win.mlx_ptr, DOC_X, DOC_Y + DOC_INT * 3,
		C_DOC, "  Seigneur, qu'ai-je fais pour meriter un tel chatiment ?");
	mlx_string_put(game->mlx, game->win.mlx_ptr, DOC_X, DOC_Y + DOC_INT * 4,
		C_DOC, "     Est-ce ma punition pour avoir suivi cette femme ?");
}

void	document5(t_game *game)
{
	mlx_string_put(game->mlx, game->win.mlx_ptr, 525, 256,
		C_DOC, "    Notes de Faust    ");
	mlx_string_put(game->mlx, game->win.mlx_ptr, 525, 256 + 30,
		C_DOC, " -------------------- ");
	mlx_string_put(game->mlx, game->win.mlx_ptr, DOC_X, DOC_Y,
		C_DOC, "J'y suis enfin arriver ! L'evolution est en marche !");
	mlx_string_put(game->mlx, game->win.mlx_ptr, DOC_X, DOC_Y + DOC_INT,
		C_DOC, "Il n'y a plus qu'a la repeter jusqu'a maitriser parfaitement");
	mlx_string_put(game->mlx, game->win.mlx_ptr, DOC_X, DOC_Y + DOC_INT * 2,
		C_DOC, " le phenomene.");
	mlx_string_put(game->mlx, game->win.mlx_ptr, DOC_X, DOC_Y + DOC_INT * 3,
		C_DOC, "Mon rat de laboratoire pleurait toutes les nuits...");
	mlx_string_put(game->mlx, game->win.mlx_ptr, DOC_X, DOC_Y + DOC_INT * 4,
		C_DOC, "Si seulement ses pleurs avaient l'elegance d'un brame...");
}
