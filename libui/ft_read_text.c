/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_text.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 12:26:52 by nneronin          #+#    #+#             */
/*   Updated: 2020/09/16 11:35:05 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ft_read_text(t_element *elem, int size)
{
	int			key_state;
	int			char_nbr;
	char		*tmp;
	SDL_Event	event;

	key_state = 0;
	char_nbr = 0;
	SDL_PollEvent(&event);
	while (char_nbr < size && event.key.keysym.sym != SDLK_RETURN)
	{
		if (event.type == SDL_TEXTINPUT && key_state == 1)
		{
			if (char_nbr == 0 && (++char_nbr))
				elem->text.text = ft_strdup(event.text.text);
			else if ((++char_nbr))
			{
				tmp = ft_strdup(elem->text.text);
				ft_strdel(&elem->text.text);
				elem->text.text = ft_strjoin(tmp, event.text.text);
				free(tmp);
			}
			ui_render(elem->extra_info);
			key_state = 0;
		}
		else if (event.key.keysym.sym == SDLK_BACKSPACE && char_nbr != 0 && key_state == 1)
		{
			elem->text.text[char_nbr] = '\0';
			char_nbr -= 1;
			key_state = -1;
			ui_render(elem->extra_info);
		}
		SDL_PollEvent(&event);
		if (event.type == SDL_KEYDOWN && key_state == 0)
			key_state = 1;
		if (event.type == SDL_KEYUP && key_state == -1)
			key_state = 0;
	}
}
