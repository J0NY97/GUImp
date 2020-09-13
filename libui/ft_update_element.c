/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_element.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 16:38:36 by jsalmi            #+#    #+#             */
/*   Updated: 2020/09/13 18:45:34 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void		ft_update_element(t_element *elem)
{
	if (elem->statique == 0)
	{
		if (elem->state != elem->old_state)
		{
			SDL_FreeSurface(elem->surface);
			elem->surface = ft_create_rgba_surface(
												elem->states[elem->state]->w,
												elem->states[elem->state]->h);
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
