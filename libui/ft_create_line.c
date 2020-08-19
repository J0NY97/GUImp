/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 11:25:55 by nneronin          #+#    #+#             */
/*   Updated: 2020/08/19 12:51:29 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

static inline void	line_calc(t_line *l)
{
	l->pytha = sqrt(((l->x2 - l->x1) * 2) + ((l->y2 - l->y1) * 2));
	l->cath_x = (l->y2 - l->y1) < 0 ? (l->y2 - l->y1) * -1 : (l->y2 - l->y1);
	l->cath_y = (l->x2 - l->x1) < 0 ? (l->x2 - l->x1) * -1 : (l->x2 - l->x1);
	l->x = l->x1 < l->x2 ? 1 : -1;
	l->y = l->y1 < l->y2 ? 1 : -1;
}

void	ft_create_line(SDL_Surface *surf, Uint32 color, t_line *l)
{
	line_calc(l);
	l->overflow_y = l->cath_y - l->cath_x;
	while (l->x1 != l->x2 || l->y1 != l->y2)
	{
		set_pixel(surf, l->x1, l->y1, color);
		l->overflow_x = l->overflow_y * 2;
		if (l->overflow_x > -(l->cath_x))
		{
			l->overflow_y -= l->cath_x;
			l->x1 += l->x;
		}
		else if (l->overflow_x < l->cath_x)
		{
			l->overflow_y += l->cath_y;
			l->y1 += l->y;
		}
	}
}
