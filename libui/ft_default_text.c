/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_create_text.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 11:18:45 by jsalmi            #+#    #+#             */
/*   Updated: 2020/09/05 16:43:12 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

t_text	ft_default_text(char *txt)
{
	t_text	text;

	text.x = 0;
	text.y = 0;
	text.centered = 0;
	if (txt != NULL)
		text.text = txt; // this shouldnt work
	else
		text.text = NULL;
	text.color = 0x000000;
	text.margin = 0;
	text.font = TTF_OpenFont("font.ttf", 28);
	return (text);
}
