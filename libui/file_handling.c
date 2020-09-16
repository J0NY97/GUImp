/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 15:55:38 by jsalmi            #+#    #+#             */
/*   Updated: 2020/09/16 14:23:09 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

SDL_Surface		*load_image(char *file)
{
	SDL_Surface *img;

	if (!(img = IMG_Load(file)))
	{
		printf("IMG_Load: %s\n", IMG_GetError());
		return (NULL);
	}
	return (img);
}

int		save_image(SDL_Surface *img, char *file)
{
	char *real_file;

	real_file = ft_strjoiner("images/", file, NULL);
	if (ft_strstr(real_file, ".png") != 0)
		IMG_SavePNG(img, real_file);
	else if (ft_strstr(real_file, ".jpg") != 0)
		IMG_SaveJPG(img, real_file, 32);
	else if (ft_strstr(real_file, ".bmp") != 0)
		SDL_SaveBMP(img, real_file);
	else
	{
		free(real_file);
		real_file = ft_strjoiner("images/", file, ".bmp", NULL);
		SDL_SaveBMP(img, real_file);
	}
	printf("File saved as %s\n", real_file);
	free(real_file);
	return (1);
}

char	*drag_and_drop(SDL_Event e)
{
	char *black_dhide;
	
	if (e.type == SDL_DROPFILE)
	{
		ft_putstr("drop event happeneed\n");
		black_dhide = e.drop.file;
		return (black_dhide);
	}
	return (NULL);
}
