/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_drop_down.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 15:42:05 by nneronin          #+#    #+#             */
/*   Updated: 2020/09/26 16:03:18 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guimp.h"

static inline void	drop_down_font(t_info *info)
{
	t_xywh			coord;

	coord = ui_init_coords(212, 200, 162, 32);
	info->font_down = ui_create_drop(info->toolbox->window, coord, info->col_menu);
	ft_set_text(&info->font_down->text, "Font select");
	info->font_down->text.x = 10;
	ft_drop_down_add_item(info->toolbox->window, info->font_down, "Jonis.ttf");
	ft_drop_down_add_item(info->toolbox->window, info->font_down, "Amatic.ttf");
	ft_drop_down_add_item(info->toolbox->window, info->font_down, "OpenSans.ttf");
	ft_drop_down_add_item(info->toolbox->window, info->font_down, "Pacifico.ttf");
	ft_drop_down_add_item(info->toolbox->window, info->font_down, "Tusj.ttf");
}

static inline void	drop_down_sticker(t_info *info)
{
	t_xywh			coord;
	SDL_Rect		temp;
	SDL_Surface		*icon;

	temp.w = 32;
	temp.h = 32;
	temp.x = 150 - temp.w;
	temp.y = 0;
	coord = ui_init_coords(25, 200, 162, 32);
	info->drop_down = ui_create_drop(info->toolbox->window, coord, info->col_menu);
	ft_set_text(&info->drop_down->text, "Sticker select");
	info->drop_down->text.x = 10;
	ft_drop_down_add_item(info->toolbox->window, info->drop_down, "Minion");
	icon = load_image("resources/stickers/icon-minion.png");
	SDL_BlitSurface(icon, NULL, ((t_drop_down *)info->drop_down->info)->items[0]->surface, &temp);
	SDL_BlitSurface(icon, NULL, ((t_drop_down *)info->drop_down->info)->items[0]->states[0], &temp);
	SDL_BlitSurface(icon, NULL, ((t_drop_down *)info->drop_down->info)->items[0]->states[1], &temp);
	SDL_FreeSurface(icon);
	ft_drop_down_add_item(info->toolbox->window, info->drop_down, "Guimp-icon");
	icon = load_image("resources/stickers/icon-gimp-icon.png");
	SDL_BlitSurface(icon, NULL, ((t_drop_down *)info->drop_down->info)->items[1]->surface, &temp);
	SDL_BlitSurface(icon, NULL, ((t_drop_down *)info->drop_down->info)->items[1]->states[0], &temp);
	SDL_BlitSurface(icon, NULL, ((t_drop_down *)info->drop_down->info)->items[1]->states[1], &temp);
	SDL_FreeSurface(icon);

}

void				drop_down_init(t_info *info)
{
	drop_down_sticker(info);
	ft_update_drop(info->drop_down);
	drop_down_font(info);
	ft_update_drop(info->font_down);
}
