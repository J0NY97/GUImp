/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 11:25:55 by nneronin          #+#    #+#             */
/*   Updated: 2020/08/19 12:48:05 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct	s_line_algo
{
	int			x;
	int			y;
	int			x1;
	int			y1;
	int			x2;
	int			y2;
	int			cath_x;
	int 		cath_y;
	int			overflow_x;
	int			overflow_y;
	double		pytha;

}				t_line_algo;

#include "libui.h"

static inline void	line_calc(t_line_algo *l)
{
	l->pytha = sqrt(((l->x2 - l->x1) * 2) + ((l->y2 - l->y1) * 2));
	l->cath_x = (l->y2 - l->y1) < 0 ? (l->y2 - l->y1) * -1 : (l->y2 - l->y1);
	l->cath_y = (l->x2 - l->x1) < 0 ? (l->x2 - l->x1) * -1 : (l->x2 - l->x1);
	l->x = l->x1 < l->x2 ? 1 : -1;
	l->y = l->y1 < l->y2 ? 1 : -1;
}

void	ft_create_line(SDL_Surface *surf, Uint32 color, t_line_algo *l)
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
