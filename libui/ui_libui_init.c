/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_libui_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 14:49:35 by jsalmi            #+#    #+#             */
/*   Updated: 2020/09/19 11:29:57 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ui_libui_init(t_libui *libui)
{
	SDL_Init(SDL_INIT_VIDEO);
	TTF_Init();
	IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG);
	libui->windows = NULL;
	libui->hotkeys = NULL;
	libui->quit = 0;
	libui->drag_file = NULL;
}
