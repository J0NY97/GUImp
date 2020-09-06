/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_button_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 11:59:15 by jsalmi            #+#    #+#             */
/*   Updated: 2020/09/06 12:00:47 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ft_button_handler(SDL_Event e, t_element *elem)
{
	if (e.type == SDL_MOUSEBUTTONDOWN)
		elem->state = 1;
	else if (e.type == SDL_MOUSEMOTION)
		elem->state = 2;
	else if (e.type == SDL_MOUSEBUTTONUP)
		elem->state = 2;
}
