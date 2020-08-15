/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_button.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 12:07:14 by jsalmi            #+#    #+#             */
/*   Updated: 2020/08/15 14:20:01 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

int			ft_create_button(t_button_info info)
{
	t_button *new_button;
	if (!(new_button = (t_button *)malloc(sizeof(t_button))))
		ft_putstr("[create_button] Couldnt malloc new button.\n");
	new_button->surface = SDL_CreateRGBSurface(0, info.w, info.h, 32, 0, 0, 0, 0);
	new_button->f = info.f;
	new_button->x = info.x;
	new_button->y = info.y;
	new_button->font = info.font;
	new_button->state = info.state;
	new_button->text = ft_strdup(info.text);
	ft_strdel(&info.text);
	free(info.text);
	info.win->buttons[++info.win->button_amount] = new_button;
	
	ft_update_button(new_button, 0xffffff, 0x00ff00);	
	return (1);
}
