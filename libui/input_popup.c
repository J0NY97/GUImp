/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   popup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 14:01:15 by nneronin          #+#    #+#             */
/*   Updated: 2020/09/05 19:00:57 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

static void		button(SDL_Event e, t_element *elem)
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
		ft_read_text(elem, 19);
	}
}

static void		init_button(t_window *win, t_element *buttons[2])
{
	t_xywh coord;

	coord = ui_init_coords(50, 200, 100, 50);
	buttons[0] = ui_create_button(win, coord, NULL); // NIKLAS, sista parametern is parenten for elementen
	buttons[0]->text.text = ft_strdup("OK");
	buttons[0]->text.centered = 1;
	buttons[0]->f = &button;
	((t_button *)buttons[0]->info)->type = 1;
	buttons[0]->old_state = 500;
	ft_update_background(buttons[0]->states[0], 0x0082c4);

	coord = ui_init_coords(200, 200, 100, 50);
	buttons[1] = ui_create_button(win, coord, NULL);
	buttons[1]->text.text = ft_strdup("CANCEL");
	buttons[1]->text.centered = 1;
	buttons[1]->f = &button;
	((t_button *)buttons[1]->info)->type = 0;
	buttons[1]->old_state = 500;
	ft_update_background(buttons[1]->states[0], 0xEE7f1B);

	coord = ui_init_coords(50, 100, 250, 50);
	buttons[2] = ui_create_button(win, coord, NULL);
	buttons[2]->text.text = ft_strdup("Input");
	buttons[2]->text.y = 10;
	buttons[2]->text.x = 10;
	buttons[2]->text.parent = win->surface;
	buttons[2]->set_text = 1;
	buttons[2]->f = &text_area;
	buttons[2]->old_state = 500;
	buttons[2]->extra_info = win->win;

	ft_update_element(buttons[0]);
	ft_update_element(buttons[1]);
	ft_update_element(buttons[2]);

}

char		*input_popup(int x1, int y1)
{
	int				result;
	char			*str;
	t_libui			*libui;
	t_element		*buttons[3];
	t_window		*win;
	t_window_info	test;

	libui = (t_libui *)malloc(sizeof(t_libui));
	ui_libui_init(libui);
	test.coord = ui_init_coords(0, 0, 350, 300);
	test.title = ft_strdup("~Pop~Up~");
	win = ft_create_window(libui, test);
	ft_update_background(win->surface, 0xECECEC);
	result = -1;
	init_button(win, buttons);
	buttons[0]->extra_info = &result;
	buttons[1]->extra_info = &result;
	while (result == -1)
	{
		ui_render(win);
		ft_event_poller(libui);
	}


	if (result == 1)
		str = ft_strdup(buttons[1]->text.text);
	else
		str = NULL; //cant be NULL
	free_element(buttons[1]);
	free_element(buttons[0]);
	free_window(win);
	free(libui->windows);
	free(libui->hotkeys);
	free(libui);
	return (str);
}