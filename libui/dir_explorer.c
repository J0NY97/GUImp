/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   popup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 14:01:15 by nneronin          #+#    #+#             */
/*   Updated: 2020/09/19 12:42:36 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"
#include <dirent.h>

void	popup_coord(int *x, int *y, int w, int h)
{
	SDL_DisplayMode DM;
	SDL_GetCurrentDisplayMode(0, &DM);
	*x = DM.w / 2 - (w / 2);
	*y = DM.h / 2 - (h / 2);
}

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

void		init_button(t_window *win, int elem_nb, t_list *list, t_element *menu)
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
		ui_create_button(win, coord, menu);
		ft_set_text(&((t_element *)win->elements->content)->text, curr->content);
		curr = curr->next;
		((t_element *)win->elements->content)->text.centered = 1;
		((t_element *)win->elements->content)->f = &button1;
		ft_update_elem_background(win->elements->content, 0xff0082c4);
	}
}

t_window		*init_dir_win(t_libui *libui, char *folder_path, unsigned char type)
{
	int				elem_nb;
	t_list			*list;
	t_window		*win;
	t_window_info	test;
	t_element		*menu;

	if ((list = dir_open(folder_path, type, &elem_nb)) == NULL)
		return (NULL);
	test.coord = ui_init_coords(0, 0, 350 + 20, 20 + 25 + (10 * 75)); //rememebere
	popup_coord(&test.coord.x, &test.coord.y,  350, 25 + (10 * 75));
	test.title = ft_strdup(folder_path);
	test.bg_color = 0xFFECECEC;
	win = ft_create_window(libui, test);

	t_xywh coord;

	coord = ui_init_coords(10, 10, 330, 25 + (elem_nb * 75));
	menu = ui_create_surface(win, coord, NULL);
	ft_update_elem_background(menu, 0xffa9a9a9);

	ui_create_scrollbar(win, menu);
	init_button(win, elem_nb, list, menu);

	ft_lstdel(&list, &del);
	return (win);
}


char		*dir_explore(char *folder_path, unsigned char type)
{
	char			*str;
	char			*result;
	t_list			*list;
	t_libui			*libui;
	t_window		*win;

	libui = (t_libui *)malloc(sizeof(t_libui));
	libui->windows = NULL;
	libui->hotkeys = NULL;
	libui->quit = 0;
	result = NULL;
	str = NULL;
	if ((win = init_dir_win(libui, folder_path, type)) == NULL) //free libui
		return (NULL);
	list = win->elements;
	while (((t_element *)list->content)->extra_info == NULL)
	{
		((t_element *)list->content)->extra_info = &result;
		list = list->next;
	}
	while (result == NULL && libui->quit != 1)
	{
		ft_event_poller(libui);
		ui_render(win);
	}
	if (libui->quit != 1)
		str = ft_strjoiner(folder_path, "/", result, NULL);
	free(result);
	free_libui(libui);
	return (str);
}
