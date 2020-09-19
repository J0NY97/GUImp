/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_window.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 13:15:15 by jsalmi            #+#    #+#             */
/*   Updated: 2020/09/19 11:24:04 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

t_window	*ft_create_window(t_libui *libui, t_window_info info)
{
	t_window *new_window;
	
	if (!(new_window = (t_window *)malloc(sizeof(t_window))))
		return (NULL);
	new_window->win = SDL_CreateWindow(info.title, info.coord.x, info.coord.y, info.coord.w, info.coord.h, 0);
	if (!new_window->win)
		printf("[create_window] : %s\n", SDL_GetError());
	new_window->surface = SDL_GetWindowSurface(new_window->win);
	ft_update_background(new_window->surface, info.bg_color);
	if (info.resizeable == 1)
		SDL_SetWindowResizable(new_window->win, 1);
	new_window->id = SDL_GetWindowID(new_window->win);
	new_window->elements = NULL;
	new_window->non_render = NULL;
	new_window->bg_color = info.bg_color;
	ft_strdel(&info.title);
	free(info.title); //probably useless
	ft_add_window_to_libui_windows(libui, new_window);
	return (new_window);
}
