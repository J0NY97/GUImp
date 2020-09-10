/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prefab_tools_init.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 11:38:42 by jsalmi            #+#    #+#             */
/*   Updated: 2020/09/10 14:29:42 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

t_element	*prefab_tools_init(t_window *win, int x, int y)
{
	t_xywh		coords;
	t_element	*menu;
	t_element	*open;
	t_element	*save;
	t_element	*quit;

	// MENU
	coords = ui_init_coords(x, y, 400, 100);
	menu = ui_create_surface(win, coords, NULL);
	menu->set_text = 1;
	menu->text = ft_default_text("Tools menu");
	menu->bg_color = 0xffa9a9a9;
	ft_update_background(menu->states[0], menu->bg_color);
	TTF_CloseFont(menu->text.font);
	menu->text.font = TTF_OpenFont("font.ttf", 20);
	menu->old_state = 500;
	ft_update_element(menu);

	// OPEN
	coords = ui_init_coords(25, 25, 100, 50);
	open = ui_create_button(win, coords, menu);
	open->text.text = ft_strdup("Open");
	menu->text.centered = 1;
	open->f = &ft_button_handler;
	open->old_state = 500;
	ft_update_element(open);

	// SAVE
	coords = ui_init_coords(150, 25, 100, 50);
	save = ui_create_button(win, coords, menu);
	save->text.text = ft_strdup("Save");
	menu->text.centered = 1;
	save->f = &ft_button_handler;
	save->old_state = 500;
	ft_update_element(save);

	// QUIT
	coords = ui_init_coords(275, 25, 100, 50);
	quit = ui_create_button(win, coords, menu);
	quit->text.text = ft_strdup("Quit");
	menu->text.centered = 1;
	quit->f = &ft_button_handler;
	quit->old_state = 500;
	ft_update_element(quit);

	return (menu);
}
