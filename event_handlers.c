/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 12:26:53 by jsalmi            #+#    #+#             */
/*   Updated: 2020/08/15 14:16:28 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guimp.h"

// @TODO: when event occures loop all elements of focused window (for better performance)
// @Improvement: change info->toolbox to the current focused window, so we dont have to check all the buttons of all the windows
// 				in mouse events mousebuttondown check_button_hitbox()

void	check_button_hitbox(t_window *win, int x, int y, int state)
{
	int ib;

	ib = 0;
	while (ib <= win->button_amount)
	{
		if ((y >= win->buttons[ib]->y && y <= win->buttons[ib]->y + win->buttons[ib]->surface->h) &&
			(x >= win->buttons[ib]->x && x <= win->buttons[ib]->x + win->buttons[ib]->surface->w))
		{
			win->buttons[ib]->state = state;
			state == 2 ? win->buttons[ib]->f() : 0;
			return;
		}
		win->buttons[ib]->state = 0;
		ib++;
	}
}

void	mouse_events(t_info *info, SDL_Event event)
{
	if (event.type == SDL_MOUSEMOTION)
	{
		printf("Mouse is at %d, %d\n", event.motion.x, event.motion.y);
		check_button_hitbox(info->toolbox, event.button.x, event.button.y, 1);
	}
	else if (event.type == SDL_MOUSEBUTTONDOWN)
	{
		printf("mouse clicked\n");
		// when mouse clicked loop aill the buttons of that window and check if you clicked them
		check_button_hitbox(info->toolbox, event.button.x, event.button.y, 2);
	}
	else if (event.type == SDL_MOUSEBUTTONUP)
	{
		printf("mouse unclicked\n");
		check_button_hitbox(info->toolbox, event.button.x, event.button.y, 1);
	}
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
