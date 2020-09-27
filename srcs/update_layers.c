/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_layers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 12:51:10 by nneronin          #+#    #+#             */
/*   Updated: 2020/09/27 15:51:36 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guimp.h"

void	update_layers(t_info *info)
{
	int			i;
	SDL_Surface *new_surf;

	i = -1;
	while (++i < info->layer_amount)
	{
		new_surf = ft_scale_surface_aspect(info->drawing_surface[i]->surface,
											info->layer_layers[i]->surface->w,
											info->layer_layers[i]->surface->h);
		SDL_BlitSurface(new_surf, NULL, info->layer_layers[i]->surface, NULL);
		SDL_FreeSurface(new_surf);
	}
	ft_update_background(info->screen_surface->surface, info->drawing_surface[0]->bg_color);
	i = -1;
	while (++i < info->layer_amount)
	{
		SDL_BlitScaled(info->drawing_surface[i]->surface, NULL,
				info->screen_surface->surface, NULL);
	}
}
