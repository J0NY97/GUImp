/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 15:55:38 by jsalmi            #+#    #+#             */
/*   Updated: 2020/08/27 13:05:23 by jsalmi           ###   ########.fr       */
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
	if (SDL_SaveBMP(img, file) != 0)
	{
		printf("Save_Img(): %s\n", SDL_GetError());
		return (0);
	}
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
