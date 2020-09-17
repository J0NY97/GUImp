/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libui_quit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 14:14:12 by jsalmi            #+#    #+#             */
/*   Updated: 2020/09/17 14:36:33 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	libui_quit(t_libui *libui)
{
	t_list	*temp;
	t_list	*curr;

	curr = libui->windows;
	while (curr)
	{
		temp = curr;
		curr = curr->next;
		free_window(temp->content);
		temp->next = NULL;
		free(temp);
	}
	// HOTKEYS
	curr = libui->hotkeys;
	while (curr)
	{
		temp = curr;
		curr = curr->next;
		temp->next = NULL;
		free(temp);
	}
	free(libui);
}
