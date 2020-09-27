/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drag_drop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 13:02:21 by nneronin          #+#    #+#             */
/*   Updated: 2020/09/27 13:03:09 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guimp.h"

void	drag_drop(t_info *info, t_libui *libui)
{
	SDL_Surface *new_image;

	if (libui->drag_file != NULL)
	{
		if ((new_image = load_image(libui->drag_file)))
		{
			SDL_BlitSurface(new_image, NULL,
					info->drawing_surface[info->brush.selected_layer]->surface,
					NULL);
			SDL_FreeSurface(new_image);
		}
		ft_strdel(&libui->drag_file);
	}
}
