/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_button.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 13:37:55 by jsalmi            #+#    #+#             */
/*   Updated: 2020/08/15 14:44:09 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

/*
 ** Updates the button background to "color"
*/
int		ft_update_button(t_button *button, int bg_color, int txt_color)
{
	int i;
	int j;

	i = -1;
	while (++i < button->surface->h)
	{
		j = -1;
		while (++j < button->surface->w)
		{
			set_pixel(button->surface, j, i, bg_color);
		}
	}
	
	// @Fix: this whole shit
	SDL_Color color = hex_to_rgba(txt_color);
	SDL_Surface *temp_surf = TTF_RenderText_Blended(button->font, button->text, color);
	
	SDL_Rect temp;
	temp.w = button->surface->w;
	temp.h = button->surface->h;
	temp.x = temp.w / 2 - (temp_surf->w / 2);
	temp.y = temp.h / 2 - (temp_surf->h / 2);
	SDL_BlitSurface(temp_surf, NULL, button->surface, &temp);
	SDL_FreeSurface(temp_surf);
	return (1);	
}
