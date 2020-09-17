/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   popup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 14:01:15 by nneronin          #+#    #+#             */
/*   Updated: 2020/09/17 13:39:24 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"
#include <dirent.h>

void	del(void *name, size_t size)
{

	ft_strdel((char **)&name);
}


void		button1(SDL_Event e, t_element *elem)
{
	char **str;
   
	str	= elem->extra_info;
	if (e.type == SDL_MOUSEBUTTONDOWN)
		(*str) = ft_strdup(elem->text.text);
}

void		init_button(t_window *win, int elem_nb, t_list *list)
{
	int i;
	t_list *curr;
	t_xywh coord;

	i = -1;
	curr = list;
	coord = ui_init_coords(50, 0, 200, 0);
	while (++i < elem_nb)
	{
		coord = ui_init_coords(50, coord.y + 25 + coord.h, 250, 50);
		ui_create_button(win, coord, NULL);
		ft_set_text(&((t_element *)win->elements->content)->text, curr->content);
		curr = curr->next;
		((t_element *)win->elements->content)->text.centered = 1;
		((t_element *)win->elements->content)->f = &button1;
		ft_update_elem_background(win->elements->content, 0xff0082c4);
	}
}

char		*dir_open(int x1, int y1, char *folder_path, unsigned char type)
{
	char			*result = NULL;
	t_libui			*libui;
	t_window		*win;
	t_window_info	test;

	libui = (t_libui *)malloc(sizeof(t_libui));
	libui->windows = NULL;
	libui->hotkeys = NULL;

	t_list *list;
	int elem_nb;
	list = dir_explorer(folder_path, type, &elem_nb);

	test.coord = ui_init_coords(0, 0, 350, 25 + (elem_nb * 75));
	test.title = ft_strdup(folder_path); //free in ft_create_window
	win = ft_create_window(libui, test);
	ft_update_background(win->surface, 0xffECECEC);
	init_button(win, elem_nb, list);
	ft_lstdel(&list, &del);


	t_list *curr;
	curr = win->elements;
	while (curr)
	{
		((t_element *)curr->content)->extra_info = &result;
		curr = curr->next;
	}

	while (result == NULL)
	{
		ft_event_poller(libui);
		ui_render(win);
	}
	free_window(win);
	free(libui->windows);
	free(libui->hotkeys);
	free(libui);

	return (result); //maybe strjoin
}
