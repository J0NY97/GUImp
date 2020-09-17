/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_create_text.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 11:18:45 by jsalmi            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2020/09/17 11:41:03 by nneronin         ###   ########.fr       */
=======
/*   Updated: 2020/09/17 11:51:38 by jsalmi           ###   ########.fr       */
>>>>>>> 71c7be79e55b60c06dd178b3f49f56775b138b45
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

t_text	ft_default_text(char *txt)
{
	t_text	text;

	text.x = 0;
	text.y = 0;
	text.centered = 0;
	text.parent = NULL;
	if (txt != NULL)
<<<<<<< HEAD
		text.text = ft_strdup(txt); // this shouldnt work
=======
		text.text = ft_strdup(txt);
>>>>>>> 71c7be79e55b60c06dd178b3f49f56775b138b45
	else
		text.text = NULL;
	text.color = 0x000000;
	text.margin = 0;
	text.font = TTF_OpenFont("font.ttf", 28);
	return (text);
}
