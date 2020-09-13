/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_help.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 18:13:19 by nneronin          #+#    #+#             */
/*   Updated: 2020/09/13 18:25:19 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

SDL_Surface 	*ft_create_rgba_surface(int w, int h)
{
	return (SDL_CreateRGBSurface(0, w, h, 32,
				0xff0000, 0x00ff00, 0x0000ff, 0xff000000));
}
