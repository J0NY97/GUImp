/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 15:19:53 by jsalmi            #+#    #+#             */
/*   Updated: 2020/08/20 19:22:33 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guimp.h"

void	render_element(t_element *elem)
{	
	SDL_Rect	temp;
		
	temp.x = elem->x;
	temp.y = elem->y;
	temp.w = elem->w;
	temp.h = elem->h;
	SDL_BlitSurface(elem->surface, NULL, elem->parent, &temp);
}

void	render_window(t_win *win)
{
	t_list		*curr;

	curr = win->elements;
	while (curr != NULL)
	{
		render_element(curr->content);
		curr = curr->next;
	}
	SDL_UpdateWindowSurface(win->window->win);
}

void	click(SDL_Event event, t_element *elem)
{
	if (event.type == SDL_MOUSEBUTTONDOWN)
		printf("element_clicked\n");
}

void	add_elem_to_list(t_win *win, t_element_info info)
{
	t_list *lst;

	lst = ft_lstnew(0, 0);
	lst->content = ft_create_element(info);
	lst->content_size = win->elem_amount;
	if (win->elements)
		ft_lstadd(&win->elements, lst);
	else
		win->elements = lst;
	win->elem_amount += 1;
}

void	call_own_function(t_libui *libui, t_element *element)
{
	element->event_handler(libui, element);
}

void	call_all_handlers(t_win *win, t_libui *libui)
{
	t_list *curr;

	curr = win->elements;
	while (curr != NULL)
	{
		call_own_function(libui, curr->content);
		curr = curr->next;
	}
}

void	slider_event(SDL_Event e, t_element *elem)
{
	SDL_Surface *bar;
	SDL_Rect	temp;
	t_new_slider *slider;
	float		ppv;
	int x;
	int y;
	
	slider = (t_new_slider *)elem->info;
	if (e.type == SDL_MOUSEBUTTONUP)
		slider->clicked = 0;
	if (e.type == SDL_MOUSEBUTTONDOWN)
		slider->clicked = 1;
	if (slider->clicked == 1)
	{
		x = e.button.x - elem->x;
		y = e.button.y - elem->y;
		bar = SDL_CreateRGBSurface(0, 10, elem->h, 32, 0, 0, 0, 0);
		ft_update_background(elem->surface, elem->bg_color);
		ft_update_background(bar, slider->color);
		ppv = (slider->max - slider->min) / (float)elem->w;
		temp.x = x - (bar->w / 2);
		temp.y = 0;
		temp.w = bar->w;
		temp.h = bar->h;
		SDL_BlitSurface(bar, NULL, elem->surface, &temp);
		slider->value = (float)ppv * x;
	}
		set_pixel(elem->surface, x, y, 0xff0000);
}

void	get_brush_color(t_info *info)
{
	info->brush.color = (((t_new_slider *)(info->r_slider->info))->value & 0xFF) << 16 |
						(((t_new_slider *)(info->g_slider->info))->value & 0xFF) << 8 |
						(((t_new_slider *)(info->b_slider->info))->value & 0xFF);
}

void	change_brush_type(t_libui *libui, t_element **elems, t_element *elem)
{
	t_brush_button *button;
	SDL_Event e;
	
	e = libui->event;
	button = (t_brush_button *)elem->info;
	if (e.button.x >= elem->x && e.button.y >= elem->y &&
		e.button.x <= elem->x + elem->w && e.button.y <= elem->y + elem->h)
	{
		if (e.type == SDL_MOUSEBUTTONDOWN)
		{
			if (button->state == 0)
			{
				for (int i = 0; i < 3; i++)
				{
					if (((t_brush_button *)elems[i]->info)->state == 1)
					{
						((t_brush_button *)elems[i]->info)->state = 0;
						ft_update_background(elems[i]->surface, elems[i]->bg_color);
					}
				}
				button->state = 1;
				button->brush->type = button->type;
				ft_update_background(elem->surface, elem->bg_color & 0xff);
			}
		}
	}
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
	info->brush.size = 20;
	info->brush.old_x = -1;
	info->brush.old_y = -1;
	if (!(info->toolbox = (t_win *)malloc(sizeof(t_win))))
		exit (0);
	if (!(info->main = (t_win *)malloc(sizeof(t_win))))
		exit (0);
	// END INIT
	t_window_info test;
////////////
	test.x = 0;
	test.y = 0;
	test.w = 500;
	test.h = 1250;
	test.flags = 0;
	test.resizeable = 1;
	test.title = ft_strdup("title");
	if (!(info->toolbox->window = ft_create_window(test)))
		exit (0);
	info->toolbox->elements = NULL;
	info->toolbox->elem_amount = -1;

	test.x = 501;
	test.y = 0;
	test.w = 1000;
	test.h = 1250;
	test.flags = 0;
	test.resizeable = 1;
	test.title = ft_strdup("Xd");
	if (!(info->main->window = ft_create_window(test)))
		exit (0);
	info->main->elements= NULL;
	info->main->elem_amount = -1;
/////////////
	t_element_info	b;
	t_brush_button	*binfo;

	if (!(binfo = (t_brush_button *)malloc(sizeof(t_brush_button))))
		exit (0);
	b.x = 50;
	b.y = 50;
	b.w = 100;
	b.h = 50;
	b.parent = info->toolbox->window->surface;
	b.f = &click;
	b.event_handler = &ft_mouse_button_handler;
	b.bg_color = 0xffffff;
	binfo->state = 1;
	binfo->type = 1;
	binfo->update = 1;
	binfo->brush = &info->brush;
	b.info = binfo;
	b.text_info.set_text = 1;
	b.text_info.x = 0;
	b.text_info.y = 0;
	b.text_info.text = ft_strdup("circle");
	b.text_info.color = 0x000000;
	b.text_info.font = info->font;
	add_elem_to_list(info->toolbox, b);
	info->buttons[0] = info->toolbox->elements->content;	

	t_brush_button	*binfo_too;

	if (!(binfo_too = (t_brush_button *)malloc(sizeof(t_brush_button))))
		exit (0);
	b.x = 160;
	b.y = 50;
	b.w = 100;
	b.h = 50;
	b.parent = info->toolbox->window->surface;
	b.f = &click;
	b.event_handler = &ft_mouse_button_handler;
	b.bg_color = 0xffffff;
	binfo_too->state = 0;
	binfo_too->type = 2;
	binfo_too->update = 1;
	binfo_too->brush = &info->brush;
	b.info = binfo_too;
	b.text_info.set_text = 1;
	b.text_info.x = 0;
	b.text_info.y = 0;
	b.text_info.text = ft_strdup("squaer");
	b.text_info.color = 0x000000;
	b.text_info.font = info->font;
	add_elem_to_list(info->toolbox, b);
	info->buttons[1] = info->toolbox->elements->content;

	t_brush_button	*binfo_three;

	if (!(binfo_three = (t_brush_button *)malloc(sizeof(t_brush_button))))
		exit (0);
	b.x = 50;
	b.y = 110;
	b.w = 100;
	b.h = 50;
	b.parent = info->toolbox->window->surface;
	b.f = &click;
	b.event_handler = &ft_mouse_button_handler;
	b.bg_color = 0xffffff;
	binfo_three->state = 0;
	binfo_three->type = 2;
	binfo_three->update = 1;
	binfo_three->brush = &info->brush;
	b.info = binfo_three;
	b.text_info.set_text = 1;
	b.text_info.x = 0;
	b.text_info.y = 0;
	b.text_info.text = ft_strdup("deletion");
	b.text_info.color = 0x000000;
	b.text_info.font = info->font;
	add_elem_to_list(info->toolbox, b);
	info->buttons[2] = info->toolbox->elements->content;
///////////////
	t_element_info s;
	s.x = 50;
	s.y = 50;
	s.w = info->main->window->surface->w - (s.x * 2);
	s.h = info->main->window->surface->h - (s.y * 2);
	s.parent = info->main->window->surface;
	s.f = &draw;
	s.event_handler = &ft_mouse_button_handler;
	s.bg_color = 0xffffff;
	s.info = &info->brush;
	s.text_info.set_text = 0;
	s.text_info.x = 0;
	s.text_info.y = 0;
	s.text_info.text = ft_strdup("test");
	s.text_info.color = 0x000000;
	s.text_info.font = info->font;
	add_elem_to_list(info->main, s);
///////////
//SLIDER
	t_element_info sinf;
	t_new_slider	*slinfo;
	if (!(slinfo = (t_new_slider *)malloc(sizeof(t_new_slider))))
		exit (0);
	sinf.x = 100;
	sinf.y = 200;
	sinf.w = 200;
	sinf.h = 20;
	sinf.bg_color = 0xffffff;
	sinf.parent = info->toolbox->window->surface;
	slinfo->min = 0;
	slinfo->max = 255;
	slinfo->value = 100;
	slinfo->clicked = 0;
	slinfo->color = 0x00ff0000;
	sinf.info = slinfo;
	sinf.f = &slider_event;
	sinf.event_handler = &ft_mouse_button_handler;
	sinf.text_info.set_text = 0;
	add_elem_to_list(info->toolbox, sinf);
	slider_event(libui->event, info->toolbox->elements->content);
	info->r_slider = info->toolbox->elements->content;

	t_new_slider	*slinfo_too;
	if (!(slinfo_too = (t_new_slider *)malloc(sizeof(t_new_slider))))
		exit (0);
	sinf.x = 100;
	sinf.y = 250;
	sinf.w = 200;
	sinf.h = 20;
	sinf.bg_color = 0xffffff;
	sinf.parent = info->toolbox->window->surface;
	sinf.info = slinfo_too;
	slinfo_too->min = 0;
	slinfo_too->max = 255;
	slinfo_too->value = 100;
	slinfo_too->clicked = 0;
	slinfo_too->color = 0x00ff00;
	sinf.f = &slider_event;
	sinf.event_handler = &ft_mouse_button_handler;
	sinf.text_info.set_text = 0;
	add_elem_to_list(info->toolbox, sinf);
	slider_event(libui->event, info->toolbox->elements->content);
	info->g_slider = info->toolbox->elements->content;

	t_new_slider	*slinfo_three;
	if (!(slinfo_three = (t_new_slider *)malloc(sizeof(t_new_slider))))
		exit (0);
	sinf.x = 100;
	sinf.y = 300;
	sinf.w = 200;
	sinf.h = 20;
	sinf.bg_color = 0xffffff;
	sinf.parent = info->toolbox->window->surface;
	sinf.info = slinfo_three;
	slinfo_three->min = 0;
	slinfo_three->max = 255;
	slinfo_three->value = 100;
	slinfo_three->clicked = 0;
	slinfo_three->color = 0x0000ff;
	sinf.f = &slider_event;
	sinf.event_handler = &ft_mouse_button_handler;
	sinf.text_info.set_text = 0;
	add_elem_to_list(info->toolbox, sinf);
	slider_event(libui->event, info->toolbox->elements->content);
	info->b_slider = info->toolbox->elements->content;

	t_new_slider	*zinfo;
	if (!(zinfo = (t_new_slider *)malloc(sizeof(t_new_slider))))
		exit (0);
	sinf.x = 100;
	sinf.y = 350;
	sinf.w = 200;
	sinf.h = 20;
	sinf.bg_color = 0xffffff;
	sinf.parent = info->toolbox->window->surface;
	sinf.info = zinfo;
	zinfo->min = 1;
	zinfo->max = 100;
	zinfo->value = 2;
	zinfo->clicked = 0;
	zinfo->color = 0xd3d3d3;
	sinf.f = &slider_event;
	sinf.event_handler = &ft_mouse_button_handler;
	sinf.text_info.set_text = 0;
	add_elem_to_list(info->toolbox, sinf);
	slider_event(libui->event, info->toolbox->elements->content);
	info->size_slider = info->toolbox->elements->content;
//////////
	while (info->run)
	{
		// EVENT HANDLING
		ft_event_poller(libui);
		if (libui->event.type == SDL_MOUSEBUTTONDOWN ||
			libui->event.type == SDL_MOUSEMOTION ||
			libui->event.type == SDL_MOUSEBUTTONUP)

		{
			if (libui->event.window.windowID == info->toolbox->window->id){
				call_all_handlers(info->toolbox, libui);
			for (int i = 0; i < 3; i++)
			{
				change_brush_type(libui, info->buttons, info->buttons[i]);
			}}
			else if (libui->event.window.windowID == info->main->window->id)
				call_all_handlers(info->main, libui);
		}
		info->brush.color = rgb_to_hex(((t_new_slider *)info->r_slider->info)->value,
										((t_new_slider *)info->g_slider->info)->value,
										((t_new_slider *)info->b_slider->info)->value);
		
		info->brush.size = ((t_new_slider *)info->size_slider->info)->value;
		// RENDERING
		render_window(info->toolbox);
		render_window(info->main);
	}
}
