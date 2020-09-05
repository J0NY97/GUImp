/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_text.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 17:32:45 by jsalmi            #+#    #+#             */
/*   Updated: 2020/09/05 16:42:53 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ft_create_text(t_text *text)
{
	SDL_Rect	temp;

	temp.x = text->x;
	temp.y = text->y;
	text->surface = TTF_RenderText_Blended_Wrapped(
			text->font, text->text, hex_to_rgba(text->color),
			(text->parent->w - text->margin));
	temp.w = text->surface->w;
	temp.h = text->surface->h;
	if (text->centered == 1)
	{
		temp.x = (text->parent->w / 2) - (text->surface->w / 2);
		temp.y = (text->parent->h / 2) - (text->surface->h / 2);
	}
	SDL_BlitSurface(text->surface, NULL, text->parent, &temp);
	SDL_FreeSurface(text->surface);
}
