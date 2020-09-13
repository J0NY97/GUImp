/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 15:57:02 by jsalmi            #+#    #+#             */
/*   Updated: 2020/09/13 16:39:54 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void    set_pixel(SDL_Surface *surf, int x, int y, Uint32 color)
{
	Uint32 *pixels;

    pixels = surf->pixels;
    pixels[y * surf->w + x] = color;
}

/*void    set_blended_pixel(SDL_Surface *surf, int x, int y, Uint32 color)
{
	Uint32 *pixels;
	Uint32	new_color;
	SDL_Color	c1;
	SDL_Color	c2;

    pixels = surf->pixels;
	c1 = hex_to_rgba(pixels[y * surf->w + x]);
	c2 = hex_to_rgba(color);
	//c1.a = c1.a + c2.a;
	c1.r = c1.r + c2.r;
	c1.g = c1.g + c2.g;
	c1.b = c1.b + c2.b;
	new_color = rgb_to_hex(c1.r, c1.g, c1.b, c1.a);
    pixels[y * surf->w + x] = new_color;
}
*/
void    set_blended_pixel(SDL_Surface *surf, int x, int y, Uint32 color)
{
	int		a;
	int		inv_a;
	Uint32 *pixels;
	Uint32	new_color;
	SDL_Color	c1;
	SDL_Color	c2;

    pixels = surf->pixels;
	c1 = hex_to_rgba(pixels[y * surf->w + x]);
	c2 = hex_to_rgba(color);
	a = c2.a + 1;
	inv_a = 256 - c2.a;

	c1.r = (((c1.r * inv_a) + (c2.r * a)) >> 8);
	c1.g = (((c1.g * inv_a) + (c2.g * a)) >> 8);
	c1.b = (((c1.b * inv_a) + (c2.b * a)) >> 8);
	c1.a = 0xff;
	new_color = rgb_to_hex(c1.r, c1.g, c1.b, c1.a);
    pixels[y * surf->w + x] = new_color;
}
