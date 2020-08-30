/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_window_to_libui_windows.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 14:52:12 by jsalmi            #+#    #+#             */
/*   Updated: 2020/08/30 14:54:22 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ft_add_window_to_libui_windows(t_libui *libui, t_window *win)
{
	t_list *new;

	new = ft_lstnew(0, 0);
	new->content = win;
	new->content_size = sizeof(t_window);
	if (libui->windows == NULL)
		libui->windows = new;
	else
		ft_lstadd(&libui->windows, new);
}
