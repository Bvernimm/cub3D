/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_document.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaruell <llaruell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 14:28:13 by llaruell          #+#    #+#             */
/*   Updated: 2023/01/03 10:45:47 by llaruell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_doc_font(t_game *game)
{
	t_coord	b_font;
	t_coord	w_font;

	b_font.y = B_FONT_Y;
	while (b_font.y < game->win.height - B_FONT_Y)
	{
		b_font.x = B_FONT_X;
		while (b_font.x < game->win.width - B_FONT_X)
		{
			pixel_draw(b_font.x, b_font.y, B_FONT, game);
			b_font.x++;
		}
		b_font.y++;
	}
	w_font.y = W_FONT_Y;
	while (w_font.y < game->win.height - W_FONT_Y)
	{
		w_font.x = W_FONT_X;
		while (w_font.x < game->win.width - W_FONT_X)
		{
			pixel_draw(w_font.x, w_font.y, W_FONT, game);
			w_font.x++;
		}
		w_font.y++;
	}
}

void	get_doc_tuto(t_game *game, int id)
{
	if (id == 1)
		tuto1(game);
	else if (id == 2)
		tuto2(game);
}

void	get_doc(t_game *game, int id)
{
	if (id == 1)
		document1(game);
	else if (id == 2)
		document2(game);
	else if (id == 3)
		document3(game);
	else if (id == 4)
		document4(game);
	else if (id == 5)
		document5(game);
	else if (id == 6)
		document6(game);
	else if (id == 7)
		document7(game);
	else if (id == 8)
		document8(game);
	else if (id == 9)
		document9(game);
	else if (id == 10)
		document10(game);
}

void	draw_string(t_game *game)
{
	if (game->control.level == 0)
		get_doc_tuto(game, game->control.id_doc);
	else if (game->control.level == 1)
		get_doc(game, game->control.id_doc);
}

void	draw_document(t_game *game)
{
	draw_doc_font(game);
	draw(game);
	draw_string(game);
}
