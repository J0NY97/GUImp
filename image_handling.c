/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 15:55:38 by jsalmi            #+#    #+#             */
/*   Updated: 2020/08/25 16:21:12 by jsalmi           ###   ########.fr       */
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
	SDL_SaveBMP(img, file);
	return (1);
}
