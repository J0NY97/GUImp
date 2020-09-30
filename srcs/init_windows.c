/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_windows.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 17:38:29 by nneronin          #+#    #+#             */
/*   Updated: 2020/09/30 12:03:48 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guimp.h"

void	window_init(t_libui *libui, t_info *info)
{
	t_window_info new_win;

	if (!(info->toolbox = (t_win *)malloc(sizeof(t_win))))
		exit (0);
	if (!(info->main = (t_win *)malloc(sizeof(t_win))))
		exit (0);
	if (!(info->layers = (t_win *)malloc(sizeof(t_win))))
		exit (0);
	new_win.coord = ui_init_coords(0, 0, 500, 1250);
	new_win.title = ft_strdup("Toolbox");
	new_win.bg_color = 0xffd3d3d3;
	info->toolbox->window = ft_create_window(libui, new_win);
	new_win.coord = ui_init_coords(501, 0, 1000, 1250);
	new_win.title = ft_strdup("Canvas");
	new_win.bg_color = 0xffd3d3d3;
	info->main->window = ft_create_window(libui, new_win);
	new_win.coord = ui_init_coords(1502, 0, 500, 1250);
	new_win.title = ft_strdup("Layers");
	new_win.bg_color = 0xffd3d3d3;
	info->layers->window = ft_create_window(libui, new_win);
}
