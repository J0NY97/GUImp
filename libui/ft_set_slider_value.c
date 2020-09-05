/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_slider_value.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 17:00:09 by jsalmi            #+#    #+#             */
/*   Updated: 2020/09/05 17:09:25 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ft_set_slider_value(t_element *elem, int new_value)
{
	t_slider	*slider;
	int			bar_x;

	slider = elem->info;
	slider->value = new_value;
	bar_x = ((float)elem->coord.w / (slider->max - slider->min)) * slider->value;
	ft_update_slider_bar(bar_x + elem->coord.x, 0, elem);
}
