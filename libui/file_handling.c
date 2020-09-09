/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 15:55:38 by jsalmi            #+#    #+#             */
/*   Updated: 2020/09/06 16:12:42 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

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
	
	real_file = ft_strjoiner("images/", file, ".bmp", NULL);
	if (SDL_SaveBMP(img, real_file) != 0)
	{
		printf("Save_Img(): %s\n", SDL_GetError());
		free(real_file);
		return (0);
	}
	ft_putstr("File save to: ");
	ft_putstr(real_file);
	ft_putstr("\n");
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
