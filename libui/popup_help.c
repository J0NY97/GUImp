/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   popup_help.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 13:11:56 by nneronin          #+#    #+#             */
/*   Updated: 2020/09/19 13:19:06 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	popup_sdl_init(t_libui *libui)
{
	libui->quit = 0;
	libui->windows = NULL;
	libui->hotkeys = NULL;
	libui->drag_file = NULL;
}

void	popup_coord(int *x, int *y, int w, int h)
{
	SDL_DisplayMode DM;
	SDL_GetCurrentDisplayMode(0, &DM);
	*x = DM.w / 2 - (w / 2);
	*y = DM.h / 2 - (h / 2);
}

void	char_del(void *name, size_t size)
{
	ft_strdel((char **)&name);
}

void		popup_char_func(SDL_Event e, t_element *elem)
{
	char **str;

	str	= elem->extra_info;
	if (e.type == SDL_MOUSEBUTTONDOWN)
		(*str) = ft_strdup(elem->text.text);
}

void		popup_int_func(SDL_Event e, t_element *elem)
{
	int	*result;

	result = elem->extra_info;
	if (e.type == SDL_MOUSEBUTTONDOWN)
		*result = ((t_button *)elem->info)->type;
}
