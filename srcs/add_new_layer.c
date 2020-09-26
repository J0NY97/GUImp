/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_new_layer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 18:01:56 by nneronin          #+#    #+#             */
/*   Updated: 2020/09/26 18:03:04 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guimp.h"

void	add_new_layer(SDL_Event e, t_element *elem)
{
	t_xywh		coords;
	int			*layer_amount;

	layer_amount = elem->extra_info;
	if (e.type == SDL_MOUSEBUTTONDOWN)
	{
		if (*layer_amount == 5)
		{
			ft_putstr("Maximum layers created.");
			return ;
		}
		*layer_amount += 1;
		ft_printf("Layer_amount %d\n", *layer_amount);
	}
}
