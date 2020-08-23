/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_text.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 12:26:52 by nneronin          #+#    #+#             */
/*   Updated: 2020/08/23 11:17:00 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

char	*ft_read_text(int size)
{
	int			i;
	char		*key;
	char		*tmp;
	char		*text;
	SDL_Event	event;

	i = 0;
	SDL_PollEvent(&event);
	while (event.key.keysym.sym != SDLK_RETURN)
	{
		if (event.type == SDL_KEYDOWN)
		{
			key = ft_strdup(SDL_GetKeyName(event.key.keysym.sym));
			if (key[1] == '\0' || event.key.keysym.sym == SDLK_SPACE)
			{
				if (i == 0 && (++i))
					text = ft_strdup(key);
				else if ((++i))
				{
					tmp = ft_strdup(text);
					ft_strdel(&text);
					text = ft_strjoin(tmp, key[1] != '\0' ? " " : key);
					ft_strdel(&tmp);
				}
			}
			ft_strdel(&key);
		}
		SDL_PollEvent(&event);
	}
//	write(1, text, i); //Remove later.
	free(key);
	free(tmp);
	return (text);
}
