/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   guimp_quit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 13:43:28 by jsalmi            #+#    #+#             */
/*   Updated: 2020/09/17 14:14:02 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guimp.h"

void	guimp_quit(t_info *info)
{
	{ // windows
/*		ft_putstr("window deletion\n");
		free_window(info->toolbox->window);
		free_window(info->main->window);
		free_window(info->layers->window);*/
	}
	{ // tooltips surface
		ft_putstr("tooltips deletion\n");
		SDL_FreeSurface(info->tooltips.pipette);
		SDL_FreeSurface(info->tooltips.move);
		SDL_FreeSurface(info->tooltips.flood);
		SDL_FreeSurface(info->tooltips.sticker);
		SDL_FreeSurface(info->tooltips.shapes);
		SDL_FreeSurface(info->tooltips.circle);
		SDL_FreeSurface(info->tooltips.deletion);
	}
	{ // shape img surface
		ft_putstr("shape img deletion\n");
		SDL_FreeSurface(info->shape_img.orb);
		SDL_FreeSurface(info->shape_img.square);
		SDL_FreeSurface(info->shape_img.tube);
	}
	{ // element arrays
		ft_putstr("element array deletion\n");
//		free(info->buttons);
//		free(info->shapes);
//		free(info->drawing_surface);
//		free(info->layer_layers);
//		free(info->layer_buttons);
	}
	ft_putstr("info deletion\n");
	free(info);
}
