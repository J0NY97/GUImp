/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 14:31:07 by jsalmi            #+#    #+#             */
/*   Updated: 2020/08/10 14:49:28 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guimp.h"

void	check_input(t_info *info)
{
	while (SDL_PollEvent(&info->event) != 0)
	{
		SDL_Keycode keypressed;
		if (info->event.type == SDL_QUIT || info->event.key.keysym.sym == SDLK_ESCAPE)
			info->run = 0;
	}
}
