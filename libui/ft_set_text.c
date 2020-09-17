/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_text.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 11:57:43 by jsalmi            #+#    #+#             */
/*   Updated: 2020/09/17 13:09:45 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ft_set_text(t_text *text, char *txt)
{
	if (text->text == NULL)
		ft_default_text(text, txt);
	else
	{
		if (text->text)
			free(text->text);
		text->text = ft_strdup(txt);
	}
}
