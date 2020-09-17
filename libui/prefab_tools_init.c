/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prefab_tools_init.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 11:38:42 by jsalmi            #+#    #+#             */
/*   Updated: 2020/09/17 13:17:14 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ft_quit(SDL_Event e, t_element *elem)
{
	if (e.type == SDL_MOUSEBUTTONDOWN)
		exit(0);
}

t_element	*prefab_tools_init(t_window *win, int x, int y)
{
	t_xywh		coords;
	t_element	*menu;
	t_element	*quit;

	coords = ui_init_coords(x, y, 150, 100);
	menu = ui_create_surface(win, coords, NULL);
	menu->text.set_text = 1;
	ft_set_text(&menu->text, "Tools menu");
	menu->bg_color = 0xffa9a9a9;
	ft_update_background(menu->states[0], menu->bg_color);
	ft_set_font(&menu->text, "font.ttf", 20);
	ft_update_element(menu);

	coords = ui_init_coords(25, 25, 100, 50);
	quit = ui_create_button(win, coords, menu);
	ft_set_text(&quit->text, "Quit");
	quit->f = &ft_quit;
	quit->text.centered = 1;
	ft_update_element(quit);

	return (menu);
}
