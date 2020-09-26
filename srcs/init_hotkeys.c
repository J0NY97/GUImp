/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_hotkeys.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 16:04:31 by nneronin          #+#    #+#             */
/*   Updated: 2020/09/26 16:05:02 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guimp.h"

void	key_press(SDL_Event e, t_hotkey *hotkey)
{
	ft_printf("priss prass pross %s\n", SDL_GetKeyName(hotkey->key));
}

void	hotkey_init(t_info *info, t_libui *libui)
{
	ft_add_hotkey(libui, SDLK_a, &key_press);
	ft_add_hotkey(libui, SDLK_b, &key_press);
	ft_add_hotkey(libui, SDLK_c, &key_press);
	ft_add_hotkey(libui, SDLK_d, &key_press);
}
