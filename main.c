
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

void	button_init(t_info *info)
{
	t_xywh coord;

	coord = ui_init_coords(25, 25, 100, 50);
	info->buttons[0] = ui_create_button(info->toolbox->window, coord, info->brush_menu);
	info->buttons[0]->text.text = ft_strdup("Circle");
	info->buttons[0]->default_state = 1;

	coord = ui_init_coords(150, 25, 100, 50);
	info->buttons[1] = ui_create_button(info->toolbox->window, coord, info->brush_menu);
	info->buttons[1]->text.text = ft_strdup("Text");

	coord = ui_init_coords(275, 25, 100, 50);
	info->buttons[2] = ui_create_button(info->toolbox->window, coord, info->brush_menu);
	info->buttons[2]->text.text = ft_strdup("Delete");

	coord = ui_init_coords(25, 100, 100, 50);
	info->buttons[3] = ui_create_button(info->toolbox->window, coord, info->brush_menu);
	info->buttons[3]->text.text = ft_strdup("Flood");

	coord = ui_init_coords(150, 100, 100, 50);
	info->buttons[4] = ui_create_button(info->toolbox->window, coord, info->brush_menu);
	info->buttons[4]->text.text = ft_strdup("Sticker");

	coord = ui_init_coords(275, 100, 100, 50);
	info->buttons[5] = ui_create_button(info->toolbox->window, coord, info->brush_menu);
	info->buttons[5]->text.text = ft_strdup("Magnify");

	coord = ui_init_coords(25, 175, 100, 50);
	info->buttons[6] = ui_create_button(info->toolbox->window, coord, info->brush_menu);
	info->buttons[6]->text.text = ft_strdup("Move");

	coord = ui_init_coords(150, 175, 100, 50);
	info->buttons[7] = ui_create_button(info->toolbox->window, coord, info->brush_menu);
	info->buttons[7]->text.text = ft_strdup("Pipette");

	info->brush_button_amount = 8;
	// for now you have to manually update the buttons after change, pl0x fix
	for (int i = 0; i < info->brush_button_amount; i++)
	{
		info->buttons[i]->f = &draw_buttons;
		info->buttons[i]->extra_info = info->buttons;
		((t_button *)info->buttons[i]->info)->extra = &info->brush_button_amount;
		info->buttons[i]->old_state = 500;
		info->buttons[i]->text.centered = 1;
		ft_update_element(info->buttons[i]);
	}
}

void	layer_init(t_info *info)
{
	t_xywh	coord;

	coord = ui_init_coords(50, 50,
			info->main->window->surface->w - (100),
			info->main->window->surface->h - (100));
	info->drawing_surface[0] = ui_create_surface(info->main->window, coord, NULL);
	info->drawing_surface[0]->f = &draw;
	info->drawing_surface[0]->statique = 1;
	info->drawing_surface[0]->extra_info = &info->brush;

	// brush color surface
	coord = ui_init_coords(275, 50, 100, 100);
	info->brush_color = ui_create_surface(info->toolbox->window, coord, info->col_menu);
	info->brush_color->f = NULL; // not needed but it will spam the terminal otherwise
}

void	slider_init(t_info *info)
{
	t_xywh	coord;

	coord = ui_init_coords(25, 50, 200, 20);
	info->r_slider = ui_create_slider(info->toolbox->window, coord, info->col_menu, 0, 255);
	((t_slider *)info->r_slider->info)->bar_color = 0xff0000;

	coord = ui_init_coords(25, 75, 200, 20);
	info->g_slider = ui_create_slider(info->toolbox->window, coord, info->col_menu, 0, 255);
	((t_slider *)info->g_slider->info)->bar_color = 0x00ff00;

	coord = ui_init_coords(25, 100, 200, 20);
	info->b_slider = ui_create_slider(info->toolbox->window, coord, info->col_menu, 0, 255);
	((t_slider *)info->b_slider->info)->bar_color = 0x0000ff;

	coord = ui_init_coords(25, 125, 200, 20);
	info->size_slider = ui_create_slider(info->toolbox->window, coord, info->col_menu, 1, 100);

	ft_set_slider_value(info->r_slider, 125);
	ft_set_slider_value(info->g_slider, 125);
	ft_set_slider_value(info->b_slider, 125);
	ft_set_slider_value(info->size_slider, 10);
}

void	window_init(t_libui *libui, t_info *info)
{
	t_window_info new_win;

	if (!(info->toolbox = (t_win *)malloc(sizeof(t_win))))
		exit (0);
	if (!(info->main = (t_win *)malloc(sizeof(t_win))))
		exit (0);

	new_win.coord = ui_init_coords(0, 0, 500, 1250);
	new_win.title = ft_strdup("Toolbox");
	new_win.bg_color = 0xd3d3d3;
	info->toolbox->window = ft_create_window(libui, new_win);
	
	new_win.coord = ui_init_coords(501, 0, 1000, 1250);
	new_win.title = ft_strdup("Canvas");
	new_win.bg_color = 0xd3d3d3;
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
		info->brush.str = NULL;
		//info->brush.text_area->text = NULL;
	}
}

void	save_img(SDL_Event e, t_element *elem)
{
	SDL_Surface *pic;

	if (e.type == SDL_MOUSEBUTTONDOWN)
	{
		pic = ((t_element *)elem->extra_info)->surface;
		if (!save_image(pic, input_popup(100, 100))) // this should be file name without the file type.... for now
			printf("Picture couldnt be saved.\n");
		else
			printf("Picture saved.\n");
	}
}

void	add_new_layer(SDL_Event e, t_element *elem)
{
	char *temp;
	char **dimensions;
	t_element **drawing;
// dont add this until shiit is done
	if (e.type == SDL_MOUSEBUTTONDOWN)
	{
		drawing = elem->extra_info; // the drawing surfaces
		temp = input_popup(0, 0);
		dimensions = ft_strsplit(temp, 'x');
	
		printf("%sx%s\n", dimensions[0], dimensions[1]);

		SDL_FreeSurface(drawing[0]->surface);
		drawing[0]->surface = SDL_CreateRGBSurface(0, ft_atoi(dimensions[0]), ft_atoi(dimensions[1]), 32, 0, 0, 0, 0);
		ft_update_background(drawing[0]->surface, drawing[0]->bg_color);
		ft_strdel(&dimensions[0]);
		ft_strdel(&dimensions[1]);
		free(dimensions);
		free(temp);
	}
}

void	utility_init(t_info *info)
{
	t_xywh coord;

	// save_button
	coord = ui_init_coords(50, info->toolbox->window->surface->h - 60, 100, 50);
	info->save_button = ui_create_button(info->toolbox->window, coord, NULL);
	info->save_button->text.text = ft_strdup("Save");
	info->save_button->text.centered = 1;
	info->save_button->f = &save_img;
	info->save_button->extra_info = info->drawing_surface[0];
	info->save_button->old_state = 500;
	ft_update_element(info->save_button);

	coord = ui_init_coords(200, info->toolbox->window->surface->h - 60, 100, 50);
	info->new_layer_button = ui_create_button(info->toolbox->window, coord, NULL);
	info->new_layer_button->text.text = ft_strdup("New layer");
	info->new_layer_button->text.centered = 1;
	info->new_layer_button->f = &add_new_layer;
	info->new_layer_button->extra_info = info->drawing_surface;
	info->new_layer_button->old_state = 500;
	ft_update_element(info->new_layer_button);

	coord = ui_init_coords(50, 1000, 250, 50);
	info->text_area = ui_create_button(info->toolbox->window, coord, NULL);
	info->text_area->text.text = ft_strdup("Print Text");
	info->text_area->f = &text_area;
	info->text_area->text.y = 10;
	info->text_area->text.x = 10;
	info->text_area->set_text = 1;
	info->text_area->old_state = 500;
	info->text_area->extra_info = info->toolbox->window->win;
	ft_update_element(info->text_area);
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

void	drop_click(SDL_Event e, t_element *elem)
{
	printf("Drop item %s clicked\n", elem->text.text);
}

void	drop_down_init(t_info *info)
{
	t_xywh coord;

	coord = ui_init_coords(50, 200, 200, 32);
	info->drop_down = ui_create_drop(info->toolbox->window, coord, info->col_menu);
	ft_drop_down_add_item(info->drop_down, &drop_click, "item1");
	ft_drop_down_add_item(info->drop_down, &drop_click, "item2");
}

void	update_brush(t_info *info)
{	
	if (info->brush.type == 8) // aka pipette
	{
		SDL_Color color;

		color = hex_to_rgba(info->brush.color);

		ft_set_slider_value(info->r_slider, color.r);
		ft_set_slider_value(info->g_slider, color.g);
		ft_set_slider_value(info->b_slider, color.b);
	}
	else
	{
		info->brush.color = rgb_to_hex(((t_slider *)info->r_slider->info)->value,
									((t_slider *)info->g_slider->info)->value,
									((t_slider *)info->b_slider->info)->value);
	}
	info->brush.size = ((t_slider *)info->size_slider->info)->value;
	for (int i = 0; i < info->brush_button_amount; i++)
		if (info->buttons[i]->state == 1)
			info->brush.type = i + 1;
	ft_update_background(info->brush_color->surface, info->brush.color);
}

void	menu_init(t_info *info)
{
	t_xywh coord;

	coord = ui_init_coords(40, 20, 400, 250);
	info->brush_menu = ui_create_surface(info->toolbox->window, coord, NULL);
	info->brush_menu->set_text = 1;
	info->brush_menu->f = NULL;
	info->brush_menu->text = ft_default_text("Brush buttons");
	info->brush_menu->bg_color = 0xa9a9a9;
	info->brush_menu->text.x = 5;
	ft_update_background(info->brush_menu->states[0], 0xa9a9a9);
	TTF_CloseFont(info->brush_menu->text.font);
	info->brush_menu->text.font = TTF_OpenFont("font.ttf", 20);
	info->brush_menu->old_state = 500;
	ft_update_element(info->brush_menu);

	coord = ui_init_coords(40, 325, 400, 250);
	info->col_menu = ui_create_surface(info->toolbox->window, coord, NULL);
	info->col_menu->set_text = 1;
	info->col_menu->f = NULL;
	info->col_menu->text = ft_default_text("Brush modifier");
	info->col_menu->bg_color = 0xaa9a9;
	info->col_menu->text.x = 5;
	ft_update_background(info->col_menu->states[0], 0xa9a9a9);
	TTF_CloseFont(info->col_menu->text.font);
	info->col_menu->text.font = TTF_OpenFont("font.ttf", 20);
	info->col_menu->old_state = 500;
	ft_update_element(info->col_menu);
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
	menu->bg_color = 0xa9a9a9;
	menu->old_state = 500;
	ft_update_background(menu->states[0], menu->bg_color);

	coord = ui_init_coords(10, 10, 10, 10);
	butt = ui_create_button(info->toolbox->window, coord, menu);
	butt->bg_color = 0x3dffff;
	ft_update_background(butt->states[0], butt->bg_color);
	butt->old_state = 500;
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

	window_init(libui, info);
	menu_init(info);
	button_init(info);
	slider_init(info);
	drop_down_init(info);
	layer_init(info); // slider_init needs to be called before this.
	hotkey_init(info, libui);
	utility_init(info); // layer_init needs to be called before this.
	// z_buffer_sort(); // this has to happen after ALL elem inits and BEFORE the main loop
	ft_set_icon(info->main->window->win, "resources/gimp-icon.png");

	parent_elem_test(info);
	while (info->run)
	{
		ft_event_poller(libui); // input
		drag_drop_thing(info, libui);
		update_brush(info);
		ui_render(info->toolbox->window);
		ui_render(info->main->window);
	}
	// cleanup()
	return (0);
}
