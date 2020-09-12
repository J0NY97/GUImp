/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_to_screen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 15:57:52 by nneronin          #+#    #+#             */
/*   Updated: 2020/09/12 11:00:34 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guimp.h"

void	text_to_screen(SDL_Surface *surface, t_shapes l, t_brush *brush)
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
	temp.x = l.x1 - (temp.w / 2);
	temp.y = l.y1 - (temp.h / 2);
	SDL_BlitSurface(surf, NULL, surface, &temp);
	SDL_FreeSurface(surf);
	TTF_CloseFont(font);
}
