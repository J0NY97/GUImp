/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_text.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 17:32:45 by jsalmi            #+#    #+#             */
/*   Updated: 2020/09/16 16:11:17 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ft_create_text(t_text *text)
{
	SDL_Rect	temp;
	SDL_Surface	*tsurf;

	temp.x = text->x;
	temp.y = text->y;
	if (!text->font)
		printf("create_text font is null\n");
	tsurf = TTF_RenderText_Blended_Wrapped(text->font, text->text,
											hex_to_rgba(text->color),
											(text->parent->w - text->margin));
	if (tsurf == NULL)
	{
		printf("create_text : %s\n", TTF_GetError());
		return ;
	}
	temp.w = tsurf->w;
	temp.h = tsurf->h;
	if (text->centered == 1)
	{
		temp.x = (text->parent->w / 2) - (tsurf->w / 2);
		temp.y = (text->parent->h / 2) - (tsurf->h / 2);
	}
	SDL_BlitSurface(tsurf, NULL, text->parent, &temp);
	SDL_FreeSurface(tsurf);
}
