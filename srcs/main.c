/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 13:07:25 by nneronin          #+#    #+#             */
/*   Updated: 2020/09/30 13:14:33 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guimp.h"

static inline void	prefab_demo(t_info *info)
{
	t_element	*menu;

	menu = prefab_tools_init(info->toolbox->window,
							info->toolbox->window->surface->w - 175,
							info->toolbox->window->surface->h - 125);
}

static inline void	guimp_init(t_info *info, t_libui *libui)
{
	info->run = 1;
	init_brush(info);
	ui_libui_init(libui);
	tooltips_load(info);
	shape_load(info);
	window_init(libui, info);
	menu_init(info);
	tool_buttons_init(info);
	shape_buttons_init(info);
	slider_init(info);
	drop_down_init(info);
	layer_init(info);
	hotkey_init(info, libui);
	utility_init(info);
	sticker_load(info);
	ft_set_icon(info->main->window->win,
			"resources/stickers/gimp-icon.png");
	info->layer_amount = 1;
}

int					fake_main(void)
{
	t_info		*info;
	t_libui		*libui;

	if (!(libui = (t_libui *)malloc(sizeof(t_libui))))
		return (0);
	if (!(info = (t_info *)malloc(sizeof(t_info))))
		return (0);
	guimp_init(info, libui);
	prefab_demo(info);
	while (info->run)
	{
		ft_event_poller(libui);
		info->run = libui->quit != 1;
		drag_drop(info, libui);
		update_brush(info);
		update_layers(info);
		update_hidden_surface(info, libui);
		ui_render(info->toolbox->window);
		ui_render(info->main->window);
		ui_render(info->layers->window);
	}
	guimp_quit(info);
	free_libui(libui);
	free_sdl();
	return (0);
}

int					main(void)
{
	fake_main();
	ft_printf("bye!");
	while (1)
		;
	return (0);
}
