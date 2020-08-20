/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_window.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 13:15:15 by jsalmi            #+#    #+#             */
/*   Updated: 2020/08/20 11:21:19 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

t_window	*ft_create_window(t_window_info info)
{
	t_window *new_window;
	
	if (!(new_window = (t_window *)malloc(sizeof(t_window))))
	{
		ft_putstr("[create_window] New window couldnt be malloced.\n");
		return (NULL);
	}
//	new_window->button_amount = -1;		// remove in new iteration, maybe not
	new_window->win = SDL_CreateWindow(info.title, info.x, info.y, info.w, info.h, info.flags);
	new_window->surface = SDL_GetWindowSurface(new_window->win);
//	SDL_SetWindowResizable(new_window->win, info.resizeable);
	new_window->id = SDL_GetWindowID(new_window->win);
	return (new_window);
}
