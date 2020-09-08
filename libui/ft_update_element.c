/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_element.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 16:38:36 by jsalmi            #+#    #+#             */
/*   Updated: 2020/09/02 17:29:09 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void		ft_update_element(t_element *elem)
{
	if (elem->statique == 0)
	{
		if (elem->state != elem->old_state)
		{
			// @Improvement: read libui project!!!!
			SDL_FreeSurface(elem->surface);
			elem->surface = SDL_CreateRGBSurface(0, elem->states[elem->state]->w, elem->states[elem->state]->h, 32, 0, 0, 0, 0);
			SDL_BlitSurface(elem->states[elem->state], NULL, elem->surface, NULL);
			if (elem->set_text == 1)
			{
				elem->text.parent = elem->surface;
				ft_create_text(&elem->text);
			}
		}
		elem->old_state = elem->state;
	}
}
