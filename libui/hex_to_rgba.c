/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_to_rgba.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 13:51:34 by jsalmi            #+#    #+#             */
/*   Updated: 2020/09/10 12:17:56 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

SDL_Color	hex_to_rgba(int rgba)
{
	SDL_Color color;
	
	color.a = (rgba >> 24) & 0xFF;
	color.r = (rgba >> 16) & 0xFF;
	color.g = (rgba >> 8) & 0xFF;
	color.b = (rgba) & 0xFF;
	return (color);
}
