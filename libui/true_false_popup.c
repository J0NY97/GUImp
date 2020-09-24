/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   true_false_popup.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 17:01:12 by nneronin          #+#    #+#             */
/*   Updated: 2020/09/19 13:20:32 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

static void		init_button(t_window *win)
{
	t_xywh coord;

	coord = ui_init_coords(50, 200, 100, 50);
	ui_create_button(win, coord, NULL);
	ft_set_text(&((t_element *)win->elements->content)->text, "OK");
	((t_element *)win->elements->content)->text.centered = 1;
	((t_element *)win->elements->content)->f = &popup_int_func;
	((t_button *)((t_element *)win->elements->content)->info)->type = 1;
	ft_update_elem_background(win->elements->content, 0xff0082c4);

	coord = ui_init_coords(200, 200, 100, 50);
	ui_create_button(win, coord, NULL);
	ft_set_text(&((t_element *)win->elements->content)->text, "CANCEL");
	((t_element *)win->elements->content)->text.centered = 1;
	((t_element *)win->elements->content)->f = &popup_int_func;
	((t_button *)((t_element *)win->elements->content)->info)->type = 0;
	ft_update_elem_background(win->elements->content, 0xffEE7f1B);
}

t_window		*init_tf_win(t_libui *libui, char *msg)
{
	t_text			text;
	t_window		*win;
	t_window_info	test;

	test.coord = ui_init_coords(0, 0, 350, 300);
	popup_coord(&test.coord.x, &test.coord.y,  350, 300);
	test.title = ft_strdup("Pop up");
	win = ft_create_window(libui, test);
	ft_update_background(win->surface, 0xffECECEC);
	init_button(win);
	text.x = 50;
	text.y = 100;
	text.margin = 50;
	text.color = 0x000000;
	text.text = ft_strdup(msg);
	text.parent = win->surface;
	text.font = TTF_OpenFont("./libui/TTF/OpenSans.ttf", 22);
	ft_create_text(&text);
	TTF_CloseFont(text.font);
	text.font = NULL;
	free(text.text);
	return (win);
}

int			true_false_popup(int x1, int y1, char *msg)
{
	int				result;
	t_list			*list;
	t_libui			*libui;
	t_window		*win;

	libui = (t_libui *)malloc(sizeof(t_libui));
	popup_sdl_init(libui);
	result = -1;
	win = init_tf_win(libui, msg);
	list = win->elements;
	while (list)
	{
		((t_element *)list->content)->extra_info = &result;
		list = list->next;
	}
	while (result == -1)
	{
		ft_event_poller(libui);
		ui_render(win);
	}
	free_libui(libui);
	return (result);
}
