/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_window.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 13:15:15 by jsalmi            #+#    #+#             */
/*   Updated: 2020/08/10 14:46:48 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

// @Improvement: this could take the whole a SDL_Rect or something instead of all the different args
SDL_Window	*ft_create_window(char *title, int x, int y, int w, int h, int resizeable)
{
	SDL_Window *win;

	win = SDL_CreateWindow(title, x, y, w, h, 0);
	SDL_SetWindowResizable(win, resizeable);
	return (win);
}
