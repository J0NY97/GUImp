/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   popup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 14:01:15 by nneronin          #+#    #+#             */
/*   Updated: 2020/08/30 14:57:26 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

# define BY event.button.y
# define BX event.button.x

void	notify(char *title, char *msg)
{
	SDL_ShowSimpleMessageBox(
			SDL_MESSAGEBOX_INFORMATION,
			title,
			msg,
			NULL);
}

void	error_msg(char *str)
{
	SDL_ShowSimpleMessageBox(
			SDL_MESSAGEBOX_ERROR,
			"Error",
			str,
			NULL);
	ft_putstr(str);
	exit(1);
}

int			pop_up(int x1, int y1, char *msg) //int returns true or false
{
	t_window		*win;
	t_window_info	test;
	SDL_Event event;
	t_libui *libui;

	test.x = 0;
	test.y = 0;
	test.w = 350;
	test.h = 300;
	test.resizeable = 0;
	test.title = ft_strdup("PoPuP");
	win = ft_create_window(libui, test);
	ft_update_background(win->surface, 0xECECEC);

	SDL_Surface *tmp;
	SDL_Rect	temp;
	int x;
	int y;

	y = 200;
	while (++y < 250 && (x = 50))
		while (++x < 150)
			set_pixel(win->surface, x, y, 0x0082C4);
	y = 200;
	while (++y < 250 && (x = 200))
		while (++x < 300)
			set_pixel(win->surface, x, y, 0xEE7F1B);

	t_text text;

	text.x = 75;
	text.y = 200;
	text.margin = 0;
	text.color = 0xFFFFFF;
	text.text = ft_strdup("Yes");
	text.font = TTF_OpenFont("./libui/TTF/OpenSans.ttf", 32);
	text.parent = win->surface;
	ft_create_text(&text);
	free(text.text);
	text.x = 225;
	text.text = ft_strdup("NO");
	ft_create_text(&text);
	free(text.text);
	text.x = 50;
	text.y = 100;
	text.color = 0x000000;
	//TTF_CloseFont(text.font);
	text.margin = 50;
	text.text = ft_strdup(msg);
	ft_create_text(&text);
	free(text.text);
	//TTF_CloseFont(text.font);


	SDL_UpdateWindowSurface(win->win);
	int is_running = 2;
	while (is_running == 2)
	{
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_MOUSEBUTTONDOWN)
			{
				if (BX >= 50 && BY >= 200 && BX <= 200 && BY <= 450)
					is_running = 1;
				if (BX >= 200 && BY >= 200 && BX <= 500 && BY <= 450)
					is_running = 0;
			}
		}
	}
	SDL_DestroyWindow(win->win);
	return (is_running);
}
