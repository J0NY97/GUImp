/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_elem_background.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 13:29:18 by jsalmi            #+#    #+#             */
/*   Updated: 2020/09/10 13:32:00 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ft_update_elem_background(t_element *elem, Uint32 color)
{
	elem->bg_color = color;
	ft_update_background(elem->surface, color);
	ft_update_background(elem->states[0], color);
}
