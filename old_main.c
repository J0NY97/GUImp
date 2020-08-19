/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 12:48:16 by jsalmi            #+#    #+#             */
/*   Updated: 2020/08/19 14:45:39 by jsalmi           ###   ########.fr       */
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
	for (int i = 0; i <= win->button_amount; i++)
	{
		temp.x = win->buttons[i]->x;
		temp.y = win->buttons[i]->y;
		temp.w = win->buttons[i]->surface->w;
		temp.h = win->buttons[i]->surface->h;
		SDL_BlitSurface(win->buttons[i]->surface, NULL, win->surface, &temp);
	}
	for (int i = 0; i <= win->surface_amount; i++)
	{
		temp.x = win->surfaces[i]->x;
		temp.y = win->surfaces[i]->y;
		temp.w = win->surfaces[i]->surface->w;
		temp.h = win->surfaces[i]->surface->h;
		SDL_BlitSurface(win->surfaces[i]->surface, NULL, win->surface, &temp);
	}
	for (int i = 0; i <= win->slider_amount; i++)
	{
		temp.x = win->sliders[i]->x;
		temp.y = win->sliders[i]->y;
		temp.w = win->sliders[i]->surface->w;
		temp.h = win->sliders[i]->surface->h;
		SDL_BlitSurface(win->sliders[i]->surface, NULL, win->surface, &temp);
	}
	// add elemsnets to surafce
	// otherthings....
	SDL_UpdateWindowSurface(win->win);
}

// @Improvement: updatese all the buttons independent if the button was actually updated
// @fix: now only checks toolbox window buttons
void	update_buttons(t_window *win)
{
	int ib;

	ib = -1;
	while (++ib <= win->button_amount)
	{
		if (win->buttons[ib]->state == 0)
			ft_update_button(win->buttons[ib], 0xffffff, 0x00ff00);
		else if (win->buttons[ib]->state == 1)
			ft_update_button(win->buttons[ib], 0xff00ff, 0x000000);
		else if (win->buttons[ib]->state == 2)
			ft_update_button(win->buttons[ib], 0xffff00, 0x000000);
	}
}

t_info	*get_info(t_button *button)
{
	return ((t_info *)button->info);
}

void	click(t_button *button)
{
	printf("click\n");
}

void	brush_circle(t_button *button)
{
	get_info(button)->brush.type = 1;
}
void	brush_deletion(t_button *button)
{
	get_info(button)->brush.type = 0;
}
void	brush_square(t_button *button)
{
	get_info(button)->brush.type = 2;
}
void	update_brush_color(t_info *info, t_slider *r, t_slider *g, t_slider *b)
{
	info->brush.color = (r->current & 0xFF) << 16 | (g->current & 0xFF) << 8 | (b->current & 0xFF);
}
void	update_brush_size(t_info *info, t_slider *size)
{
	printf("Current %d\n", size->current);
	info->brush.size = size->current;
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
	info->brush.type = 1;
	info->brush.size = 10;
	info->brush.color = 0x000000;
	info->brush.old_x = -1;
	info->brush.old_y = -1;
	info->draw = 0;
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
	button.info = info;

	button.x = 0;
	button.y = 9;
	button.w = 100;
	button.h = 50;
	button.text = ft_strdup("click me!");
	button.font = info->font;
	button.win = info->toolbox;
	button.f = &click;
	button.state = 0;
	button.group = 0;
	button.toggle = -1;
	ft_create_button(button);

	button.x = 125;
	button.y = 9;
	button.text = ft_strdup("me too!");
	button.toggle = -1;
	button.group = 1;
	ft_create_button(button);
	
	button.x = 50;
	button.y = 100;
	button.w = 200;
	button.h = 100;
	button.toggle = 1;
	button.group = 2;
	button.f = &brush_deletion;
	button.text = ft_strdup("deletion! g2");
	ft_create_button(button);

	button.x = 275;
	button.y = 100;
	button.toggle = 0;
	button.group = 2;
	button.f = &brush_circle;
	button.text = ft_strdup("circle! g2");
	ft_create_button(button);
	
	button.x = 50;
	button.y = 225;
	button.toggle = 0;
	button.group = 2;
	button.f = &brush_square;
	button.text = ft_strdup("square! g2");
	ft_create_button(button);


	// slider on toolbox win
	t_slider_info	slider;
	slider.x = 200;
	slider.w = 200;
	slider.y = 500;
	slider.h = 10;
	slider.min = 0;
	slider.max = 255;
	slider.current = 255;
	slider.slider_color = 0xff0000;
	slider.bar_color = 0xd3d3d3;
	slider.win = info->toolbox;
	ft_create_slider(slider); // this adds it to the window's sliders array
	SDL_Surface	*temp_text = TTF_RenderText_Blended(info->font, ft_itoa(slider.min), hex_to_rgba(0x00686518));
	SDL_Rect temp;
	temp.x = slider.x;
	temp.y = slider.y - 40;
	temp.w = 0;
	temp.h = 0;
	SDL_BlitSurface(temp_text, NULL, info->toolbox->surface, &temp);
	temp_text = TTF_RenderText_Blended(info->font, ft_itoa(slider.max), hex_to_rgba(0x00686518));
	temp.x = slider.x + slider.w - (temp_text->w);
	temp.y = slider.y - 40;
	SDL_BlitSurface(temp_text, NULL, info->toolbox->surface, &temp);

	slider.slider_color = 0x00ff00;
	slider.current = 0;
	slider.y = 600;
	ft_create_slider(slider);
	temp_text = TTF_RenderText_Blended(info->font, ft_itoa(slider.min), hex_to_rgba(0x00686518));
	temp.x = slider.x;
	temp.y = slider.y - 40;
	SDL_BlitSurface(temp_text, NULL, info->toolbox->surface, &temp);
	temp_text = TTF_RenderText_Blended(info->font, ft_itoa(slider.max), hex_to_rgba(0x00686518));
	temp.x = slider.x + slider.w - (temp_text->w);
	temp.y = slider.y - 40;
	SDL_BlitSurface(temp_text, NULL, info->toolbox->surface, &temp);

	slider.slider_color = 0x0000ff;
	slider.current = 0;
	slider.y = 700;
	ft_create_slider(slider);
	temp_text = TTF_RenderText_Blended(info->font, ft_itoa(slider.min), hex_to_rgba(0x00686518));
	temp.x = slider.x;
	temp.y = slider.y - 40;
	SDL_BlitSurface(temp_text, NULL, info->toolbox->surface, &temp);
	temp_text = TTF_RenderText_Blended(info->font, ft_itoa(slider.max), hex_to_rgba(0x00686518));
	temp.x = slider.x + slider.w - (temp_text->w);
	temp.y = slider.y - 40;
	SDL_BlitSurface(temp_text, NULL, info->toolbox->surface, &temp);

	// brush size slider
	slider.slider_color = 0xffffff;
	slider.min = 1;
	slider.max = 10;
	slider.current = 1;
	slider.x = 200;
	slider.y = 425;
	ft_create_slider(slider);
	//		text stuff
	temp_text = TTF_RenderText_Blended(info->font, ft_itoa(slider.min), hex_to_rgba(0x00686518));
	temp.x = slider.x;
	temp.y = slider.y - 40;
	SDL_BlitSurface(temp_text, NULL, info->toolbox->surface, &temp);
	temp_text = TTF_RenderText_Blended(info->font, ft_itoa(slider.max), hex_to_rgba(0x00686518));
	temp.x = slider.x + slider.w - (temp_text->w);
	temp.y = slider.y - 40;
	SDL_BlitSurface(temp_text, NULL, info->toolbox->surface, &temp);
/////////////
	t_window_info main;
	main.x = 501;
	main.y = 0;
	main.w = 1000;
	main.h = 1250;
	main.flags = 0;
	main.resizeable = 1;
	main.title = ft_strdup("Xd");
	info->main = ft_create_window(main);
	
	// the main surface you draw oin
	t_surface_info ns;
	ns.x = 50;
	ns.y = 50;
	ns.w = info->main->surface->w - ns.x - 50;
	ns.h = info->main->surface->h - ns.y - 50;
	ns.win = info->main;
	ft_create_surface(ns);


	ns.x = 250;
	ns.y = 750;
	ns.w = 100;
	ns.h = 100;
	ns.color = info->brush.color;
	ns.win = info->toolbox;
	ft_create_surface(ns);

	t_line l;

	l.x1 = 0;
	l.y1 = 0;
	l.x2 = 200;
	l.y2 = 400;
	ft_create_line(info->main->surfaces[0]->surface, 0xff00f0, &l);

	while (info->run)
	{
	   	// @Improvement: move this to where it will be called everytime the color sliders update 
		update_brush_color(info, info->toolbox->sliders[0], info->toolbox->sliders[1], info->toolbox->sliders[2]);
		update_brush_size(info, info->toolbox->sliders[3]);
		ft_update_background(info->toolbox->surfaces[0]->surface, info->brush.color); // brush color shower
		///////
		event_handler(info);
		update_buttons(info->toolbox);
		update_buttons(info->main);
		render(info->toolbox);
		render(info->main);
	}
	return (0);
}
