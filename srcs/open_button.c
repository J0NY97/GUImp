/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_button.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 18:06:19 by nneronin          #+#    #+#             */
/*   Updated: 2020/09/26 18:07:01 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guimp.h"

void	open_button(SDL_Event e, t_element *elem)
{
	char		*file;
	t_brush		*brush;
	SDL_Rect	temp;
	t_button	*button;
	t_element	**surfaces;
	SDL_Surface	*image;

	button = elem->info;
	brush = button->extra;
	surfaces = elem->extra_info;
	if (e.type == SDL_MOUSEBUTTONDOWN)
	{
		file = dir_explore("./images", DT_REG);
		if (file != NULL)
		{
			image = load_image(file);
			if (image != NULL)
			{
				temp = ft_sdl_rect(0, 0, image->w, image->h);
				SDL_BlitScaled(image, NULL, surfaces[brush->selected_layer]->surface, &temp);
				SDL_FreeSurface(image);
			}
			else
				ft_putstr("open_button: image couldnt be loaded\n");
			ft_strdel(&file);
		}
		else
			ft_putstr("open_button: file doesnt exist\n");
	}
}
