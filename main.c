/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 12:48:16 by jsalmi            #+#    #+#             */
/*   Updated: 2020/08/15 15:56:46 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guimp.h"

void	ft_error(char *msg)
{
	ft_putstr("\x1b[31m[Error] \x1b[0m");
	ft_putstr(msg);
	ft_putstr("\n");
	exit(1);
}

void	render(t_window *win)
{
	SDL_Rect	temp;
	// add buttons to  sruface
//	printf("%d %d %d %d", win->buttons[0]->x, win->buttons[0]->y, win->buttons[0]->surface->w, win->buttons[0]->surface->h);
	set_pixel(win->buttons[0]->surface, 10, 10, 0xffffff);
	set_pixel(win->surface, 250, 500, 0xffffff);
	for (int i = 0; i <= win->button_amount; i++)
	{
		temp.x = win->buttons[i]->x;
		temp.y = win->buttons[i]->y;
		temp.w = win->buttons[i]->surface->w;
		temp.h = win->buttons[i]->surface->h;
		SDL_BlitSurface(win->buttons[i]->surface, NULL, win->surface, &temp);
	}
	// add elemsnets to surafce
	// otherthings....
	SDL_UpdateWindowSurface(win->win);
}

// @Improvement: updatese all the buttons independent if the button was actually updated
// @fix: now only checks toolbox window buttons
void	update_buttons(t_info *info)
{
	int ib;

	ib = -1;
	while (++ib <= info->toolbox->button_amount)
	{
		if (info->toolbox->buttons[ib]->state == 0)
			ft_update_button(info->toolbox->buttons[ib], 0xffffff, 0x00ff00);
		else if (info->toolbox->buttons[ib]->state == 1)
			ft_update_button(info->toolbox->buttons[ib], 0xff00ff, 0x000000);
		else if (info->toolbox->buttons[ib]->state == 2)
			ft_update_button(info->toolbox->buttons[ib], 0xffff00, 0x000000);
	}
}

void	click(void)
{
	printf("this butotn was clicked\n");
}

int		main(void)
{
	t_info *info;

	ft_test_libui();
	if (!(info = (t_info *)malloc(sizeof(t_info))))
		ft_error("Couldnt mallco t_info.");
	SDL_Init(SDL_INIT_VIDEO);
	TTF_Init();
	// SDL_Image_Init();

	// Init();
	info->run = 1;
	info->font = TTF_OpenFont("font.ttf", 32);
	//
	t_window_info toolbox;
	toolbox.x = 0;
	toolbox.y = 0;
	toolbox.w = 500;
	toolbox.h = 1250;
	toolbox.flags = 0;
	toolbox.resizeable = 1;
	toolbox.title = ft_strdup("toolbox");
	info->toolbox = ft_create_window(toolbox);

	t_button_info button;

	button.x = 0;
	button.y = 9;
	button.w = 100;
	button.h = 50;
	button.text = ft_strdup("click me!");
	button.font = info->font;
	button.win = info->toolbox;
	button.f = &click;
	button.state = 0;
	button.toggle = -1;
	ft_create_button(button);

	button.x = 125;
	button.y = 9;
	button.text = ft_strdup("me too!");
	button.toggle = -1;
	ft_create_button(button);
	
	button.x = 125;
	button.y = 100;
	button.w = 200;
	button.h = 100;
	button.toggle = 1;
	button.text = ft_strdup("me three!");
	ft_create_button(button);
	
	while (info->run)
	{
		event_handler(info);
		update_buttons(info);
		render(info->toolbox);
	}
	return (0);
}
