/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_font.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 12:10:20 by jsalmi            #+#    #+#             */
/*   Updated: 2020/09/16 12:15:01 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ft_set_font(t_text text, char *font, unsigned short size)
{
	if (text.font)
		TTF_CloseFont(text.font);
	text.font = TTF_OpenFont(font, size);
}
