/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 15:56:30 by jsalmi            #+#    #+#             */
/*   Updated: 2020/09/16 15:56:49 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

Uint32  get_color(SDL_Surface *surface, int x, int y)
{
    Uint32 *pixels;

	pixels = surface->pixels;
	return (pixels[y * surface->w + x]);
}
