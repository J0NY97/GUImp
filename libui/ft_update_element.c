/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_element.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 16:38:36 by jsalmi            #+#    #+#             */
/*   Updated: 2020/08/27 15:16:17 by jsalmi           ###   ########.fr       */
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
	elem->surface = SDL_CreateRGBSurface(0, elem->w, elem->h, 32, 0, 0, 0, 0);
	while (++y < elem->h && (x = -1))
		while (++x < elem->w)
			set_pixel(elem->surface, x, y, elem->bg_color);
	if (elem->set_text == 1)
	{
		elem->text.parent = elem->surface;
		ft_create_text(&elem->text);
	}
}
