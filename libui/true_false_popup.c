/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   true_false_popup.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 17:01:12 by nneronin          #+#    #+#             */
/*   Updated: 2020/09/13 18:49:56 by nneronin         ###   ########.fr       */
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

int			true_false_popup(int x1, int y1, char *msg)
{
	t_window_info	test;
	t_window		*win;
	t_libui			*libui;
	t_element		*buttons[2];

	libui = (t_libui *)malloc(sizeof(t_libui));
	ui_libui_init(libui);
	test.coord = ui_init_coords(0, 0, 350, 300);
	test.title = ft_strdup("Pop_up");
	win = ft_create_window(libui, test);
	ft_update_background(win->surface, 0xffECECEC);
	int result;
	t_xywh coord;

	result = -1;
	coord = ui_init_coords(50, 200, 100, 50);
	buttons[0] = ui_create_button(win, coord, NULL);
	buttons[0]->text.text = ft_strdup("OK");
	buttons[0]->text.centered = 1;
	buttons[0]->f = &button;
	((t_button *)buttons[0]->info)->type = 1;
	buttons[0]->extra_info = &result;
	buttons[0]->old_state = 500;
	ft_update_background(buttons[0]->states[0], 0xff0082c4);

	coord = ui_init_coords(200, 200, 100, 50);
	buttons[1] = ui_create_button(win, coord, NULL);
	buttons[1]->text.text = ft_strdup("CANCEL");
	buttons[1]->text.centered = 1;
	buttons[1]->f = &button;
	((t_button *)buttons[1]->info)->type = 0;
	buttons[1]->extra_info = &result;
	buttons[1]->old_state = 500;
	ft_update_background(buttons[1]->states[0], 0xffEE7f1B);

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
