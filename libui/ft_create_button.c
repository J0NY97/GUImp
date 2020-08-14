/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_button.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 12:07:14 by jsalmi            #+#    #+#             */
/*   Updated: 2020/08/14 13:23:14 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void		click(void)
{
	ft_putstr("button clicked");
}

t_button	*ft_create_button(t_button_info info)
{
	t_button *new_button;
	if (!(new_button = (t_button *)malloc(sizeof(t_button))))
		ft_putstr("[create_button] Couldnt malloc new button.\n");
	new_button->surface = SDL_CreateRGBSurface(0, info.w, info.h, 32, 0, 0, 0, 0);
	new_button->f = &click;
	return (new_button);
}
