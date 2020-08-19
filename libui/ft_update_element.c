/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_element.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 16:38:36 by jsalmi            #+#    #+#             */
/*   Updated: 2020/08/19 19:13:30 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void		ft_update_element(t_element *elem)
{
	int x;
	int y;
	SDL_Rect temp;
	SDL_Surface *text;
	
	elem->surface = SDL_CreateRGBSurface(0, elem->w, elem->h, 32, 0, 0, 0, 0);
	y = -1;
	while (++y < elem->h && (x = -1))
		while (++x < elem->w)
			set_pixel(elem->surface, x, y, elem->bg_color);
	temp.x = elem->text_info.x;
	temp.y = elem->text_info.y;
	temp.w = 0;
	temp.h = 0;
	text = TTF_RenderText_Blended(elem->text_info.font, elem->text_info.text,
					hex_to_rgba(elem->text_info.color));
	SDL_BlitSurface(text, NULL, elem->surface, &temp);
	SDL_FreeSurface(text); //
}
