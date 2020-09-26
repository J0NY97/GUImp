/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_workspace.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 18:03:24 by nneronin          #+#    #+#             */
/*   Updated: 2020/09/26 18:05:42 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guimp.h"

void	reset_workspace(SDL_Event e, t_element *elem)
{
	t_element **surfaces;

	surfaces = elem->extra_info;
	if (e.type == SDL_MOUSEBUTTONDOWN)
	{
		ft_printf("clicketi click clock\n");
		for (int i = 0; i < 5; i++)
		{
			SDL_FreeSurface(surfaces[i]->surface);
			surfaces[i]->surface = ft_create_rgba_surface(surfaces[i]->coord.w, surfaces[i]->coord.h);
		}
	}
}
