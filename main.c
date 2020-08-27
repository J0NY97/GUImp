/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 15:19:53 by jsalmi            #+#    #+#             */
/*   Updated: 2020/08/27 13:38:50 by nneronin         ###   ########.fr       */
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

void	update_slider(t_element *slider)
{
	SDL_Rect	temp;
	SDL_Surface	*bar;
	t_slider *info;
	float ppv;
	
	info = (t_slider *)slider->info;
	bar = SDL_CreateRGBSurface(0, 10, slider->h, 32, 0, 0, 0, 0);
	ft_update_background(bar, info->bar_color);	
	ppv = (float)slider->w / (info->max - info->min);
	temp.x = info->value * (float)ppv - (bar->w / 2);
	temp.y = 0;
	temp.w = bar->w;
	temp.h = bar->h;
	SDL_BlitSurface(bar, NULL, slider->surface, &temp);
	SDL_FreeSurface(bar);
}

void	slider_event(SDL_Event e, t_element *elem)
{
	SDL_Surface *bar;
	SDL_Rect	temp;
	t_slider *slider;
	float		ppv;
	int x;
	int y;
	
	slider = (t_slider *)elem->info;
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
		ft_update_background(bar, slider->bar_color);
		ppv = (slider->max - slider->min) / (float)elem->w;
		temp.x = x - (bar->w / 2);
		temp.y = 0;
		temp.w = bar->w;
		temp.h = bar->h;
		SDL_BlitSurface(bar, NULL, elem->surface, &temp);
		slider->value = (float)ppv * x;
	}
}

void	get_brush_color(t_info *info)
{
	info->brush.color = (((t_slider *)(info->r_slider->info))->value & 0xFF) << 16 |
						(((t_slider *)(info->g_slider->info))->value & 0xFF) << 8 |
						(((t_slider *)(info->b_slider->info))->value & 0xFF);
}

int		show_brush_color(t_libui *libui, t_element *elem)
{
	t_brush *brush;

	brush = (t_brush *)elem->info;
	elem->bg_color = brush->color;
	ft_update_background(elem->surface, elem->bg_color);
	return (1);
}

void		update_buttons(t_element **buttons)
{
	t_emp		temp;

	temp.i = 0;
	while (temp.i < 4)
	{
		if (((t_button *)buttons[temp.i]->info)->state == 0)
			buttons[temp.i]->bg_color = 0xffffff;
		else if (((t_button *)buttons[temp.i]->info)->state == 1)
			buttons[temp.i]->bg_color = 0x0000ff;
		else if (((t_button *)buttons[temp.i]->info)->state == 2)
			buttons[temp.i]->bg_color = 0x00ff00;
		ft_update_element(buttons[temp.i]);
		temp.i += 1;
	}
}

void	change_brush_type(SDL_Event e, t_element *elem)
{
	t_brush		*brush;
	t_button	*this;
	t_element	**buttons;
	t_element	*other;
	t_button	*that;
	
	this = (t_button *)elem->info;
	brush = (t_brush *)this->extra;
	buttons = (t_element **)elem->extra_info;
	if (e.type == SDL_MOUSEBUTTONDOWN)
	{
		if (this->state == 0)
		{
			for (int i = 0; i < 4; i++)
			{
				other = (t_element *)buttons[i];
				that = (t_button *)other->info;
				that->state = 0;
				ft_update_background(other->surface, other->bg_color);
			}
			this->state = 1;
			brush->type = this->type;
		}
	}
	update_buttons(buttons);
}

t_slider	create_slider_info(int min, int max, int value, int bar_color)
{
	t_slider	slider;

	slider.min = min;
	slider.max = max;
	slider.value = value;
	slider.bar_color = bar_color;
	slider.clicked = 0;
	slider.size = sizeof(t_slider);
	return (slider);
}

t_button	create_button_info(int state, int type, void *extra)
{
	t_button	button;
	
	button.state = state;
	button.type = type;
	button.extra = extra;
	button.size = sizeof(t_button);
	return (button);
}

void	tin_reader(SDL_Event e, t_element *elem)
{
	char *tmp;

	if (e.type == SDL_MOUSEBUTTONDOWN)
		elem->info = (int *)1;
	if (e.type == SDL_MOUSEBUTTONUP && (int)elem->info == 1)
		elem->info = (int *)2;
	if ((int)elem->info == 2)
	{
		elem->info = 0;
		elem->set_text = 1;
		elem->text.text = ft_read_text(20);
		ft_update_element(elem);
	}
}

int		main(int argc, char *argv[])
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
	IMG_Init(0);
	info->run = 1;
	info->font = TTF_OpenFont("font.ttf", 32);
	info->brush.draw = 0;
	info->brush.type = 1;
	info->brush.size = 20;
	info->brush.color = 0xd3d3d3;
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
	info->main->elements = NULL;
	info->main->elem_amount = -1;
/////////////
	t_element_info	b;
	t_button		blin;
//
	blin = create_button_info(1, 1, &info->brush);
	b.info = &blin;
	b.info_size = ((t_button *)b.info)->size;

	b.x = 50;
	b.y = 50;
	b.w = 100;
	b.h = 50;
	b.parent = info->toolbox->window->surface;
	b.f = &change_brush_type;
	b.event_handler = &ft_mouse_button_handler;
	b.bg_color = 0xffffff;
	b.extra_info = info->buttons;
	b.set_text = 1;
	b.text.x = 0;
	b.text.y = 0;
	b.text.text = ft_strdup("circle t1");
	b.text.color = 0x000000;
	b.text.font = info->font;
	add_elem_to_list(info->toolbox, b);
	info->buttons[0] = info->toolbox->elements->content;	
//
	blin = create_button_info(0, 2, &info->brush);
	b.info = &blin;
	b.info_size = ((t_button *)b.info)->size;

	b.x = 160;
	b.y = 50;
	b.w = 100;
	b.h = 50;
	b.parent = info->toolbox->window->surface;
	b.f = &change_brush_type;
	b.event_handler = &ft_mouse_button_handler;
	b.bg_color = 0xffffff;
	b.extra_info = info->buttons;
	b.set_text = 1;
	b.text.x = 0;
	b.text.y = 0;
	b.text.text = ft_strdup("squaer t2");
	b.text.color = 0x000000;
	b.text.font = info->font;
	add_elem_to_list(info->toolbox, b);
	info->buttons[1] = info->toolbox->elements->content;
//
	blin = create_button_info(0, 3, &info->brush);
	b.info = &blin;
	b.info_size = ((t_button *)b.info)->size;

	b.x = 50;
	b.y = 110;
	b.w = 100;
	b.h = 50;
	b.parent = info->toolbox->window->surface;
	b.f = &change_brush_type;
	b.event_handler = &ft_mouse_button_handler;
	b.bg_color = 0xffffff;
	b.extra_info = info->buttons;
	b.set_text = 1;
	b.text.x = 0;
	b.text.y = 0;
	b.text.text = ft_strdup("deletion t3");
	b.text.color = 0x000000;
	b.text.font = info->font;
	add_elem_to_list(info->toolbox, b);
	info->buttons[2] = info->toolbox->elements->content;

	blin = create_button_info(0, 4, &info->brush);
	b.info = &blin;
	b.info_size = ((t_button *)b.info)->size;

	b.x = 160;
	b.y = 110;
	b.w = 100;
	b.h = 50;
	b.parent = info->toolbox->window->surface;
	b.f = &change_brush_type;
	b.event_handler = &ft_mouse_button_handler;
	b.bg_color = 0xffffff;
	b.extra_info = info->buttons;
	b.set_text = 1;
	b.text.x = 0;
	b.text.y = 0;
	b.text.text = ft_strdup("flood t4");
	b.text.color = 0x000000;
	b.text.font = info->font;
	add_elem_to_list(info->toolbox, b);
	info->buttons[3] = info->toolbox->elements->content;

///////////////
//MAIN SURFACE
	t_element_info s;

	s.x = 50;
	s.y = 50;
	s.w = info->main->window->surface->w - (s.x * 2);
	s.h = info->main->window->surface->h - (s.y * 2);
	printf("%d %d\n", s.w, s.h);
	s.parent = info->main->window->surface;
	s.f = &draw;
	s.event_handler = &ft_mouse_button_handler;
	s.bg_color = 0xffffff;
	s.info = &info->brush;
	s.set_text = 0;
	s.text.x = 0;
	s.text.y = 0;
	s.text.text = NULL;
	s.text.color = 0x000000;
	s.text.font = info->font;
	add_elem_to_list(info->main, s);
	info->drawing_surface[0] = info->main->elements->content;
	if (argc >= 2)
	{
		SDL_Surface *temp;
		if ((temp = load_image(argv[1])))
		{
			SDL_BlitSurface(temp, NULL, info->drawing_surface[0]->surface, NULL);
			printf("%s image loaded.\n", argv[1]);
		}
	}
///////////
//SLIDER
	t_element_info	sinf;
	t_slider		slin;
//
	slin = create_slider_info(0, 255, 150, 0xff0000);
	sinf.info = &slin;
	sinf.info_size = ((t_slider *)sinf.info)->size;

	sinf.x = 100;
	sinf.y = 200;
	sinf.w = 200;
	sinf.h = 20;
	sinf.bg_color = 0xffffff;
	sinf.parent = info->toolbox->window->surface;
	sinf.f = &slider_event;
	sinf.event_handler = &ft_mouse_button_handler;
	sinf.set_text = 0;
	add_elem_to_list(info->toolbox, sinf);
	info->r_slider = info->toolbox->elements->content;
//
	slin = create_slider_info(0, 255, 150, 0x00ff00);
	sinf.info = &slin;
	sinf.info_size = ((t_slider *)sinf.info)->size;

	sinf.x = 100;
	sinf.y = 250;
	sinf.w = 200;
	sinf.h = 20;
	sinf.bg_color = 0xffffff;
	sinf.parent = info->toolbox->window->surface;
	sinf.f = &slider_event;
	sinf.event_handler = &ft_mouse_button_handler;
	sinf.set_text = 0;
	add_elem_to_list(info->toolbox, sinf);
	info->g_slider = info->toolbox->elements->content;
//
	slin = create_slider_info(0, 255, 155, 0x0000ff);
	sinf.info = &slin;
	sinf.info_size = ((t_slider *)sinf.info)->size;

	sinf.x = 100;
	sinf.y = 300;
	sinf.w = 200;
	sinf.h = 20;
	sinf.bg_color = 0xffffff;
	sinf.parent = info->toolbox->window->surface;
	sinf.f = &slider_event;
	sinf.event_handler = &ft_mouse_button_handler;
	sinf.set_text = 0;
	add_elem_to_list(info->toolbox, sinf);
	info->b_slider = info->toolbox->elements->content; 
//
	slin = create_slider_info(1, 100, 10, 0xd3d3d3);
	sinf.info = &slin;
	sinf.info_size = ((t_slider *)sinf.info)->size;

	sinf.x = 100;
	sinf.y = 350;
	sinf.w = 200;
	sinf.h = 20;
	sinf.bg_color = 0xffffff;
	sinf.parent = info->toolbox->window->surface;
	sinf.f = &slider_event;
	sinf.event_handler = &ft_mouse_button_handler;
	sinf.set_text = 0;
	add_elem_to_list(info->toolbox, sinf);
	info->size_slider = info->toolbox->elements->content;
//
	t_element_info	bcol;

	bcol.x = 100;
	bcol.y = 400;
	bcol.w = 100;
	bcol.h = 100;
	bcol.bg_color = 0x000000;
	bcol.parent = info->toolbox->window->surface;
	bcol.info_size = 0;
	bcol.info = &info->brush;
	bcol.f = NULL;
	bcol.event_handler = &show_brush_color;
	bcol.set_text = 0;
	add_elem_to_list(info->toolbox, bcol);
////
//text input element
	t_element_info tin;

	tin.x = 100;
	tin.y = 600;
	tin.w = 300;
	tin.h = 32;
	tin.bg_color = 0xffffff;
	tin.parent = info->toolbox->window->surface;
	tin.info_size = 0;
	tin.info = 0;
	tin.f = &tin_reader;
	tin.event_handler = &ft_mouse_button_handler;
	tin.set_text = 1;
	tin.text.x = 0;
	tin.text.y = 0;
	tin.text.text = ft_strdup("IIIIIIIIIIIIIIIIIIIIIIIIIII");
	tin.text.color = 0x000000;
	tin.text.font = info->font;
	add_elem_to_list(info->toolbox, tin);
	info->brush.text_area = &((t_element *)info->toolbox->elements->content)->text;
//
	update_buttons(info->buttons);
	update_slider(info->r_slider);
	update_slider(info->g_slider);
	update_slider(info->b_slider);
	update_slider(info->size_slider);
	while (info->run)
	{
		// EVENT HANDLING
		ft_event_poller(libui);
		if (libui->event.window.windowID == info->toolbox->window->id)
			call_all_handlers(info->toolbox, libui);
		else if (libui->event.window.windowID == info->main->window->id)
			call_all_handlers(info->main, libui);
		info->brush.color = rgb_to_hex(((t_slider *)info->r_slider->info)->value,
										((t_slider *)info->g_slider->info)->value,
										((t_slider *)info->b_slider->info)->value);
		info->brush.size = ((t_slider *)info->size_slider->info)->value;
		// RENDERING
		render_window(info->toolbox);
		render_window(info->main);
	}
}
