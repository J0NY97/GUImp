/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   popup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 14:01:15 by nneronin          #+#    #+#             */
/*   Updated: 2020/09/03 16:35:44 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void		button(SDL_Event e, t_element *elem)
{
	int *result;

	result = elem->extra_info;
	if (e.type == SDL_MOUSEBUTTONDOWN)
		*result = ((t_button *)elem->info)->type;
}

void		text_area(SDL_Event e, t_element *elem)
{
	if (e.type == SDL_MOUSEBUTTONDOWN)
	{
		free(elem->text.text);
		ft_read_text(elem, 20);
	}
}

char		*input_popup(int x1, int y1)
{
	t_window		*win;
	t_window_info	test;
	t_libui *libui;
	t_element *buttons[2];

	libui = (t_libui *)malloc(sizeof(t_libui));
	ui_libui_init(libui);
	test.coord = ui_init_coords(0, 0, 350, 300);
	test.title = ft_strdup("Pop_up");
	win = ft_create_window(libui, test);
	ft_update_background(win->surface, 0xECECEC);

	int result;
	t_xywh coord;

	result = -1;
	coord = ui_init_coords(50, 200, 100, 50);
	buttons[0] = ui_create_button(win, coord);
	buttons[0]->text.text = ft_strdup("OK");
	buttons[0]->text.x = 25;
	buttons[0]->text.y = 0;
	buttons[0]->f = &button;
	((t_button *)buttons[0]->info)->type = 1;
	buttons[0]->extra_info = &result;
	buttons[0]->old_state = 500;
	ft_update_background(buttons[0]->states[0], 0x0082c4);

	coord = ui_init_coords(50, 100, 250, 50);
	buttons[1] = ui_create_button(win, coord);
	buttons[1]->text.text = ft_strdup("Input");
	buttons[1]->text.parent = win->surface;
	buttons[1]->set_text = 1;
	buttons[1]->f = &text_area;
	buttons[1]->old_state = 500;
	buttons[1]->extra_info = win->win;

	ft_update_element(buttons[0]);
	ft_update_element(buttons[1]);

	while (result == -1)
	{
		ui_render(win);
		ft_event_poller(libui);
	}
	SDL_DestroyWindow(win->win);
	free(win);
	char *str;
	str = ft_strdup(buttons[1]->text.text);
	free(win);
	free(buttons[0]);
	free(buttons[1]);
	free(libui);
	return (str);
}

int			true_false_popup(int x1, int y1, char *msg)
{
	t_window		*win;
	t_window_info	test;
	t_libui			*libui;
	t_element *buttons[2];

	libui = (t_libui *)malloc(sizeof(t_libui));
	ui_libui_init(libui);
	test.coord = ui_init_coords(0, 0, 350, 300);
	test.title = ft_strdup("Pop_up");
	win = ft_create_window(libui, test);
	ft_update_background(win->surface, 0xECECEC);
	int result;
	t_xywh coord;

	result = -1;
	coord = ui_init_coords(50, 200, 100, 50);
	buttons[0] = ui_create_button(win, coord);
	buttons[0]->text.text = ft_strdup("OK");
	buttons[0]->text.x = 15;
	buttons[0]->text.y = 5;
	buttons[0]->f = &button;
	((t_button *)buttons[0]->info)->type = 1;
	buttons[0]->extra_info = &result;
	buttons[0]->old_state = 500;
	ft_update_background(buttons[0]->states[0], 0x0082c4);

	coord = ui_init_coords(200, 200, 100, 50);
	buttons[1] = ui_create_button(win, coord);
	buttons[1]->text.text = ft_strdup("CANCEL");
	buttons[1]->text.x = 5;
	buttons[1]->text.y = 5;
	buttons[1]->f = &button;
	((t_button *)buttons[1]->info)->type = 0;
	buttons[1]->extra_info = &result;
	buttons[1]->old_state = 500;
	ft_update_background(buttons[1]->states[0], 0xEE7f1B);

	ft_update_element(buttons[0]);
	ft_update_element(buttons[1]);
	t_text text;

	text.x = 50;
	text.y = 100;
	text.margin = 50;
	text.color = 0x000000;
	text.text = ft_strdup(msg);
	text.parent = win->surface;
	text.font = TTF_OpenFont("./libui/TTF/OpenSans.ttf", 22);
	ft_create_text(&text);
	free(text.text);
	TTF_CloseFont(text.font);
	text.font = NULL;

	ui_render(win);
	while (result == -1)
		ft_event_poller(libui);


	free_element(buttons[1]);
	free_element(buttons[0]);
	free_window(win);

	free(libui->windows);
	free(libui->hotkeys);
	free(libui);
	return (0);
}
