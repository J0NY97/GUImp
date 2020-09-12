/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_button_image.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 12:30:44 by jsalmi            #+#    #+#             */
/*   Updated: 2020/09/12 13:56:43 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ft_set_element_image(t_element *elem, SDL_Surface *img)
{
	SDL_Rect temp;

	elem->set_text = 0;
	temp.h = elem->surface->h;
	temp.w = temp.h;
	temp.x = temp.w / 2;
	temp.y = 0;
	SDL_BlitScaled(img, NULL, elem->states[0], &temp);
	SDL_BlitScaled(img, NULL, elem->states[2], &temp);
	SDL_BlitScaled(img, NULL, elem->states[1], &temp);
	SDL_BlitScaled(img, NULL, elem->surface, &temp);
}
