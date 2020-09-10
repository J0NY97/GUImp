/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_libui_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 14:49:35 by jsalmi            #+#    #+#             */
/*   Updated: 2020/09/10 13:48:48 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ui_libui_init(t_libui *libui)
{
	SDL_Init(SDL_INIT_VIDEO);
	TTF_Init();
	IMG_Init(0);
	libui->windows = NULL;
	libui->hotkeys = NULL;
	libui->run = 1;
}
