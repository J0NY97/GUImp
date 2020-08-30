/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_element.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 16:38:36 by jsalmi            #+#    #+#             */
/*   Updated: 2020/08/30 13:51:45 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void		ft_update_element(t_element *elem)
{
	int x;
	int y;
	SDL_Rect temp;
	
	y = -1;
	SDL_FreeSurface(elem->surface); // dont worry about this line
	SDL_FreeSurface(elem->states[0]); // dont worry about this line
	SDL_FreeSurface(elem->states[1]); // dont worry about this line
	SDL_FreeSurface(elem->states[2]); // dont worry about this line
	elem->surface = SDL_CreateRGBSurface(0, elem->w, elem->h, 32, 0, 0, 0, 0);
	// @Improvement: make this a loop if its smart
	elem->states[0] = SDL_CreateRGBSurface(0, elem->w, elem->h, 32, 0, 0, 0, 0);
	elem->states[1] = SDL_CreateRGBSurface(0, elem->w, elem->h, 32, 0, 0, 0, 0);
	elem->states[2] = SDL_CreateRGBSurface(0, elem->w, elem->h, 32, 0, 0, 0, 0);
	while (++y < elem->h && (x = -1))
	{
		while (++x < elem->w)
		{
			set_pixel(elem->states[0], x, y, elem->bg_color);
			set_pixel(elem->states[1], x, y, elem->bg_color & 0xff);
			set_pixel(elem->states[2], x, y, 0x00ff00);
		}
	}
	SDL_BlitSurface(elem->states[elem->state], NULL, elem->surface, NULL);
	if (elem->set_text == 1)
	{
		elem->text.parent = elem->surface;
		ft_create_text(&elem->text);
	}
}
