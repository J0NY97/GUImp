/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_icon.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 11:25:20 by nneronin          #+#    #+#             */
/*   Updated: 2020/09/05 12:11:52 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ft_set_icon(SDL_Window *window, char *dir)
{
	SDL_Surface *icon;

	icon = load_image(dir);
	SDL_SetWindowIcon(window, icon);
	SDL_FreeSurface(icon);
}
