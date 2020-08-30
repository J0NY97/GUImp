/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 10:56:54 by jsalmi            #+#    #+#             */
/*   Updated: 2020/08/30 17:54:30 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guimp.h"

void	draw_buttons(SDL_Event e, t_element *elem)
{
	t_element **buttons;

	if (e.type == SDL_MOUSEBUTTONDOWN)
	{
		buttons = (t_element **)elem->extra_info;
		// the 4 is the amount of buttons in the array, if you add more you have to add more
		for (int i = 0; i < 4; i++)
			buttons[i]->default_state = 0;
		elem->default_state = 1;
	}
	if (e.type == SDL_MOUSEMOTION)
		elem->state = 2;
	else if (e.type == SDL_MOUSEBUTTONUP)
		elem->state = 2;
}

void	button_init(t_info *info)
{
	info->buttons[0] = ui_create_button(info->toolbox->window, 75, 50);
	info->buttons[0]->text.text = ft_strdup("circle");
	info->buttons[0]->default_state = 1;
	info->buttons[0]->f = &draw_buttons;
	info->buttons[0]->extra_info = info->buttons;

	info->buttons[1] = ui_create_button(info->toolbox->window, 200, 50);
	info->buttons[1]->text.text = ft_strdup("text");
	info->buttons[1]->f = &draw_buttons;
	info->buttons[1]->extra_info = info->buttons;

	info->buttons[2] = ui_create_button(info->toolbox->window, 75, 125);
	info->buttons[2]->text.text = ft_strdup("delete");
	info->buttons[2]->f = &draw_buttons;
	info->buttons[2]->extra_info = info->buttons;

	info->buttons[3] = ui_create_button(info->toolbox->window, 200, 125);
	info->buttons[3]->text.text = ft_strdup("flood");
	info->buttons[3]->f = &draw_buttons;
	info->buttons[3]->extra_info = info->buttons;
}

void	layer_init(t_info *info)
{
	info->drawing_surface[0] = ui_create_surface(info->main->window, 50, 50);
	info->drawing_surface[0]->w = info->main->window->surface->w - (info->drawing_surface[0]->x * 2);
	info->drawing_surface[0]->h = info->main->window->surface->h - (info->drawing_surface[0]->y * 2);
	info->drawing_surface[0]->f = &draw;
	info->drawing_surface[0]->extra_info = &info->brush;
}

void	window_init(t_libui *libui, t_info *info)
{
	t_window_info new_win;

	if (!(info->toolbox = (t_win *)malloc(sizeof(t_win))))
		exit (0);
	if (!(info->main = (t_win *)malloc(sizeof(t_win))))
		exit (0);
	
	/*new_win.x = 0;
	new_win.y = 0;
	new_win.w = 500;
	new_win.h = 1250;*/
	new_win->cords.x = 0;
	new_win->cords.y = 0;
	new_win->cords.w = 500;
	new_win->cords.h = 1250;
	new_win.title = ft_strdup("toolbox");
	info->toolbox->window = ft_create_window(libui, new_win);

	/*new_win.x = 501;
	new_win.y = 0;
	new_win.w = 1000;
	new_win.h = 1250;*/
	new_win->cords.x = 501;
	new_win->cords.y = 0;
	new_win->cords.w = 1000;
	new_win->cords.h = 1250;
	new_win.title = ft_strdup("main");
	info->main->window = ft_create_window(libui, new_win);
}

void	guimp_init(t_info *info)
{
	info->run = 1;
	// brush init
	{
		info->brush.font_dir = ft_strdup("font.ttf");
		info->brush.draw = 0;
		info->brush.type = 1;
		info->brush.size = 20;
		info->brush.color = 0xd3d3d3;
		info->brush.old_x = -1;
		info->brush.old_y = -1;
	}
}

int		main(void)
{
	t_libui *libui;
	t_info *info;

	if (!(libui = (t_libui *)malloc(sizeof(t_libui))))
		exit (0);
	if (!(info = (t_info *)malloc(sizeof(t_info))))
		exit (0);
	SDL_Init(SDL_INIT_VIDEO);
	TTF_Init();
	IMG_Init(0);
	ui_libui_init(libui);
	guimp_init(info);

	window_init(libui, info);
	button_init(info);
//	slider_init();
//	drop_down_init();
	layer_init(info);
	while (info->run)
	{
		ft_event_poller(libui); // input
		ui_render(info->toolbox->window);
		ui_render(info->main->window);
	}
	return (0);
}
