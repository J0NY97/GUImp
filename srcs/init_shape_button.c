/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_button_init.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 16:55:56 by nneronin          #+#    #+#             */
/*   Updated: 2020/09/30 14:39:58 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guimp.h"

static inline void	orb(t_info *info)
{
	info->shapes[0] = ui_create_button(info->toolbox->window,
			ui_init_coords(25, 25, 100, 50), info->shape_menu);
	ft_set_element_image(info->shapes[0], info->shape_img.orb);
}

static inline void	square(t_info *info)
{
	info->shapes[1] = ui_create_button(info->toolbox->window,
			ui_init_coords(150, 25, 100, 50), info->shape_menu);
	ft_set_element_image(info->shapes[1], info->shape_img.square);
}

static inline void	tube(t_info *info)
{
	info->shapes[2] = ui_create_button(info->toolbox->window,
			ui_init_coords(275, 25, 100, 50), info->shape_menu);
	ft_set_element_image(info->shapes[2], info->shape_img.tube);
}

void	shape_buttons_init(t_info *info)
{
	int		i;

	i = -1;
	orb(info);
	square(info);
	tube(info);
	info->shapes[0]->default_state = 1;
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
