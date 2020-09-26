/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utility_elems.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 17:51:33 by nneronin          #+#    #+#             */
/*   Updated: 2020/09/26 18:09:54 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guimp.h"

static inline void	save_button(t_info *info, t_element *menu)
{
	t_xywh		coord;

	coord = ui_init_coords(25, 25, 100, 50);
	info->save_button = ui_create_button(info->toolbox->window, coord, menu);
	ft_set_text(&info->save_button->text, "Save");
	info->save_button->text.centered = 1;
	info->save_button->f = &save_img;
	info->save_button->extra_info = info->drawing_surface[0];
}

static inline void	new_layer_button(t_info *info, t_element *menu)
{
	t_xywh		coord;

	coord = ui_init_coords(150, 25, 100, 50);
	info->new_layer_button = ui_create_button(info->toolbox->window, coord, menu);
	ft_set_text(&info->new_layer_button->text, "New layer");
	info->new_layer_button->text.centered = 1;
	info->new_layer_button->f = &add_new_layer;
	info->new_layer_button->extra_info = &info->layer_amount;

}

static inline void	text_input_area(t_info *info)
{
	t_xywh		coord;

	coord = ui_init_coords(40, 1000, 400, 50);
	info->text_area = ui_create_button(info->toolbox->window, coord, NULL);
	ft_set_text(&info->text_area->text, "Print Text");
	info->text_area->text.centered = 1;
	info->text_area->f = &text_area;
	info->text_area->extra_info = info->toolbox->window;
}

static inline void	clear_workspace_button(t_info *info)
{
	t_xywh		coord;

	coord = ui_init_coords(40, 1100, 100, 50);
	info->clear_workspace = ui_create_button(info->toolbox->window, coord, NULL);
	ft_set_text(&info->clear_workspace->text, "Clear");
	info->clear_workspace->text.centered = 1;
	info->clear_workspace->f = &reset_workspace;
	info->clear_workspace->extra_info = info->drawing_surface;
}

static inline void	open_file_button(t_info *info)
{
	t_xywh		coord;

	coord = ui_init_coords(165, 1100, 100, 50);
	info->clear_workspace = ui_create_button(info->toolbox->window, coord, NULL);
	ft_set_text(&info->clear_workspace->text, "Open");
	info->clear_workspace->text.centered = 1;
	info->clear_workspace->f = &open_button;
	((t_button *)info->clear_workspace->info)->extra = &info->brush;
	info->clear_workspace->extra_info = info->drawing_surface;
}


void				utility_init(t_info *info)
{
	t_xywh		coord;
	t_element	*menu;

	coord = ui_init_coords(25, info->toolbox->window->surface->h - 125, 275, 100);
	menu = ui_create_surface(info->toolbox->window, coord, NULL);
	ft_update_elem_background(menu, 0xffa9a9a9);
	save_button(info, menu);
	new_layer_button(info, menu);
	text_input_area(info);
	clear_workspace_button(info);
	open_file_button(info);

}
