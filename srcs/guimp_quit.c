/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   guimp_quit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 13:43:28 by jsalmi            #+#    #+#             */
/*   Updated: 2020/09/26 15:10:10 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guimp.h"

void	guimp_quit(t_info *info)
{
	SDL_FreeSurface(info->tooltips.pipette);
	SDL_FreeSurface(info->tooltips.move);
	SDL_FreeSurface(info->tooltips.flood);
	SDL_FreeSurface(info->tooltips.sticker);
	SDL_FreeSurface(info->tooltips.shapes);
	SDL_FreeSurface(info->tooltips.circle);
	SDL_FreeSurface(info->tooltips.deletion);
	SDL_FreeSurface(info->shape_img.orb);
	SDL_FreeSurface(info->shape_img.square);
	free(info);
}
