/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event_poller.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 15:16:58 by jsalmi            #+#    #+#             */
/*   Updated: 2020/08/29 18:26:50 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ft_event_poller(t_libui *libui)
{
	SDL_PollEvent(&libui->event);
	if (libui->event.type == SDL_QUIT)
	{
		if (pop_up(0, 0, "Are you sure you want to quit?"))
			exit(1);
	}
	if (libui->event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
		exit (1);
}
