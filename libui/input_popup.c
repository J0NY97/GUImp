/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   popup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 14:01:15 by nneronin          #+#    #+#             */
/*   Updated: 2020/09/17 16:43:00 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

char	*ft_strndup(const char *s1, ssize_t len)
{
	ssize_t	counter;
	char	*sdest;

	counter = 0;
	if (!(sdest = (char *)ft_memalloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (s1[counter] != '\0' && counter < len)
	{
		sdest[counter] = s1[counter];
		counter++;
	}
	sdest[counter] = '\0';
	return (sdest);
}

void		text_area(SDL_Event e, t_element *elem)
{
	char		*tmp;

	if (e.type == SDL_MOUSEBUTTONDOWN && elem->loop != 1)
	{
		elem->loop = 1;
		free(elem->text.text);
		elem->text.text = ft_strdup("<-");
	}
	else if (e.type == SDL_TEXTINPUT)
	{
		tmp = ft_strndup(elem->text.text, (ft_strlen(elem->text.text) - 2));
		ft_strdel(&elem->text.text);
		elem->text.text = ft_strjoiner(tmp, e.text.text, "<-");
		free(tmp);
	}
	else if (elem->loop == 1 && e.key.keysym.sym == SDLK_BACKSPACE && e.type == SDL_KEYDOWN)
	{
		tmp = ft_strndup(elem->text.text, (ft_strlen(elem->text.text) - 3));
		ft_strdel(&elem->text.text);
		elem->text.text = ft_strjoin(tmp, "<-");
		free(tmp);
	}
	if (e.key.keysym.sym == SDLK_RETURN)
	{
		tmp = ft_strndup(elem->text.text, (ft_strlen(elem->text.text) - 2));
		ft_strdel(&elem->text.text);
		elem->text.text = ft_strdup(tmp);
		free(tmp);
		elem->loop = 0;
	}
}

static void		button_func(SDL_Event e, t_element *elem)
{
	int	*result;

	result = elem->extra_info;
	if (e.type == SDL_MOUSEBUTTONDOWN)
		*result = ((t_button *)elem->info)->type;
}

static void		init_button(t_window *win)
{
	t_xywh coord;

	coord = ui_init_coords(50, 200, 100, 50);
	ui_create_button(win, coord, NULL);
	ft_set_text(&((t_element *)win->elements->content)->text, "OK");
	((t_element *)win->elements->content)->text.centered = 1;
	((t_element *)win->elements->content)->f = &button_func;
	((t_button *)((t_element *)win->elements->content)->info)->type = 1;
	ft_update_elem_background(win->elements->content, 0xff0082c4);

	coord = ui_init_coords(200, 200, 100, 50);
	ui_create_button(win, coord, NULL);
	ft_set_text(&((t_element *)win->elements->content)->text, "CANCEL");
	((t_element *)win->elements->content)->text.centered = 1;
	((t_element *)win->elements->content)->f = &button_func;
	((t_button *)((t_element *)win->elements->content)->info)->type = 0;
	ft_update_elem_background(win->elements->content, 0xffEE7f1B);

}

void		init_text_area(t_element **button, t_window *win)
{
	t_xywh coord;

	coord = ui_init_coords(50, 100, 250, 50);
	(*button) = ui_create_button(win, coord, NULL);
	ft_set_text(&(*button)->text, "Input");
	(*button)->text.y = 10;
	(*button)->text.x = 10;
	(*button)->text.set_text = 1;
	(*button)->f = &text_area;
	(*button)->extra_info = win->win;
}

t_window		*init_input_win(t_libui *libui)
{
	t_text			text;
	t_window		*win;
	t_window_info	test;

	test.coord = ui_init_coords(0, 0, 350, 300);
	popup_coord(&test.coord.x, &test.coord.y, 350, 300);
	test.title = ft_strdup("Pop up");
	win = ft_create_window(libui, test);
	ft_update_background(win->surface, 0xffECECEC);
	init_button(win);
	return (win);
}

char		*input_popup(int x1, int y1)
{
	int				result;
	char			*str;
	t_libui			*libui;
	t_list			*list;
	t_element		*button;
	t_window		*win;

	str = NULL; //cant be NULL
	libui = (t_libui *)malloc(sizeof(t_libui));
	libui->windows = NULL;
	libui->hotkeys = NULL;
	result = -1;
	win = init_input_win(libui);
	init_text_area(&button, win);
	list = win->elements->next;
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
	if (result == 1 && button->loop == 1)
		str = ft_strndup(button->text.text, ft_strlen(button->text.text) - 2);
	else if (result == 1 && button->loop == 0)
		str = ft_strdup(button->text.text);
	free_window(win);
	free(libui->windows);
	free(libui->hotkeys);
	free(libui);
	return (str);
}
