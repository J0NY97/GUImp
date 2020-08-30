/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_init_coords.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 16:48:12 by jsalmi            #+#    #+#             */
/*   Updated: 2020/08/30 16:49:10 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

t_xywh	ui_init_coords(int x, int y, int w, int h)
{
	t_xywh coords;

	coords.x = x;
	coords.y = y;
	coords.w = w;
	coords.h = h;
	return (coords);
}
