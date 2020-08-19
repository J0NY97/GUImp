/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 15:19:53 by jsalmi            #+#    #+#             */
/*   Updated: 2020/08/19 19:48:36 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guimp.h"

void	render_window(t_window *win)
{
	SDL_Rect	temp;
	for (int i = 0; i <= win->button_amount; i++)
	{
		temp.x = win->buttons[i]->x;
		temp.y = win->buttons[i]->y;
		temp.w = win->buttons[i]->w;
		temp.h = win->buttons[i]->h;
		SDL_BlitSurface(win->buttons[i]->surface, NULL, win->surface, &temp);
	}
	SDL_UpdateWindowSurface(win->win);
}

void	click(SDL_Event event, t_element *elem)
{
	printf("element_clicked\n");
}

void	draw(SDL_Event event, t_element *elem)
{
	t_brush *brush;

	brush = (t_brush *)elem->info;
	if (event.type == SDL_MOUSEBUTTONUP)
		brush->draw = 0;
	else if (event.type == SDL_MOUSEBUTTONDOWN)
		brush->draw = 1;
	if (brush->draw == 1)
		set_pixel(elem->surface, event.button.x - elem->x, event.button.y - elem->y, 0xff0000);
}

int		main(void)
{
	t_libui	*libui;
	t_info	*info;
	if (!(libui = (t_libui *)malloc(sizeof(t_libui))))
		exit(0);
	if (!(info = (t_info *)malloc(sizeof(t_info))))
		exit(0);
	// INIT
	SDL_Init(SDL_INIT_VIDEO);
	TTF_Init();
	info->run = 1;
	info->font = TTF_OpenFont("font.ttf", 32);
	info->brush.draw = 0;
	// END INIT
	t_window_info test;

	test.x = 0;
	test.y = 0;
	test.w = 500;
	test.h = 1250;
	test.flags = 0;
	test.resizeable = 1;
	test.title = ft_strdup("title");
	if (!(info->toolbox = ft_create_window(test)))
		exit (0);
	test.x = 501;
	test.y = 0;
	test.w = 1000;
	test.h = 1250;
	test.flags = 0;
	test.resizeable = 1;
	test.title = ft_strdup("Xd");
	if (!(info->main = ft_create_window(test)))
		exit (0);
	
	t_element_info s;
	t_element_info b;
	
	b.x = 0;
	b.y = 0;
	b.w = 100;
	b.h = 100;
	b.parent = info->toolbox;
	b.f = &click;
	b.event_handler = &ft_mouse_button_handler;
	b.bg_color = 0xffffff;
	b.info = NULL;
	b.text_info.x = 0;
	b.text_info.y = 0;
	b.text_info.text = ft_strdup("test");
	b.text_info.color = 0x000000;
	b.text_info.font = info->font;
	info->toolbox->buttons[0] = ft_create_element(b);
	info->toolbox->button_amount += 1;

	s.x = 50;
	s.y = 50;
	s.w = info->main->surface->w - s.x;
	s.h = info->main->surface->h - s.y;
	s.parent = info->main;
	s.f = &draw;
	s.event_handler = &ft_mouse_button_handler;
	s.bg_color = 0xffffff;
	s.info = &info->brush;
	s.text_info.x = 0;
	s.text_info.y = 0;
	s.text_info.text = ft_strdup("test");
	s.text_info.color = 0x000000;
	s.text_info.font = info->font;
	info->main->buttons[0] = ft_create_element(s);
	info->main->button_amount += 1;

	while (info->run)
	{
		// EVENT HANDLING
		ft_event_poller(libui);
		if (libui->event.type == SDL_MOUSEBUTTONDOWN ||
			libui->event.type == SDL_MOUSEMOTION ||
			libui->event.type == SDL_MOUSEBUTTONUP)

		{
			info->toolbox->buttons[0]->event_handler(libui, info->toolbox->buttons[0]);
			info->main->buttons[0]->event_handler(libui, info->main->buttons[0]);
		}
		// RENDERING
		render_window(info->toolbox);
		render_window(info->main);
	}
}
