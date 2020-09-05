/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   notify.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 13:02:13 by nneronin          #+#    #+#             */
/*   Updated: 2020/09/03 13:02:40 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	notify(char *title, char *msg)
{
	SDL_ShowSimpleMessageBox(
			SDL_MESSAGEBOX_INFORMATION,
			title, msg, NULL);
}

void	error_msg(char *str)
{
	SDL_ShowSimpleMessageBox(
			SDL_MESSAGEBOX_ERROR,
			"Error", str, NULL);
	ft_putstr(str);
	exit(1);
}
