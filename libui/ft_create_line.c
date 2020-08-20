/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 11:25:55 by nneronin          #+#    #+#             */
/*   Updated: 2020/08/20 18:57:23 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	cross(SDL_Surface *surf, int x, int y, int size, int color)
{
	int a;

	if (size <= 2)
		set_pixel(surf, x, y, color);
	a = x - size;
	while (++a <= size + x)
		set_pixel(surf, a, y, color);
	a = y - size;
	while (++a <= size + y)
		set_pixel(surf, x, a, color);
}

static inline void	line_calc(t_line *l)
{
	l->cath_x = (l->y2 - l->y1) < 0 ? (l->y2 - l->y1) * -1 : (l->y2 - l->y1);
	l->cath_y = (l->x2 - l->x1) < 0 ? (l->x2 - l->x1) * -1 : (l->x2 - l->x1);
	l->x = l->x1 < l->x2 ? 1 : -1;
	l->y = l->y1 < l->y2 ? 1 : -1;
}

void	ft_create_line(SDL_Surface *surf, Uint32 color, int size, t_line *l)
{
	t_circle c;

	c.r = size;
	line_calc(l);
	color = color;
	l->overflow_y = l->cath_y - l->cath_x;
	while (l->x1 != l->x2 || l->y1 != l->y2)
	{
		c.xc = l->x1;
		c.yc = l->y1;
		//if (size <= 2)
		//	set_pixel(surf, l->x1 , l->y1, color);
		//else
		ft_create_circle(surf, color, c, 0);
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
