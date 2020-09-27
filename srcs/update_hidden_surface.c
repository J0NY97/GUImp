/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_hiden_surface.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 10:40:35 by nneronin          #+#    #+#             */
/*   Updated: 2020/09/27 12:49:38 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guimp.h"

static inline void	blit_tooltip2(t_info *info, t_shapes l)
{
	SDL_Rect temp;

	if (info->brush.type == 5)
	{
		temp = ft_sdl_rect(l.x1 - 128 / 2, l.y1 - 128 / 2, 128, 128);
		SDL_BlitSurface(info->brush.stickers[info->brush.selected_sticker],
				NULL, HIDDEN_SURF, &temp);
	}
	else if (info->brush.type == 6)
	{
		temp = ft_sdl_rect(l.x1 - (20 / 2), l.y1 - (20 / 2), 20, 20);
		SDL_BlitSurface(info->tooltips.move, NULL, HIDDEN_SURF, &temp);
	}
	else if (info->brush.type == 7)
		trace_shape(info);
	else if (info->brush.type == 8)
	{
		temp = ft_sdl_rect(l.x1, l.y1 - 20, 20, 20);
		SDL_BlitSurface(info->tooltips.pipette, NULL, HIDDEN_SURF, &temp);
	}
}

static inline void	blit_tooltip(t_info *info, t_shapes l)
{
	SDL_Rect temp;

	if (info->brush.type == 1)
		ft_create_circle(HIDDEN_SURF, info->brush.color, l);
	else if (info->brush.type == 2)
		text_to_screen(HIDDEN_SURF, l, info->brush.str, info->brush.font_dir);
	else if (info->brush.type == 3)
	{
		ft_create_circle(HIDDEN_SURF,
				info->drawing_surface[info->brush.selected_layer]->bg_color, l);
	}
	else if (info->brush.type == 4)
	{
		temp = ft_sdl_rect(l.x1, l.y1 - 20, 20, 20);
		SDL_BlitSurface(info->tooltips.flood, NULL, HIDDEN_SURF, &temp);
	}
	else
		blit_tooltip2(info, l);
}

void				update_hidden_surface(t_info *info, t_libui *libui)
{
	t_shapes	l;

	l = info->brush.shape;
	l.x1 = libui->event.button.x;
	l.y1 = libui->event.button.y;
	l.size = info->brush.size / info->brush.aspect_x;
	ft_update_background(info->hidden_surface->surface, 0x00000000);
	if (libui->event.window.windowID == info->main->window->id)
	{
		l.fill = info->brush.type == 1 ? 0 : 1;
		blit_tooltip(info, l);
	}
}
