
#include "guimp.h"

void	guimp_init(t_info *info)
{
	info->run = 1;
	init_brush(info);
	info->layer_amount = 1; //idk
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
		info->brush.shape.color = info->brush.color;
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

void	drag_drop_thing(t_info *info, t_libui *libui)
{
	SDL_Surface *new_image;

	if (libui->drag_file != NULL)
	{
		if ((new_image = load_image(libui->drag_file)))
		{
			SDL_BlitSurface(new_image, NULL, info->drawing_surface[info->brush.selected_layer]->surface, NULL);
			SDL_FreeSurface(new_image);
		}
		ft_strdel(&libui->drag_file);
	}
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
	ft_update_background(info->screen_surface->surface, info->drawing_surface[0]->bg_color);
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
	
	l = info->brush.shape;
	l.x1 = x;
	l.y1 = y;
	l.size = info->brush.size / info->brush.aspect_x;
	ft_update_background(info->hidden_surface->surface, 0x00000000);
	if (libui->event.window.windowID == info->main->window->id)
	{	
		if (info->brush.type == 1) // pencil
		{
			l.fill = 0;
			ft_create_circle(info->hidden_surface->surface, info->brush.color, l);
		}
		else if (info->brush.type == 2) // text
		{
			text_to_screen(info->hidden_surface->surface, l, info->brush.str, info->brush.font_dir);
		}
		else if (info->brush.type == 3) // eraser
		{
			l.fill = 1;
			ft_create_circle(info->hidden_surface->surface, info->drawing_surface[info->brush.selected_layer]->bg_color, l);
		}
		else if (info->brush.type == 4)
		{
			temp = ft_sdl_rect(l.x1, l.y1 - info->tooltips.flood->h, info->tooltips.flood->w, info->tooltips.flood->h);
			SDL_BlitSurface(info->tooltips.flood, NULL, info->hidden_surface->surface, &temp);
		}
		else if (info->brush.type == 5) // sticker
		{
			temp = ft_sdl_rect(l.x1 - info->brush.stickers[info->brush.selected_sticker]->w / 2,
							l.y1 - info->brush.stickers[info->brush.selected_sticker]->h / 2,
							info->brush.stickers[info->brush.selected_sticker]->w,
							info->brush.stickers[info->brush.selected_sticker]->h);
			SDL_BlitSurface(info->brush.stickers[info->brush.selected_sticker], NULL, info->hidden_surface->surface, &temp);
		}
		else if (info->brush.type == 6) // move and zoom
		{
			temp = ft_sdl_rect(l.x1 - (info->tooltips.move->w / 2),
							l.y1 - (info->tooltips.move->h / 2),
							info->tooltips.move->w,
							info->tooltips.move->h);
			SDL_BlitSurface(info->tooltips.move, NULL, info->hidden_surface->surface, &temp);
		}
		else if (info->brush.type == 7) // shapes
			trace_shape(info);
		else if (info->brush.type == 8) // pipette
		{
			temp = ft_sdl_rect(l.x1, l.y1 - info->tooltips.pipette->h, info->tooltips.pipette->w, info->tooltips.pipette->h);
			SDL_BlitSurface(info->tooltips.pipette, NULL, info->hidden_surface->surface, &temp);
		}
	}
}

int		fake_main(void)
{
	t_libui *libui;
	t_info *info;

	if (!(libui = (t_libui *)malloc(sizeof(t_libui))))
		exit (0);
	if (!(info = (t_info *)malloc(sizeof(t_info))))
		exit (0);
	ui_libui_init(libui);
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
		ft_event_poller(libui);
		info->run = libui->quit != 1;
		drag_drop_thing(info, libui);
		update_brush(info);
		update_layers(info);
		update_hidden_surface(info, libui);
		ui_render(info->toolbox->window);
		ui_render(info->main->window);
		ui_render(info->layers->window);
	}
	ft_printf("bye!");
//	guimp_quit(info); // cleanup the quimp stuff
	free_libui(libui);
	IMG_Quit();
	TTF_Quit();
	SDL_Quit();
	return (0);
}

int main(void)
{
	fake_main();
	//while(1);
	return (0);
}
