/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 15:55:38 by jsalmi            #+#    #+#             */
/*   Updated: 2020/08/29 18:30:36 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guimp.h"

SDL_Surface		*load_image(char *file)
{
	SDL_Surface *img;

	img = IMG_Load(file);
	if (!img)
		printf("IMG_Load: %s\n", IMG_GetError());
	return (img);
}

int		save_image(SDL_Surface *img, char *file)
{
	char *real_file;

	//if (!(pop_up(0, 0, ft_strjoin("Save file as: ", file))))
	//	return (1);
	real_file = ft_strjoin(file, ".bmp");
	if (SDL_SaveBMP(img, real_file) != 0)
	{
		printf("Save_Img(): %s\n", SDL_GetError());
		free(real_file);
		return (0);
	}
	free(real_file);
	return (1);
}

char	*drag_and_drop(SDL_Event e)
{
	char *black_dhide;
	
	if (e.type == SDL_DROPFILE)
	{
		printf("Event is dropfile\n");
		black_dhide = e.drop.file;
		return (black_dhide);
	}
	return (NULL);
}
