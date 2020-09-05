/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_to_screen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 15:57:52 by nneronin          #+#    #+#             */
/*   Updated: 2020/09/05 15:06:29 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guimp.h"

void	text_to_screen(t_element *elem, t_shapes l, t_brush *brush)
{
	SDL_Rect	temp;
	SDL_Surface *surf;
	TTF_Font	*font;

	font = TTF_OpenFont(brush->font_dir, brush->size);
	temp.x = l.x2;
	temp.y = l.y2;
	surf = TTF_RenderText_Blended(font,
			brush->str, hex_to_rgba(brush->color));
	temp.w = surf->w;
	temp.h = surf->h;
	SDL_BlitSurface(surf, NULL, elem->surface, &temp);
	SDL_FreeSurface(surf);
	TTF_CloseFont(font);
}
