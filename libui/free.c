/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 13:43:34 by nneronin          #+#    #+#             */
/*   Updated: 2020/09/17 14:22:49 by jsalmi           ###   ########.fr       */
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
	free(elem->info);
	//ft_strdel((char **)&elem->extra_info);//idk
	elem->extra_info = NULL;

	free_text(&elem->text);

	SDL_FreeSurface(elem->surface);
	SDL_FreeSurface(elem->states[2]);
	SDL_FreeSurface(elem->states[1]);
	SDL_FreeSurface(elem->states[0]);
	elem->parent_elem = NULL;
	elem->parent = NULL;
	free(elem);
}

void	free_window(t_window *win)
{
	t_list *curr;
	t_list *tmp;

	curr = win->elements;
	SDL_FreeSurface(win->surface);
	SDL_DestroyWindow(win->win);
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
