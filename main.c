/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 12:48:16 by jsalmi            #+#    #+#             */
/*   Updated: 2020/08/14 15:57:38 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guimp.h"

void	ft_error(char *msg)
{
	ft_putstr("\x1b[31m[Error] \x1b[0m");
	ft_putstr(msg);
	ft_putstr("\n");
	exit(1);
}

void	render(t_window *win)
{
	SDL_Rect	temp;
	// add buttons to  sruface
//	printf("%d %d %d %d", win->buttons[0]->x, win->buttons[0]->y, win->buttons[0]->surface->w, win->buttons[0]->surface->h);
	set_pixel(win->buttons[0]->surface, 10, 10, 0xffffff);
	set_pixel(win->surface, 250, 500, 0xffffff);
	for (int i = 0; i <= win->button_amount; i++)
	{
		temp.x = win->buttons[i]->x;
		temp.y = win->buttons[i]->y;
		temp.w = win->buttons[i]->surface->w;
		temp.h = win->buttons[i]->surface->h;
		SDL_BlitSurface(win->buttons[i]->surface, NULL, win->surface, &temp);
	}
	// add elemsnets to surafce
	// otherthings....
	SDL_UpdateWindowSurface(win->win);
}

int		main(void)
{
	t_info *info;

	ft_test_libui();
	if (!(info = (t_info *)malloc(sizeof(t_info))))
		ft_error("Couldnt mallco t_info.");
	SDL_Init(SDL_INIT_VIDEO);
	TTF_Init();
	// SDL_Image_Init();

	// Init();
	info->run = 1;
	info->font = TTF_OpenFont("font.ttf", 32);
	//
	t_window_info toolbox;
	toolbox.x = 0;
	toolbox.y = 0;
	toolbox.w = 500;
	toolbox.h = 1250;
	toolbox.flags = 0;
	toolbox.resizeable = 1;
	toolbox.title = ft_strdup("toolbox");
	info->toolbox = ft_create_window(toolbox);

	t_button_info button;
	button.x = 0;
	button.y = 9;
	button.w = 100;
	button.h = 50;
	button.text = ft_strdup("click me!");
	button.font = info->font;
	button.win = info->toolbox;
	ft_create_button(button);


//	ft_add_button_to_window(toolbox->win, new_button);

/*
	info->main.x = info->toolbox.x + info->toolbox.w + 5;
	info->main.y = 0;
	info->main.w = 1500;
	info->main.h = 1250;
	info->main.resizeable = 1;
	info->main.win = ft_create_window("main", info->main.x, info->main.y,
										info->main.w, info->main.h, info->main.resizeable);
	info->main.surface = SDL_GetWindowSurface(info->main.win);

	info->layers.x = info->main.x + info->main.w + 5;
	info->layers.y = 0;
	info->layers.w = 500;
	info->layers.h = 1250;
	info->layers.resizeable = 1;
	ft_create_window("layers", info->layers.x, info->layers.y,
										info->layers.w, info->layers.h, info->main.resizeable);
	info->layers.surface = SDL_GetWindowSurface(info->layers.win);
*/
	while (info->run)
	{
		//input
		event_handler(info);
		// This will go into render function
//		SDL_UpdateWindowSurface(info->main.win);
//		SDL_UpdateWindowSurface(info->layers.win);
		render(info->toolbox);
	}
	return (0);
}
