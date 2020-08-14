/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_button.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 12:07:14 by jsalmi            #+#    #+#             */
/*   Updated: 2020/08/14 16:01:58 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void		click(void)
{
	ft_putstr("button clicked");
}

int			ft_create_button(t_button_info info)
{
	t_button *new_button;
	if (!(new_button = (t_button *)malloc(sizeof(t_button))))
		ft_putstr("[create_button] Couldnt malloc new button.\n");
	new_button->surface = SDL_CreateRGBSurface(0, info.w, info.h, 32, 0, 0, 0, 0);
	new_button->f = &click;
	new_button->x = info.x;
	new_button->y = info.y;
	new_button->font = info.font;
	info.win->buttons[++info.win->button_amount] = new_button;
	
	// delte ths
	for (int i = 0; i < info.h; i++)
	{
		for (int j = 0; j < info.w; j++)
		{
			set_pixel(new_button->surface, j, i, 0xffffff);
		}
	}

	SDL_Rect temp;
	temp.x = info.x;
	temp.y = info.y;
	temp.w = info.w;
	temp.h = info.h;
	SDL_Color color = {0, 255, 0, 0};
	SDL_Surface *temp_surf = TTF_RenderText_Blended(info.font, info.text, color);
	SDL_BlitSurface(temp_surf, NULL, new_button->surface, NULL);
	return (1);
}
