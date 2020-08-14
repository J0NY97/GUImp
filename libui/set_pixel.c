/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 15:57:02 by jsalmi            #+#    #+#             */
/*   Updated: 2020/08/14 15:57:28 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void    set_pixel(SDL_Surface *surf, int x, int y, Uint32 color)
{
	Uint32 *pixels;

    pixels = surf->pixels;
    pixels[y * surf->w + x] = color;
}
