/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_text.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 17:32:45 by jsalmi            #+#    #+#             */
/*   Updated: 2020/08/22 17:44:24 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ft_create_text(t_text *text)
{
	SDL_Rect	temp;

	temp.x = text->x;
	temp.y = text->y;
	text->surface = TTF_RenderText_Blended(text->font, text->text, hex_to_rgba(text->color));
	temp.w = text->surface->w;
	temp.h = text->surface->h;
	SDL_BlitSurface(text->surface, NULL, text->parent, &temp);
}
