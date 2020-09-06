/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_text.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 12:26:52 by nneronin          #+#    #+#             */
/*   Updated: 2020/09/06 13:31:59 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ft_read_text(t_element *elem, int size)
{
	int			t;
	int			i;
	char		*tmp;
	SDL_Event	event;

	t = 0;
	i = 0;
	SDL_PollEvent(&event);
	while (i < size && event.key.keysym.sym != SDLK_RETURN)
	{
		if (event.type == SDL_TEXTINPUT && t == 1)
		{
			if (i == 0 && (++i))
				elem->text.text = ft_strdup(event.text.text);
			else if ((++i))
			{
				tmp = ft_strdup(elem->text.text);
				ft_strdel(&elem->text.text);
				elem->text.text = ft_strjoin(tmp, event.text.text);
				free(tmp);
			}
			elem->old_state = 500;
			ui_render(elem->extra_info);
			t = 0;
		}
		else if (event.key.keysym.sym == SDLK_BACKSPACE && i != 0 && t == 1)
		{
			elem->text.text[i] = '\0';
			i -= 1;
			t = -1;
			elem->old_state = 500;
			ui_render(elem->extra_info);
		}
		SDL_PollEvent(&event);
		if (event.type == SDL_KEYDOWN && t == 0)
			t = 1;
		if (event.type == SDL_KEYUP && t == -1)
			t = 0;
	}
}
