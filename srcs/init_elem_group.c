/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 15:13:37 by nneronin          #+#    #+#             */
/*   Updated: 2020/09/26 15:39:50 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guimp.h"

static inline void	layers(t_info *info)
{
	t_xywh coord;

	coord = ui_init_coords(50, 50, 400, 1150);
	info->layer_menu = ui_create_surface(info->layers->window, coord, NULL);
	ft_set_text(&info->layer_menu->text, "Layers");
	info->layer_menu->text.x = 5;
	ft_set_font(&info->layer_menu->text, "font.ttf", 20);
	ft_update_elem_background(info->layer_menu, 0xffa9a9a9);
	ui_create_scrollbar(info->layers->window, info->layer_menu);
}

static inline void	shapes_modifier(t_info *info)
{
	t_xywh coord;

	coord = ui_init_coords(40, 710, 400, 100);
	info->shape_menu = ui_create_surface(info->toolbox->window, coord, NULL);
	info->shape_menu->bg_color = 0xffa9a9a9;
	ft_update_background(info->shape_menu->states[0], 0xffa9a9a9);
	ft_set_text(&info->shape_menu->text, "Shapes modifier");
	ft_set_font(&info->shape_menu->text, "font.ttf", 20);
	info->shape_menu->text.x = 5;
}

static inline void	brush_modifier(t_info *info)
{
	t_xywh coord;

	coord = ui_init_coords(40, 305, 400, 380);
	info->col_menu = ui_create_surface(info->toolbox->window, coord, NULL);
	ft_set_text(&info->col_menu->text, "Brush modifier");
	info->col_menu->text.x = 5;
	ft_set_font(&info->col_menu->text, "font.ttf", 20);
	ft_update_elem_background(info->col_menu, 0xffa9a9a9);
}

static inline void	brush_button(t_info *info)
{
	t_xywh coord;

	coord = ui_init_coords(40, 25, 400, 255);
	info->brush_menu = ui_create_surface(info->toolbox->window, coord, NULL);
	ft_set_text(&info->brush_menu->text, "Brush buttons");
	info->brush_menu->text.x = 5;
	ft_set_font(&info->brush_menu->text, "font.ttf", 20);
	ft_update_elem_background(info->brush_menu, 0xffa9a9a9);
}

void				menu_init(t_info *info)
{
	brush_button(info);
	brush_modifier(info);
	shapes_modifier(info);
	layers(info);
}
