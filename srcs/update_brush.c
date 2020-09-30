/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_brush.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 11:54:40 by nneronin          #+#    #+#             */
/*   Updated: 2020/09/30 13:42:59 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guimp.h"

static inline void	pipette(t_info *info)
{
	SDL_Color color;

	color = hex_to_rgba(info->brush.color);
	ft_set_slider_value(info->r_slider, color.r);
	ft_set_slider_value(info->g_slider, color.g);
	ft_set_slider_value(info->b_slider, color.b);
	ft_set_slider_value(info->a_slider, color.a);
}

static inline void	color_combine(t_info *info)
{
	info->brush.color = rgb_to_hex(((t_slider *)info->r_slider->info)->value,
								((t_slider *)info->g_slider->info)->value,
								((t_slider *)info->b_slider->info)->value,
								((t_slider *)info->a_slider->info)->value);
	info->brush.shape.color = info->brush.color;
}

static inline void	while_loops(t_info *info)
{
	int	i;

	i = -1;
	while (++i < info->brush_button_amount)
		if (info->buttons[i]->state == 1)
			info->brush.type = i + 1;
	i = -1;
	while (++i < info->layer_amount)
		if (info->layer_buttons[i]->state == 1)
			info->brush.selected_layer = i;
	i = -1;
	while (++i < ((t_drop_down *)info->drop_down->info)->item_amount)
		if (((t_drop_down *)info->drop_down->info)->items[i]->state == 1)
			info->brush.selected_sticker = i;
	i = -1;
	while (++i < ((t_drop_down *)info->font_down->info)->item_amount)
		if (((t_drop_down *)info->font_down->info)->items[i]->state == 1)
			info->brush.font_dir = ft_strjoiner("libui/TTF/",
					((t_drop_down *)info->font_down->info)->items[i]->text.text,
					NULL);
	i = -1;
	while (++i < info->shapes_nbr)
		if (info->shapes[i]->state == 1)
			info->brush.shape_type = i + 1;
}

void				update_brush(t_info *info)
{
	if (info->brush.type == 8)
		pipette(info);
	else
		color_combine(info);
	info->brush.size = ((t_slider *)info->size_slider->info)->value;
	while_loops(info);
	free(info->brush.str);
	info->brush.str = ft_strdup(info->text_area->text.text);
	ft_update_background(info->brush_color->surface, info->brush.color);
}
