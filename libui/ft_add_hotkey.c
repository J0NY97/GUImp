/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_hotkey.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 13:43:09 by jsalmi            #+#    #+#             */
/*   Updated: 2020/09/02 16:00:28 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ft_add_hotkey_to_list(t_libui *libui, t_hotkey *hotkey)
{
	t_list *lst;

	lst = ft_lstnew(0, 0);
	lst->content = hotkey;
	lst->content_size = sizeof(t_hotkey);
	if (libui->hotkeys == NULL)
		libui->hotkeys = lst;
	else
		ft_lstadd(&libui->hotkeys, lst);
}

void	ft_add_hotkey(t_libui *libui, SDL_Keycode key, void (*f)(SDL_Event e, t_hotkey *hotkey))
{
	t_hotkey *hotkey;
	
	if (!(hotkey = (t_hotkey *)malloc(sizeof(t_hotkey))))
		ft_putstr("[ADD_HOTKEY] new hotkey couldnt be malloced.\n");
	hotkey->key = key;
	hotkey->f = f;
	ft_add_hotkey_to_list(libui, hotkey);
//	ft_add_x_to_list(libui->hotkeys, hotkey, sizeof(t_hotkey));
}
