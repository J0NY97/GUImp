/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 12:26:53 by jsalmi            #+#    #+#             */
/*   Updated: 2020/08/14 16:03:29 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guimp.h"

// @TODO: when event occures loop all elements of focused window (for better performance)

void	mouse_events(t_info *info, SDL_Event event)
{
	if (event.type == SDL_MOUSEMOTION)
		printf("Mouse is at %d, %d\n", event.motion.x, event.motion.y);
	else if (event.type == SDL_MOUSEBUTTONDOWN)
		printf("mouse clicked\n");
	else if (event.type == SDL_MOUSEBUTTONUP)
		printf("mouse unclicked\n");
}

void	keyboard_events(t_info *info, SDL_Event event)
{
	if (event.type == SDL_KEYDOWN)
		printf("%s key was pressed\n", SDL_GetScancodeName(event.key.keysym.scancode));
	else if (event.type == SDL_KEYUP)
		printf("key unpressed.\n");
}

void	event_handler(t_info *info)
{
	// @Improvement: this could probably be in the info
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT || event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
			exit (1);	
		else if (event.type == SDL_MOUSEMOTION || event.type == SDL_MOUSEBUTTONDOWN || event.type == SDL_MOUSEBUTTONUP)
			mouse_events(info, event);
		else if (event.type == SDL_KEYDOWN || event.type == SDL_KEYUP)
			keyboard_events(info, event);
	}
}
