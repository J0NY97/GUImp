/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 10:56:54 by jsalmi            #+#    #+#             */
/*   Updated: 2020/09/02 16:42:09 by jsalmi           ###   ########.fr       */
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
	t_xywh coord;

	coord = ui_init_coords(75, 50, 100, 50);
	info->buttons[0] = ui_create_button(info->toolbox->window, coord);
	info->buttons[0]->text.text = ft_strdup("circle");
	info->buttons[0]->f = &draw_buttons;
	info->buttons[0]->extra_info = info->buttons;
	info->buttons[0]->default_state = 1;

	coord = ui_init_coords(200, 50, 100, 50);
	info->buttons[1] = ui_create_button(info->toolbox->window, coord);
	info->buttons[1]->text.text = ft_strdup("text");
	info->buttons[1]->f = &draw_buttons;
	info->buttons[1]->extra_info = info->buttons;

	coord = ui_init_coords(75, 125, 100, 50);
	info->buttons[2] = ui_create_button(info->toolbox->window, coord);
	info->buttons[2]->text.text = ft_strdup("delete");
	info->buttons[2]->f = &draw_buttons;
	info->buttons[2]->extra_info = info->buttons;

	coord = ui_init_coords(200, 125, 100, 50);
	info->buttons[3] = ui_create_button(info->toolbox->window, coord);
	info->buttons[3]->text.text = ft_strdup("flood");
	info->buttons[3]->f = &draw_buttons;
	info->buttons[3]->extra_info = info->buttons;

	// for now you have to manually update the buttons after change, pl0x fix
	info->buttons[0]->old_state = 500;
	ft_update_element(info->buttons[0]);
	info->buttons[1]->old_state = 500;
	ft_update_element(info->buttons[1]);
	info->buttons[2]->old_state = 500;
	ft_update_element(info->buttons[2]);
	info->buttons[3]->old_state = 500;
	ft_update_element(info->buttons[3]);
}

void	layer_init(t_info *info)
{
	t_xywh	coord;

	coord = ui_init_coords(50, 50,
			info->main->window->surface->w - (100),
			info->main->window->surface->h - (100));
	info->drawing_surface[0] = ui_create_surface(info->main->window, coord);
	info->drawing_surface[0]->f = &draw;
	info->drawing_surface[0]->statique = 1;
	info->drawing_surface[0]->extra_info = &info->brush;

	// brush color surface
	coord = ui_init_coords(325, 350, 100, 100);
	info->brush_color = ui_create_surface(info->toolbox->window, coord);
	info->brush_color->f = NULL; // not needed but it will spam the terminal otherwise
}

void	slider_init(t_info *info)
{
	t_xywh	coord;

	coord = ui_init_coords(100, 350, 200, 20);
	info->r_slider = ui_create_slider(info->toolbox->window, coord, 0, 255);
	((t_slider *)info->r_slider->info)->bar_color = 0xff0000;

	coord = ui_init_coords(100, 375, 200, 20);
	info->g_slider = ui_create_slider(info->toolbox->window, coord, 0, 255);
	((t_slider *)info->g_slider->info)->bar_color = 0x00ff00;

	coord = ui_init_coords(100, 400, 200, 20);
	info->b_slider = ui_create_slider(info->toolbox->window, coord, 0, 255);
	((t_slider *)info->b_slider->info)->bar_color = 0x0000ff;

	coord = ui_init_coords(100, 425, 200, 20);
	info->size_slider = ui_create_slider(info->toolbox->window, coord, 1, 100);
	((t_slider *)info->size_slider->info)->value = 10;

 	int t = ((float)info->r_slider->coord.w / (((t_slider *)info->r_slider->info)->max - ((t_slider *)info->r_slider->info)->min)) *
			((t_slider *)info->r_slider->info)->value;
	ft_update_slider_bar(t + info->r_slider->coord.x, 0, info->r_slider);

	t = ((float)info->g_slider->coord.w / (((t_slider *)info->g_slider->info)->max - ((t_slider *)info->g_slider->info)->min)) *
			((t_slider *)info->g_slider->info)->value;
	ft_update_slider_bar(t + info->g_slider->coord.x, 0, info->g_slider);

	t = ((float)info->b_slider->coord.w / (((t_slider *)info->b_slider->info)->max - ((t_slider *)info->b_slider->info)->min)) *
			((t_slider *)info->b_slider->info)->value;
	ft_update_slider_bar(t + info->b_slider->coord.x, 0, info->b_slider);

	t = ((float)info->size_slider->coord.w / (((t_slider *)info->size_slider->info)->max - ((t_slider *)info->size_slider->info)->min)) *
			((t_slider *)info->size_slider->info)->value;
	ft_update_slider_bar(t + info->size_slider->coord.x, 0, info->size_slider);
}

void	window_init(t_libui *libui, t_info *info)
{
	t_window_info new_win;

	if (!(info->toolbox = (t_win *)malloc(sizeof(t_win))))
		exit (0);
	if (!(info->main = (t_win *)malloc(sizeof(t_win))))
		exit (0);

	new_win.coord = ui_init_coords(0, 0, 500, 1250);
	new_win.title = ft_strdup("toolbox");
	info->toolbox->window = ft_create_window(libui, new_win);
	
	new_win.coord = ui_init_coords(501, 0, 1000, 1250);
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

void	key_press(SDL_Event e, t_hotkey *hotkey)
{
	printf("priss prass pross %s\n", SDL_GetKeyName(hotkey->key));
}

void	hotkey_init(t_info *info, t_libui *libui)
{
	ft_add_hotkey(libui, SDLK_a, &key_press);
	ft_add_hotkey(libui, SDLK_b, &key_press);
	ft_add_hotkey(libui, SDLK_c, &key_press);
	ft_add_hotkey(libui, SDLK_d, &key_press);
}

void	update_brush(t_info *info)
{
	info->brush.color = rgb_to_hex(((t_slider *)info->r_slider->info)->value,
									((t_slider *)info->g_slider->info)->value,
									((t_slider *)info->b_slider->info)->value);
	info->brush.size = ((t_slider *)info->size_slider->info)->value;	
	ft_update_background(info->brush_color->surface, info->brush.color);
}

void	check_for_drag_droppings(char *file, t_info *info)
{
	SDL_Surface *new_image;
	if (file)
	{
		if ((new_image = load_image(file)))
		{
			SDL_BlitSurface(new_image, NULL, info->drawing_surface[0]->surface, NULL);
		}
		SDL_FreeSurface(new_image);
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
	slider_init(info);
//	drop_down_init();
	layer_init(info); // slider_init needs to be called before this.
	hotkey_init(info, libui);
	while (info->run)
	{
		ft_event_poller(libui); // input
		check_for_drag_droppings(drag_and_drop(libui->event), info);
		update_brush(info);
		ui_render(info->toolbox->window);
		ui_render(info->main->window);
	}
	// cleanup()
	return (0);
}
