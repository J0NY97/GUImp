/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_slider.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 11:18:09 by jsalmi            #+#    #+#             */
/*   Updated: 2020/09/05 13:13:42 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

t_element	*ui_create_slider(t_window *win, t_xywh rel_coord, int min, int max)
{
	t_element_info	info;
	t_element		*elem;

	info = ft_default_elem_info(win, rel_coord);
	info.f = &ft_slider_function;
	info.info = (t_slider *)malloc(sizeof(t_slider));
	info.info_size = 0; // this probably shouldnt be removed, someone who wants to make a custom element can do that using the create_elem()
	info.set_text = 0;
	info.text = ft_default_text(NULL); // This may not be needed
	if ((elem = ft_create_element(info)) == NULL)
		ft_putstr("Slider coulndt be created!\n");
	ft_add_element_to_window_elements(win, elem);
	// slider specific info
	{
		((t_slider *)elem->info)->min = min;
		((t_slider *)elem->info)->max = max;
		((t_slider *)elem->info)->value = (max - min) / 2;
		((t_slider *)elem->info)->bar_color = 0xd3d3d3;
	}
	int p = ((float)elem->rel_coord.w / (max - min)) * ((t_slider *)elem->info)->value;
	ft_update_slider_bar(p + elem->rel_coord.x, elem->rel_coord.y, elem);
	return (elem);
}
