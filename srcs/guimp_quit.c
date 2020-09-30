/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   guimp_quit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 13:43:28 by jsalmi            #+#    #+#             */
/*   Updated: 2020/09/30 12:29:02 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guimp.h"

void	guimp_quit(t_info *info)
{
	int i;

	SDL_FreeSurface(info->tooltips.pipette);
	SDL_FreeSurface(info->tooltips.move);
	SDL_FreeSurface(info->tooltips.flood);
	SDL_FreeSurface(info->tooltips.sticker);
	SDL_FreeSurface(info->tooltips.shapes);
	SDL_FreeSurface(info->tooltips.circle);
	SDL_FreeSurface(info->tooltips.deletion);
	SDL_FreeSurface(info->shape_img.orb);
	SDL_FreeSurface(info->shape_img.square);
	SDL_FreeSurface(info->shape_img.tube);
	SDL_FreeSurface(info->brush.stickers[0]);
	SDL_FreeSurface(info->brush.stickers[1]);
	ft_strdel(&info->brush.font_dir);
	ft_strdel(&info->brush.str);
	TTF_CloseFont(info->brush.font);
	free(info->toolbox);
	free(info->main);
	i = -1;
	while (++i < LAYER_NBR)
		free_element(info->drawing_surface[i]);
	free(info->layers);
	free(info);
}
