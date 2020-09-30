/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_workspace.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 18:03:24 by nneronin          #+#    #+#             */
/*   Updated: 2020/09/30 15:48:49 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guimp.h"

void	reset_workspace(SDL_Event e, t_element *elem)
{
	int			i;
	t_element	**surfaces;

	surfaces = elem->extra_info;
	if (e.type == SDL_MOUSEBUTTONDOWN)
	{
		i = -1;
		while (++i < LAYER_NBR)
		{
			SDL_FreeSurface(surfaces[i]->surface);
			surfaces[i]->surface = ft_create_rgba_surface(surfaces[i]->coord.w,
					surfaces[i]->coord.h);
		}
	}
}
