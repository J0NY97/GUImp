/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 17:59:36 by nneronin          #+#    #+#             */
/*   Updated: 2020/09/26 18:00:47 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guimp.h"

void	save_img(SDL_Event e, t_element *elem)
{
	char		*file;
	SDL_Surface	*pic;

	if (e.type == SDL_MOUSEBUTTONDOWN)
	{
		pic = ((t_element *)elem->extra_info)->surface;
		if ((file = input_popup(100, 100)) == NULL)
		{
			ft_printf("You decided not to save the picture..\n");
			return;
		}
		if (save_image(pic, file))
			ft_printf("Picture saved.\n");
		else
			ft_printf("Picture couldnt be saved.\n");
		free(file);
	}
}
