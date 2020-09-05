/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_to_screen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 15:57:52 by nneronin          #+#    #+#             */
/*   Updated: 2020/09/05 18:31:43 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guimp.h"

void	text_to_screen(t_element *elem, t_shapes l, t_brush *brush)
{
	SDL_Rect	temp;
	SDL_Surface *surf;
	TTF_Font	*font;

	font = TTF_OpenFont(brush->font_dir, brush->size);
	surf = TTF_RenderText_Blended(font,
								brush->str,
								hex_to_rgba(brush->color));
	temp.w = surf->w;
	temp.h = surf->h;
	temp.x = l.x2 - (temp.w / 2);
	temp.y = l.y2 - (temp.h / 2);
	SDL_BlitSurface(surf, NULL, elem->surface, &temp);
	SDL_FreeSurface(surf);
	TTF_CloseFont(font);
}
