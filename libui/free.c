/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 13:43:34 by nneronin          #+#    #+#             */
/*   Updated: 2020/09/17 11:42:47 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	free_element(t_element *elem)
{
	free(elem->info);
	ft_strdel(&elem->text.text);
	TTF_CloseFont(elem->text.font);
	elem->text.font = NULL; // to be safe...
	SDL_FreeSurface(elem->surface);
	SDL_FreeSurface(elem->states[2]);
	SDL_FreeSurface(elem->states[1]);
	SDL_FreeSurface(elem->states[0]);
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
	}
	free(win);
}
