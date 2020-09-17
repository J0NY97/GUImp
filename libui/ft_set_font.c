/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_font.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 12:10:20 by jsalmi            #+#    #+#             */
/*   Updated: 2020/09/17 13:09:31 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ft_set_font(t_text *text, char *font, int size)
{
	if (text->font)
		TTF_CloseFont(text->font);
	text->font = NULL;
	text->font = TTF_OpenFont(font, size);
	if (!text->font)
	{
		printf("set_font : %s\n", TTF_GetError());
		exit (0);
	}
}
