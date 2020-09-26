/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_brush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 18:14:18 by nneronin          #+#    #+#             */
/*   Updated: 2020/09/26 18:15:06 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guimp.h"

void		init_brush(t_info *info)
{
	info->brush.aspect_y = 1;
	info->brush.aspect_x = 1;
	info->brush.zoom = 0;
	info->brush.font_dir = ft_strdup("font.ttf");
	info->brush.draw = 0;
	info->brush.type = 1;
	info->brush.size = 20;
	info->brush.color = 0xffd3d3d3;
	info->brush.shape.x2 = -1;
	info->brush.shape.y2 = -1;
	info->brush.str = NULL;
	info->brush.selected_sticker = 0;
}
