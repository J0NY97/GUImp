/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_slider.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 16:07:15 by nneronin          #+#    #+#             */
/*   Updated: 2020/09/30 13:15:36 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guimp.h"

static inline void	r_slider(t_info *info)
{
	t_xywh	coord;

	coord = ui_init_coords(25, 50, 225, 20);
	info->r_slider = ui_create_slider(info->toolbox->window,
			coord, info->col_menu, 0, 255);
	((t_slider *)info->r_slider->info)->bar_color = 0xffff0000;
	ft_set_slider_value(info->r_slider, 127);
}

static inline void	g_slider(t_info *info)
{
	t_xywh	coord;

	coord = ui_init_coords(25, 76, 225, 20);
	info->g_slider = ui_create_slider(info->toolbox->window,
			coord, info->col_menu, 0, 255);
	((t_slider *)info->g_slider->info)->bar_color = 0xff00ff00;
	ft_set_slider_value(info->g_slider, 127);
}

static inline void	b_slider(t_info *info)
{
	t_xywh	coord;

	coord = ui_init_coords(25, 102, 225, 20);
	info->b_slider = ui_create_slider(info->toolbox->window,
			coord, info->col_menu, 0, 255);
	((t_slider *)info->b_slider->info)->bar_color = 0xff0000ff;
	ft_set_slider_value(info->b_slider, 127);
}

static inline void	a_slider(t_info *info)
{
	t_xywh	coord;

	coord = ui_init_coords(25, 154, 225, 20);
	info->a_slider = ui_create_slider(info->toolbox->window,
			coord, info->col_menu, 0, 255);
	ft_set_slider_value(info->a_slider, 255);
}

static inline void	size_slider(t_info *info)
{
	t_xywh	coord;

	coord = ui_init_coords(25, 128, 225, 20);
	info->size_slider = ui_create_slider(info->toolbox->window,
			coord, info->col_menu, 1, 100);
	ft_set_slider_value(info->size_slider, 49);
}

void				slider_init(t_info *info)
{
	r_slider(info);
	g_slider(info);
	b_slider(info);
	a_slider(info);
	size_slider(info);
}
