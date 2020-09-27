/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_icons.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 17:19:54 by nneronin          #+#    #+#             */
/*   Updated: 2020/09/27 12:38:14 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guimp.h"

void	shape_load(t_info *info)
{
	info->shape_img.orb = load_image("resources/tooltips/orb.bmp");
	info->shape_img.square = load_image("resources/tooltips/square.bmp");
	info->shape_img.tube = load_image("resources/tooltips/tube.bmp");
}

void	tooltips_load(t_info *info)
{
	info->tooltips.pipette = load_image("resources/tooltips/pipette.bmp");
	info->tooltips.move = load_image("resources/tooltips/move.bmp");
	info->tooltips.sticker = load_image("resources/tooltips/sticker.bmp");
	info->tooltips.circle = load_image("resources/tooltips/circle.bmp");
	info->tooltips.deletion = load_image("resources/tooltips/delete.bmp");
	info->tooltips.flood = load_image("resources/tooltips/flood.bmp");
	info->tooltips.shapes = load_image("resources/tooltips/shapes.bmp");
}

void	sticker_load(t_info *info)
{
	info->brush.stickers[0] = load_image("resources/stickers/minion.png");
	info->brush.stickers[1] = load_image("resources/stickers/gimp-icon.png");
}
