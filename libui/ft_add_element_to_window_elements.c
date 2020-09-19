/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_element_to_list.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 11:56:09 by jsalmi            #+#    #+#             */
/*   Updated: 2020/09/19 11:13:08 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ft_add_element_to_window_elements(t_window *win, t_element *elem)
{
	t_list *lst;

	lst = ft_lstnew(0, 0);
	lst->content = elem;
	lst->content_size = sizeof(t_element);
	if (win->elements == NULL)
		win->elements = lst;
	else
		ft_lstadd(&win->elements, lst);
}

void	ft_add_to_non_render_elem_list(t_window *win, t_element *elem)
{
	t_list *lst;

	lst = ft_lstnew(0, 0);
	lst->content = elem;
	lst->content_size = sizeof(t_element);
	if (win->non_render == NULL)
		win->non_render = lst;
	else
		ft_lstadd(&win->non_render, lst);
}
