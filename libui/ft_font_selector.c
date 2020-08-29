/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_font_selector.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 11:03:51 by nneronin          #+#    #+#             */
/*   Updated: 2020/08/29 12:03:46 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

TTF_Font	*init_fonts(char *name, int size)
{
	char		*tmp;
	TTF_Font	*fonts;
	
	tmp = ft_strjoin(name, ".ttf");
	free(name);
	name = ft_strjoin("./libui/TTF/", tmp);
	if (!(font = TTF_OpenFont(name, size)))
	{
		ft_putstr(TTF_GetError());
		write(1, "\n", 1);
	}
	free(name);
	free(tmp);
	return (font);
}
