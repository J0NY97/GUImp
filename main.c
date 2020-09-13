
#include "guimp.h"

void	draw_buttons(SDL_Event e, t_element *elem)
{
	t_element **buttons;
	t_button	*but;
	int			*but_am;

	but = elem->info;
	but_am = but->extra;
	if (e.type == SDL_MOUSEBUTTONDOWN)
	{
		buttons = (t_element **)elem->extra_info;
		for (int i = 0; i < *but_am; i++)
			buttons[i]->default_state = 0;
		elem->default_state = 1;
	}
	if (e.type == SDL_MOUSEMOTION)
		elem->state = 2;
	else if (e.type == SDL_MOUSEBUTTONUP)
		elem->state = 2;
}

void	change_selected_layer(SDL_Event e, t_element *elem)
{
	t_element **buttons;
	t_button	*but;
	int			*but_am;

	but = elem->info;
	but_am = but->extra;
	if (e.type == SDL_MOUSEBUTTONDOWN)
	{
		buttons = (t_element **)elem->extra_info;
		for (int i = 0; i < 5; i++)
			buttons[i]->default_state = 0;
		elem->default_state = 1;
	}
	if (e.type == SDL_MOUSEMOTION)
		elem->state = 2;
	else if (e.type == SDL_MOUSEBUTTONUP)
		elem->state = 2;
}


void	tool_buttons_init(t_info *info)
{
	SDL_Rect	temp;
	t_xywh coord;

	// pencil
	coord = ui_init_coords(25, 25, 100, 50);
	info->buttons[0] = ui_create_button(info->toolbox->window, coord, info->brush_menu);
	ft_set_element_image(info->buttons[0], info->tooltips.circle);
	info->buttons[0]->default_state = 1;

	// text	
	coord = ui_init_coords(150, 25, 100, 50);
	info->buttons[1] = ui_create_button(info->toolbox->window, coord, info->brush_menu);
	info->buttons[1]->text.text = ft_strdup("Text");

	// deletion
	coord = ui_init_coords(275, 25, 100, 50);
	info->buttons[2] = ui_create_button(info->toolbox->window, coord, info->brush_menu);
	ft_set_element_image(info->buttons[2], info->tooltips.deletion);

	// flood
	coord = ui_init_coords(25, 100, 100, 50);
	info->buttons[3] = ui_create_button(info->toolbox->window, coord, info->brush_menu);
	ft_set_element_image(info->buttons[3], info->tooltips.flood);

	// sticker
	coord = ui_init_coords(150, 100, 100, 50);
	info->buttons[4] = ui_create_button(info->toolbox->window, coord, info->brush_menu);
	ft_set_element_image(info->buttons[4], info->tooltips.sticker);

	// zoom and move
	coord = ui_init_coords(275, 100, 100, 50);
	info->buttons[5] = ui_create_button(info->toolbox->window, coord, info->brush_menu);
	ft_set_element_image(info->buttons[5], info->tooltips.move);

	// shapes
	coord = ui_init_coords(25, 175, 100, 50);
	info->buttons[6] = ui_create_button(info->toolbox->window, coord, info->brush_menu);
	ft_set_element_image(info->buttons[6], info->tooltips.shapes);

	// pipette
	coord = ui_init_coords(150, 175, 100, 50);
	info->buttons[7] = ui_create_button(info->toolbox->window, coord, info->brush_menu);
	ft_set_element_image(info->buttons[7], info->tooltips.pipette);
	
	//scrollbar just to demonstrate
	ui_create_scrollbar(info->toolbox->window, info->buttons[7]);

	info->brush_button_amount = 8;
	for (int i = 0; i < info->brush_button_amount; i++)
	{
		info->buttons[i]->f = &draw_buttons;
		info->buttons[i]->extra_info = info->buttons;
		info->buttons[i]->old_state = 500;
		info->buttons[i]->text.centered = 1;
		((t_button *)info->buttons[i]->info)->extra = &info->brush_button_amount;
	}
}

void	layer_init(t_info *info)
{
	t_xywh	coord;

	// the hidden surface, that shows the small image of the selected brush
	coord = ui_init_coords(0, 0, info->main->window->surface->w, info->main->window->surface->h);
	info->hidden_surface = ui_create_surface(info->main->window, coord, NULL);
	info->hidden_surface->shadow = 0;
	info->hidden_surface->event_handler = NULL;
	
	coord = ui_init_coords(50, 50, info->main->window->surface->w - 100, info->main->window->surface->h - 100);
	// init all the drawing layers
	for (int i = 0; i < 5; i++)
	{
		info->drawing_surface[i] = ui_create_surface(NULL, coord, NULL);
		SDL_FreeSurface(info->drawing_surface[i]->surface);
		info->drawing_surface[i]->surface = ft_create_rgba_surface(coord.w, coord.h);
		ft_update_elem_background(info->drawing_surface[i], 0x00ffffff);
		info->drawing_surface[i]->old_state = 500;
		info->drawing_surface[i]->statique = 1;
	}
	// make the first one white
	ft_update_elem_background(info->drawing_surface[0], 0xffffffff);
	// the screen_surface element gets the same stats as the drawing_surfac[0]]
	info->screen_surface = ui_create_surface(info->main->window, coord, NULL);
	SDL_FreeSurface(info->screen_surface->surface);
	info->screen_surface->surface = ft_create_rgba_surface(coord.w, coord.h);
	ft_update_elem_background(info->screen_surface, 0xff000000);
	info->screen_surface->f = &draw;
	info->screen_surface->extra_info = &info->brush;
	((t_surface *)info->screen_surface->info)->extra = info->drawing_surface;

	// brush color surface
	coord = ui_init_coords(275, 50, 100, 100);
	info->brush_color = ui_create_surface(info->toolbox->window, coord, info->col_menu);
	info->brush_color->f = NULL; // not needed but it will spam the terminal otherwise

	for (int i = 0; i < 5; i++)	
	{
		// the actual buttons
		coord = ui_init_coords(50, i * 200 + (i * 25) + 25, info->layer_menu->surface->w - 100, 200);
		info->layer_buttons[i] = ui_create_button(info->layers->window, coord, info->layer_menu);
		info->layer_buttons[i]->f = &change_selected_layer;
		info->layer_buttons[i]->set_text = 0;
		info->layer_buttons[i]->extra_info = info->layer_buttons;
		info->layer_buttons[i]->old_state = 500;
		((t_button *)info->layer_buttons[i]->info)->extra = &info->layer_amount;
		// the area where the layers are shown on
		coord = ui_init_coords(10, 10, info->layer_buttons[i]->surface->w - 20, info->layer_buttons[i]->surface->h - 20);
		info->layer_layers[i] = ui_create_surface(info->layers->window, coord, info->layer_buttons[i]);
		ft_update_elem_background(info->layer_layers[i], 0xfff9f9f9);
	}
}

void	slider_init(t_info *info)
{
	t_xywh	coord;

	coord = ui_init_coords(25, 50, 225, 20);
	info->r_slider = ui_create_slider(info->toolbox->window, coord, info->col_menu, 0, 255);
	((t_slider *)info->r_slider->info)->bar_color = 0xffff0000;

	coord = ui_init_coords(25, 76, 225, 20);
	info->g_slider = ui_create_slider(info->toolbox->window, coord, info->col_menu, 0, 255);
	((t_slider *)info->g_slider->info)->bar_color = 0xff00ff00;

	coord = ui_init_coords(25, 102, 225, 20);
	info->b_slider = ui_create_slider(info->toolbox->window, coord, info->col_menu, 0, 255);
	((t_slider *)info->b_slider->info)->bar_color = 0xff0000ff;

	coord = ui_init_coords(25, 128, 225, 20);
	info->size_slider = ui_create_slider(info->toolbox->window, coord, info->col_menu, 1, 100);

	coord = ui_init_coords(25, 154, 225, 20);
	info->a_slider = ui_create_slider(info->toolbox->window, coord, info->col_menu, 0, 255);

	ft_set_slider_value(info->r_slider, 127);
	ft_set_slider_value(info->g_slider, 127);
	ft_set_slider_value(info->b_slider, 127);
	ft_set_slider_value(info->a_slider, 255);
	ft_set_slider_value(info->size_slider, 49);
}

void	window_init(t_libui *libui, t_info *info)
{
	t_window_info new_win;

	if (!(info->toolbox = (t_win *)malloc(sizeof(t_win))))
		exit (0);
	if (!(info->main = (t_win *)malloc(sizeof(t_win))))
		exit (0);
	if (!(info->layers = (t_win *)malloc(sizeof(t_win))))
		exit (0);

	new_win.coord = ui_init_coords(0, 0, 500, 1250);
	new_win.title = ft_strdup("Toolbox");
	new_win.bg_color = 0xffd3d3d3;
	info->toolbox->window = ft_create_window(libui, new_win);
	
	new_win.coord = ui_init_coords(501, 0, 1000, 1250);
	new_win.title = ft_strdup("Canvas");
	new_win.bg_color = 0xffd3d3d3;
	info->main->window = ft_create_window(libui, new_win);

	new_win.coord = ui_init_coords(1502, 0, 500, 1250);
	new_win.title = ft_strdup("Layers");
	new_win.bg_color = 0xffd3d3d3;
	info->layers->window = ft_create_window(libui, new_win);
}

void	guimp_init(t_info *info)
{
	info->run = 1;
	// brush init
	{
		info->brush.aspect_y = 1;
		info->brush.aspect_x = 1;
		info->brush.zoom = 0;
		info->brush.font_dir = ft_strdup("font.ttf");
		info->brush.draw = 0;
		info->brush.type = 1;
		info->brush.size = 20;
		info->brush.color = 0xffd3d3d3;
		info->brush.shape.x2 = -1;
		info->brush.shape.y2 = -1;
		info->brush.str = NULL;
		info->brush.selected_sticker = 0;
		info->brush.selected_layer = 0;
		//info->brush.text_area->text = NULL;
	}
	// layer stuff
	{
		info->layer_amount = 1;
	}
}

void	save_img(SDL_Event e, t_element *elem)
{
	SDL_Surface *pic;
	char *file;

	if (e.type == SDL_MOUSEBUTTONDOWN)
	{
		pic = ((t_element *)elem->extra_info)->surface;
		if ((file = input_popup(100, 100)) == NULL)
		{
			printf("You decided not to save the picture..\n");
			return;
		}
		if (save_image(pic, file))
			printf("Picture saved.\n");
		else
			printf("Picture couldnt be saved.\n");
		free(file);
	}
}

void	add_new_layer(SDL_Event e, t_element *elem)
{
	t_xywh		coords;
	int			*layer_amount;
	
	layer_amount = elem->extra_info;
	if (e.type == SDL_MOUSEBUTTONDOWN)
	{
		if (*layer_amount == 5)
		{
			ft_putstr("Maximum layers created.");
			return ;
		}
		*layer_amount += 1;
		printf("Layer_amount %d\n", *layer_amount);
	}
}

void	utility_init(t_info *info)
{
	t_xywh coord;
	t_element *menu;

	coord = ui_init_coords(25, info->toolbox->window->surface->h - 125, 275, 100);
	menu = ui_create_surface(info->toolbox->window, coord, NULL);
	ft_update_elem_background(menu, 0xffa9a9a9);
	// save_button
	coord = ui_init_coords(25, 25, 100, 50);
	info->save_button = ui_create_button(info->toolbox->window, coord, menu);
	info->save_button->text.text = ft_strdup("Save");
	info->save_button->text.centered = 1;
	info->save_button->f = &save_img;
	info->save_button->extra_info = info->drawing_surface[0];
	info->save_button->old_state = 500;
	// new layer button
	coord = ui_init_coords(150, 25, 100, 50);
	info->new_layer_button = ui_create_button(info->toolbox->window, coord, menu);
	info->new_layer_button->text.text = ft_strdup("New layer");
	info->new_layer_button->text.centered = 1;
	info->new_layer_button->f = &add_new_layer;
	info->new_layer_button->extra_info = &info->layer_amount;
	info->new_layer_button->old_state = 500;
	// text input area
	coord = ui_init_coords(40, 1000, 400, 50);
	info->text_area = ui_create_button(info->toolbox->window, coord, NULL);
	info->text_area->text.text = ft_strdup("Print Text");
	info->text_area->f = &text_area;
	info->text_area->text.y = 10;
	info->text_area->text.x = 10;
	info->text_area->set_text = 1;
	info->text_area->old_state = 500;
	info->text_area->extra_info = info->toolbox->window;

	// button on window for demonstration
	coord = ui_init_coords(400, 800, 100, 50);
	t_element *butbut = ui_create_button(info->toolbox->window, coord, NULL);
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

void	drop_down_init(t_info *info)
{
	t_xywh coord;
	SDL_Surface *icon;
	SDL_Rect	temp;

	temp.w = 32;
	temp.h = 32;
	temp.x = 175 - temp.w;
	temp.y = 0;

	// STICKER SELECTION DROP DOWN
	coord = ui_init_coords(25, 200, 162, 32);
	info->drop_down = ui_create_drop(info->toolbox->window, coord, info->col_menu);
	info->drop_down->text.text = ft_strdup("Sticker select");
	info->drop_down->text.x = 10;
	info->drop_down->old_state = 500;
	// item1
	ft_drop_down_add_item(info->drop_down, "Minion");
	icon = load_image("resources/stickers/icon-minion.png");
	SDL_BlitSurface(icon, NULL, ((t_drop_down *)info->drop_down->info)->items[0]->surface, &temp);
	SDL_BlitSurface(icon, NULL, ((t_drop_down *)info->drop_down->info)->items[0]->states[0], &temp);
	SDL_BlitSurface(icon, NULL, ((t_drop_down *)info->drop_down->info)->items[0]->states[1], &temp);
	SDL_FreeSurface(icon);
	// item2
	ft_drop_down_add_item(info->drop_down, "Guimp-icon");
	icon = load_image("resources/stickers/icon-gimp-icon.png");
	SDL_BlitSurface(icon, NULL, ((t_drop_down *)info->drop_down->info)->items[1]->surface, &temp);
	SDL_BlitSurface(icon, NULL, ((t_drop_down *)info->drop_down->info)->items[1]->states[0], &temp);
	SDL_BlitSurface(icon, NULL, ((t_drop_down *)info->drop_down->info)->items[1]->states[1], &temp);
	SDL_FreeSurface(icon);

	// this have to be called after all the items have been added other wise if you edite the items they wont be updated
	//  on the drop down menu after they have been edited in here
	ft_update_drop(info->drop_down);

	// FONT SELECTION DROP DOWN
	coord = ui_init_coords(212, 200, 162, 32);
	info->font_down = ui_create_drop(info->toolbox->window, coord, info->col_menu);
	info->font_down->text.text = ft_strdup("Font select");
	info->font_down->text.x = 10;
	info->font_down->old_state = 500;

	ft_drop_down_add_item(info->font_down, "font.ttf");
	ft_drop_down_add_item(info->font_down, "Amatic.ttf");
	ft_drop_down_add_item(info->font_down, "OpenSans.ttf");
	ft_drop_down_add_item(info->font_down, "Pacifico.ttf");
	ft_drop_down_add_item(info->font_down, "Tusj.ttf");
	//ft_drop_down_add_item(info->font_down, "SeaSideResort.ttf");
	ft_update_drop(info->font_down);
}

void	update_brush(t_info *info)
{	
	SDL_Color color;

	if (info->brush.type == 8) // aka pipette
	{
		color = hex_to_rgba(info->brush.color);
		ft_set_slider_value(info->r_slider, color.r);
		ft_set_slider_value(info->g_slider, color.g);
		ft_set_slider_value(info->b_slider, color.b);
		ft_set_slider_value(info->a_slider, color.a);
	}
	else
	{
		info->brush.color = rgb_to_hex(((t_slider *)info->r_slider->info)->value,
									((t_slider *)info->g_slider->info)->value,
									((t_slider *)info->b_slider->info)->value,
									((t_slider *)info->a_slider->info)->value);
	}
	info->brush.size = ((t_slider *)info->size_slider->info)->value;
	for (int i = 0; i < info->brush_button_amount; i++)
		if (info->buttons[i]->state == 1)
			info->brush.type = i + 1;
	for (int i = 0; i < info->layer_amount; i++)
		if (info->layer_buttons[i]->state == 1)
			info->brush.selected_layer = i;
	for (int i = 0; i < ((t_drop_down *)info->drop_down->info)->item_amount; i++)
		if (((t_drop_down *)info->drop_down->info)->items[i]->state == 1)
			info->brush.selected_sticker = i;
	for (int i = 0; i < ((t_drop_down *)info->font_down->info)->item_amount; i++)
		if (((t_drop_down *)info->font_down->info)->items[i]->state == 1)
			info->brush.font_dir = ft_strjoiner("libui/TTF/", ((t_drop_down *)info->font_down->info)->items[i]->text.text, NULL);
	for (int i = 0; i < info->shapes_nbr; i++)
			if (info->shapes[i]->state == 1)
				info->brush.shape_type = i + 1;
	free(info->brush.str);
	info->brush.str = ft_strdup(info->text_area->text.text);
	ft_update_background(info->brush_color->surface, info->brush.color);
}

void	menu_init(t_info *info)
{
	t_xywh coord;

	coord = ui_init_coords(40, 25, 400, 255);
	info->brush_menu = ui_create_surface(info->toolbox->window, coord, NULL);
	info->brush_menu->set_text = 1;
	info->brush_menu->f = NULL;
	info->brush_menu->text = ft_default_text("Brush buttons");
	info->brush_menu->text.x = 5;
	TTF_CloseFont(info->brush_menu->text.font);
	info->brush_menu->text.font = TTF_OpenFont("font.ttf", 20);
	info->brush_menu->old_state = 500;
	ft_update_elem_background(info->brush_menu, 0xffa9a9a9);

	coord = ui_init_coords(40, 305, 400, 380);
	info->col_menu = ui_create_surface(info->toolbox->window, coord, NULL);
	info->col_menu->set_text = 1;
	info->col_menu->f = NULL;
	info->col_menu->text = ft_default_text("Brush modifier");
	info->col_menu->text.x = 5;
	TTF_CloseFont(info->col_menu->text.font);
	info->col_menu->text.font = TTF_OpenFont("font.ttf", 20);
	info->col_menu->old_state = 500;
	ft_update_elem_background(info->col_menu, 0xffa9a9a9);

	coord = ui_init_coords(40, 710, 400, 100);
	info->shape_menu = ui_create_surface(info->toolbox->window, coord, NULL);
	info->shape_menu->set_text = 1;
	info->shape_menu->f = NULL;
	info->shape_menu->text = ft_default_text("Shapes modifier");
	info->shape_menu->bg_color = 0xffa9a9a9;
	info->shape_menu->text.x = 5;
	ft_update_background(info->shape_menu->states[0], 0xffa9a9a9);
	TTF_CloseFont(info->shape_menu->text.font);
	info->shape_menu->text.font = TTF_OpenFont("font.ttf", 20);
	info->shape_menu->old_state = 500;

	coord = ui_init_coords(50, 50, 400, 1150);
	info->layer_menu = ui_create_surface(info->layers->window, coord, NULL);
	info->layer_menu->set_text = 1;
	info->layer_menu->f = NULL;
	info->layer_menu->text = ft_default_text("Layers");
	info->layer_menu->text.x = 5;
	TTF_CloseFont(info->layer_menu->text.font);
	info->layer_menu->text.font = TTF_OpenFont("font.ttf", 20);
	info->layer_menu->old_state = 500;
	ft_update_elem_background(info->layer_menu, 0xffa9a9a9);

	// scrollbar
	ui_create_scrollbar(info->layers->window, info->layer_menu);
}

void	drag_drop_thing(t_info *info, t_libui *libui)
{
	SDL_Surface *new_image;

	if (libui->drag_file != NULL)
	{
		if ((new_image = load_image(libui->drag_file)))
		{
			SDL_BlitSurface(new_image, NULL, info->drawing_surface[0]->surface, NULL);
			SDL_FreeSurface(new_image);
		}
		ft_strdel(&libui->drag_file);
	}
}

void	parent_elem_test(t_info *info)
{
	t_xywh		coord;
	t_element	*menu;
	t_element	*butt;

	coord = ui_init_coords(50, 800, 100, 100);
	menu = ui_create_surface(info->toolbox->window, coord, NULL);
	menu->old_state = 500;
	ft_update_elem_background(menu, 0xffa9a9a9);

	coord = ui_init_coords(10, 10, 10, 10);
	butt = ui_create_button(info->toolbox->window, coord, menu);
	butt->old_state = 500;
	ft_update_elem_background(butt, 0xff3dffff);
}

void	update_layers(t_info *info)
{
	SDL_Surface *new_surface;
	
	for (int i = 0; i < info->layer_amount; i++)
	{
		new_surface = ft_scale_surface_aspect(info->drawing_surface[i]->surface,
											info->layer_layers[i]->surface->w,
											info->layer_layers[i]->surface->h);
		SDL_BlitSurface(new_surface, NULL, info->layer_layers[i]->surface, NULL);
		SDL_FreeSurface(new_surface);
	}
	for (int i = 0; i < info->layer_amount; i++)
	{
		SDL_BlitScaled(info->drawing_surface[i]->surface, NULL, info->screen_surface->surface, NULL);
	}
}

void	update_hidden_surface(t_info *info, t_libui *libui)
{
	int x = libui->event.button.x;
	int y = libui->event.button.y;
	t_shapes l;
	SDL_Rect	temp;

	l.x1 = x;
	l.y1 = y;
	l.size = info->brush.size / info->brush.aspect_x;
	ft_update_background(info->hidden_surface->surface, 0x00000000);
	if (libui->event.window.windowID == info->main->window->id)
	{	
		if (info->brush.type == 1)
		{
			l.fill = 0;
			ft_create_circle(info->hidden_surface->surface, info->brush.color, l);
		}
		else if (info->brush.type == 2)
		{
			text_to_screen(info->hidden_surface->surface, l, &info->brush);
		}
		else if (info->brush.type == 3)
		{
			l.fill = 1;
			ft_create_circle(info->hidden_surface->surface, info->drawing_surface[info->brush.selected_layer]->bg_color, l);
		}
		else if (info->brush.type == 4)
		{
			temp.w = info->tooltips.flood->w;
			temp.h = info->tooltips.flood->h;
			temp.x = l.x1;
			temp.y = l.y1 - temp.h;
			SDL_BlitSurface(info->tooltips.flood, NULL, info->hidden_surface->surface, &temp);
		}
		else if (info->brush.type == 5) // sticker
		{
			temp.w = info->brush.stickers[info->brush.selected_sticker]->w;
			temp.h = info->brush.stickers[info->brush.selected_sticker]->h;
			temp.x = l.x1 - temp.w / 2;
			temp.y = l.y1 - temp.h / 2;
			SDL_BlitSurface(info->brush.stickers[info->brush.selected_sticker], NULL, info->hidden_surface->surface, &temp);
		}
		else if (info->brush.type == 6) // move and zoom
		{
			temp.w = info->tooltips.move->w;
			temp.h = info->tooltips.move->h;
			temp.x = l.x1 - temp.w / 2;
			temp.y = l.y1 - temp.h / 2;
			SDL_BlitSurface(info->tooltips.move, NULL, info->hidden_surface->surface, &temp);
		}
		else if (info->brush.type == 7) // shapes
			trace_shape(info);
		else if (info->brush.type == 8) // pipette
		{
			temp.w = info->tooltips.pipette->w;
			temp.h = info->tooltips.pipette->h;;
			temp.x = l.x1;
			temp.y = l.y1 - temp.h;
			SDL_BlitSurface(info->tooltips.pipette, NULL, info->hidden_surface->surface, &temp);
		}
	}
}

int		main(void)
{
	t_libui *libui;
	t_info *info;

	if (!(libui = (t_libui *)malloc(sizeof(t_libui))))
		exit (0);
	ui_libui_init(libui);
	if (!(info = (t_info *)malloc(sizeof(t_info))))
		exit (0);
	guimp_init(info);
	tooltips_load(info);
	shape_load(info);
	window_init(libui, info);
	menu_init(info);
	tool_buttons_init(info);
	shape_buttons_init(info);
	slider_init(info);
	drop_down_init(info);
	layer_init(info); // slider_init needs to be called before this.
	hotkey_init(info, libui);
	utility_init(info); // layer_init needs to be called before this.
	sticker_load(info);
	ft_set_icon(info->main->window->win, "resources/icon/gimp-icon.png");
	t_element *menu = prefab_tools_init(info->toolbox->window,
										info->toolbox->window->surface->w - 175,
										info->toolbox->window->surface->h - 125);
	while (info->run)
	{
		ft_event_poller(libui); // input
		drag_drop_thing(info, libui);
		update_brush(info);
		update_layers(info);
		update_hidden_surface(info, libui);
		ui_render(info->toolbox->window);
		ui_render(info->main->window);
		ui_render(info->layers->window);
	}
	// cleanup()
	return (0);
}
