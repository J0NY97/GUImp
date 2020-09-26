/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_button_init.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 16:55:56 by nneronin          #+#    #+#             */
/*   Updated: 2020/09/26 18:12:34 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guimp.h"

void	shape_buttons_init(t_info *info)
{
	int i;
	t_xywh coord;

	i = -1;
	coord = ui_init_coords(25, 25, 100, 50);
	info->shapes[0] = ui_create_button(info->toolbox->window, coord, info->shape_menu);
	ft_set_element_image(info->shapes[0], info->shape_img.orb);
	info->shapes[0]->default_state = 1;

	coord = ui_init_coords(150, 25, 100, 50);
	info->shapes[1] = ui_create_button(info->toolbox->window, coord, info->shape_menu);
	ft_set_element_image(info->shapes[1], info->shape_img.square);

	coord = ui_init_coords(275, 25, 100, 50);
	info->shapes[2] = ui_create_button(info->toolbox->window, coord, info->shape_menu);
	ft_set_element_image(info->shapes[2], info->shape_img.tube);

	info->shapes_nbr = 3;
	while (++i < info->shapes_nbr)
	{
		info->shapes[i]->f = &ft_toggle_elem_group;
		info->shapes[i]->extra_info = info->shapes;
		((t_button *)info->shapes[i]->info)->extra = &info->shapes_nbr;
		info->shapes[i]->text.centered = 1;
		ft_update_element(info->shapes[i]);
	}
}
