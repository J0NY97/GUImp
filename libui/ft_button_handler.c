/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_button_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 11:59:15 by jsalmi            #+#    #+#             */
/*   Updated: 2020/09/10 13:11:43 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ft_button_handler_real(SDL_Event e, t_element *elem)
{
	if (e.type == SDL_MOUSEBUTTONDOWN)
		elem->state = 1;
	else if (e.type == SDL_MOUSEMOTION)
		elem->state = 2;
	else if (e.type == SDL_MOUSEBUTTONUP)
		elem->state = 2;
}

void	ft_button_handler(SDL_Event e, t_element *elem)
{
	if (e.type == SDL_MOUSEBUTTONDOWN)
	{
		if (elem->state == 1)
		{
			elem->state = 0;
			elem->default_state = 0;
		}
		else if (elem->state == 0)
		{
			elem->state = 1;
			elem->default_state = 1;
		}
	}
	else if (e.type == SDL_MOUSEMOTION)
		elem->state = 2;
	else if (e.type == SDL_MOUSEBUTTONUP)
		elem->state = 2;
}
