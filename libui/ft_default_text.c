/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_create_text.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 11:18:45 by jsalmi            #+#    #+#             */
/*   Updated: 2020/09/17 13:33:34 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ft_default_text(t_text *text, char *txt)
{
	text->x = 0;
	text->y = 0;
	text->centered = 0;
	text->parent = NULL;
	if (txt != NULL)
	{
		text->set_text = 1;	
		text->text = ft_strdup(txt);
	}
	else
		text->text = NULL;
	text->color = 0x000000;
	text->margin = 0;
	ft_set_font(text, "font.ttf", 28);
}
