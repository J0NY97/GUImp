/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   popup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 14:01:15 by nneronin          #+#    #+#             */
/*   Updated: 2020/08/29 14:58:51 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	notify(char *title, char *msg)
{
	SDL_ShowSimpleMessageBox(
			SDL_MESSAGEBOX_INFORMATION,
			title,
			msg,
			NULL);
}

void	error_msg(char *str)
{
	SDL_ShowSimpleMessageBox(
			SDL_MESSAGEBOX_ERROR,
			"Error",
			str,
			NULL);
	ft_putstr(str);
	exit(1);
}
/*
void	pop_up()
{
	t_window_info test;

	test.x = 0;
	test.y = 0;
	test.w = 50;
	test.h = 50;
	test.resizeable = 0;
	test.title = ft_strdup("PoPuP");
	if (!(info->toolbox->window = ft_create_window(test)))
		exit (0);
}*/
