/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 14:09:34 by nneronin          #+#    #+#             */
/*   Updated: 2020/09/09 14:18:00 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

SDL_Surface	*ft_scale_surface(SDL_Surface *surface, int w, int h)
{
	SDL_Surface *surf;

	surf = SDL_CreateRGBSurface(0, w, h, 32, 0, 0, 0, 0);
	SDL_BlitScaled(surface, NULL, surf, NULL);
	return (surf);
}
