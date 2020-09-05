/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_create_surface.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 16:06:38 by jsalmi            #+#    #+#             */
/*   Updated: 2020/09/05 11:13:36 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

t_element	*ui_create_surface(t_window *win, t_xywh coord)
{
	t_element_info	info;
	t_element		*elem;

	info = ft_default_elem_info(win, coord);
	info.info = (t_surface *)malloc(sizeof(t_surface));
	info.info_size = 0; // remove in later iteration
	elem = ft_create_element(info);
	ft_add_element_to_window_elements(win, elem);
	return (elem);
}
