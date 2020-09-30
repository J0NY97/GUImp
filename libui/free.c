/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 13:43:34 by nneronin          #+#    #+#             */
/*   Updated: 2020/09/19 12:57:45 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	free_text(t_text *text)
{
	ft_strdel(&text->text);
	TTF_CloseFont(text->font);
	text->font = NULL; // to be safe...
	text->parent = NULL;
}

void	free_element(t_element *elem)
{
	if (elem->info)
		free(elem->info);
	free_text(&elem->text);
	SDL_FreeSurface(elem->surface);
	SDL_FreeSurface(elem->states[2]);
	SDL_FreeSurface(elem->states[1]);
	SDL_FreeSurface(elem->states[0]);
	elem->extra_info = NULL;
	elem->parent_elem = NULL;
	elem->parent = NULL;
	free(elem);
}

void	free_window(t_window *win)
{
	t_list *curr;
	t_list *tmp;

	SDL_FreeSurface(win->surface);
	SDL_DestroyWindow(win->win);
	curr = win->elements;
	while (curr)
	{
		tmp = curr;
		curr = curr->next;
		free_element(tmp->content);
		tmp->next = NULL;
		free(tmp);
	}
	curr = win->non_render;
	while (curr)
	{
		tmp = curr;
		curr = curr->next;
		free_element(tmp->content);
		tmp->next = NULL;
		free(tmp);
	}
	free(win);
}

void	free_hotkeys(t_hotkey *idk)
{
	free(idk);
}

void	free_libui(t_libui *libui)
{
	t_list *curr;

	curr = libui->windows;
	while (curr)
	{
		free_window(curr->content);
		curr = curr->next;
	}
	curr = libui->hotkeys;
	while (curr)
	{
		free_hotkeys(curr->content);
		curr = curr->next;
	}
	free(libui->windows);
	free(libui->hotkeys);
	ft_strdel(&libui->drag_file);
	free(libui);
}
