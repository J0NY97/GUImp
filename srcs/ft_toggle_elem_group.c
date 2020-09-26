/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toggle_elem_group.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 17:10:10 by nneronin          #+#    #+#             */
/*   Updated: 2020/09/26 17:11:02 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guimp.h"

void	ft_toggle_elem_group(SDL_Event e, t_element *elem)
{
	t_element **buttons;
	t_button	*but;
	int			*but_am;

	but = elem->info;
	but_am = but->extra;
	if (e.type == SDL_MOUSEBUTTONDOWN)
	{
		buttons = (t_element **)elem->extra_info;
		for (int i = 0; i < 5; i++)
			buttons[i]->default_state = 0;
		elem->default_state = 1;
	}
	if (e.type == SDL_MOUSEMOTION)
		elem->state = 2;
	else if (e.type == SDL_MOUSEBUTTONUP)
		elem->state = 2;
}
