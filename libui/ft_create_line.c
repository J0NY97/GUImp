/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 11:25:55 by nneronin          #+#    #+#             */
/*   Updated: 2020/09/26 13:56:32 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

static inline void	line_calc(t_shapes *l, t_shapes *c,
		int *cath_x, int *cath_y)
{
	c->fill = 0;
	c->size = l->size;
	*cath_x = (l->y1 - l->y2) < 0 ? (l->y1 - l->y2) * -1 : (l->y1 - l->y2);
	*cath_y = (l->x1 - l->x2) < 0 ? (l->x1 - l->x2) * -1 : (l->x1 - l->x2);
}

void				ft_create_line(SDL_Surface *surf, Uint32 color, t_shapes l)
{
	t_shapes	c;
	int			cath_x;
	int			cath_y;
	int			overflow_x;
	int			overflow_y;

	line_calc(&l, &c, &cath_x, &cath_y);
	overflow_y = cath_y - cath_x;
	while (l.x2 != l.x1 || l.y2 != l.y1)
	{
		c.x1 = l.x2;
		c.y1 = l.y2;
		ft_create_circle(surf, color, c);
		overflow_x = overflow_y * 2;
		if (overflow_x > -(cath_x))
		{
			overflow_y -= cath_x;
			l.x2 += l.x2 < l.x1 ? 1 : -1;
		}
		else if (overflow_x < cath_x)
		{
			overflow_y += cath_y;
			l.y2 += l.y2 < l.y1 ? 1 : -1;
		}
	}
}
