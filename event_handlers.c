/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 12:26:53 by jsalmi            #+#    #+#             */
/*   Updated: 2020/08/16 17:05:48 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guimp.h"

// @TODO: when event occures loop all elements of focused window (for better performance)
// @Improvement: change info->toolbox to the current focused window, so we dont have to check all the buttons of all the windows
// 				in mouse events mousebuttondown check_button_hitbox()

void	toggle_button_group(t_window *win, t_button **buttons, t_button *curr)
{
	int ib;
	int group;

	ib = -1;
	group = curr->group;
	while (++ib <= win->button_amount)
	{
		if (curr != buttons[ib] && buttons[ib]->group == group)
		{
			buttons[ib]->state = 0;
			buttons[ib]->toggle = 0;
		}
	}
}

void	check_button_hitbox(t_window *win, int x, int y, int state)
{
	int ib;

	ib = 0;
	while (ib <= win->button_amount)
	{
		if ((y >= win->buttons[ib]->y && y <= win->buttons[ib]->y + win->buttons[ib]->surface->h) &&
			(x >= win->buttons[ib]->x && x <= win->buttons[ib]->x + win->buttons[ib]->surface->w))
		{
			if (win->buttons[ib]->toggle >= 0)
			{
				if (state == 2)
					win->buttons[ib]->toggle = win->buttons[ib]->toggle != 1;
				if (win->buttons[ib]->toggle == 0)
					win->buttons[ib]->state = state;
				else
				{
					win->buttons[ib]->state = 2;
					toggle_button_group(win, win->buttons, win->buttons[ib]);
					win->buttons[ib]->f(win->buttons[ib]);
				}
				return ;
			}
			win->buttons[ib]->state = state;
			state == 2 ? win->buttons[ib]->f(win->buttons[ib]) : 0;
			return;
		}
		if (win->buttons[ib]->toggle == -1 || win->buttons[ib]->toggle == 0)
			win->buttons[ib]->state = 0;
		ib++;
	}
}

void	draw(t_info *info, t_window *win, int x, int y)
{
	t_surface *surf;
	int xd;
	int yd;

	surf = win->surfaces[0];
	x = x - surf->x - (info->brush.size / 2);
	y = y - surf->y - (info->brush.size / 2);
	if (info->brush.type == 2) // square brush
	{	
		yd = -1;
		while (++yd < info->brush.size)
		{
			xd = -1;
			while (++xd < info->brush.size)
			{
				set_pixel(surf->surface, x + xd, y + yd, 0x000000);
			}
		}
	}
}

void	mouse_events(t_info *info, SDL_Event event)
{
	if (event.type == SDL_MOUSEMOTION)
	{
		//printf("Mouse is at %d, %d\n", event.motion.x, event.motion.y);
		if (event.window.windowID == info->toolbox->id)
			check_button_hitbox(info->toolbox, event.button.x, event.button.y, 1);
		else if (event.window.windowID == info->main->id)
		{
			check_button_hitbox(info->main, event.button.x, event.button.y, 1);
		}
	}
	else if (event.type == SDL_MOUSEBUTTONDOWN)
	{
		printf("mouse clicked\n");
		// when mouse clicked loop aill the buttons of that window and check if you clicked them
		if (event.window.windowID == info->toolbox->id)
			check_button_hitbox(info->toolbox, event.button.x, event.button.y, 2);
		else if (event.window.windowID == info->main->id)
		{
			check_button_hitbox(info->main, event.button.x, event.button.y, 2);
			info->draw = 1;
		}
	}
	else if (event.type == SDL_MOUSEBUTTONUP)
	{
		printf("mouse unclicked\n");
		if (event.window.windowID == info->toolbox->id)
			check_button_hitbox(info->toolbox, event.button.x, event.button.y, 1);
		else if (event.window.windowID == info->main->id)
		{
			info->draw = 0;
			check_button_hitbox(info->main, event.button.x, event.button.y, 1);
		}
	}
	if (info->draw == 1)
		draw(info, info->main, event.button.x, event.button.y);
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
