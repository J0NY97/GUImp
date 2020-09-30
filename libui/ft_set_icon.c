/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_icon.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 11:25:20 by nneronin          #+#    #+#             */
/*   Updated: 2020/09/17 11:25:50 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ft_set_icon(SDL_Window *window, char *dir)
{
	SDL_Surface *icon;

	if ((icon = load_image(dir)) == NULL)
		exit (0);
	SDL_SetWindowIcon(window, icon);
	SDL_FreeSurface(icon);
}
