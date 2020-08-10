/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 12:48:16 by jsalmi            #+#    #+#             */
/*   Updated: 2020/08/10 14:46:00 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guimp.h"

void	ft_error(char *msg)
{
	ft_putstr("\x1b[31m[Error] \x1b[0m");
	ft_putstr(msg);
	ft_putstr("\n");
	exit(1);
}

int		main(void)
{
	t_info *info;

	ft_test_libui();
	if (!(info = (t_info *)malloc(sizeof(t_info))))
		ft_error("Couldnt mallco t_info.");
	SDL_Init(SDL_INIT_VIDEO);
	//TTF_Init();
	// SDL_Image_Init();

	// Init();
	info->run = 1;
	//
	info->toolbox.x = 0;
	info->toolbox.y = 0;
	info->toolbox.w = 500;
	info->toolbox.h = 1250;
	info->toolbox.resizeable = 1;
	info->toolbox.win = ft_create_window("toolbox", info->toolbox.x, info->toolbox.y,
										info->toolbox.w, info->toolbox.h, info->toolbox.resizeable);
	info->toolbox.surface = SDL_GetWindowSurface(info->toolbox.win);

	info->main.x = info->toolbox.x + info->toolbox.w + 5;
	info->main.y = 0;
	info->main.w = 1500;
	info->main.h = 1250;
	info->main.resizeable = 1;
	info->main.win = ft_create_window("main", info->main.x, info->main.y,
										info->main.w, info->main.h, info->main.resizeable);
	info->main.surface = SDL_GetWindowSurface(info->main.win);

	info->layers.x = info->main.x + info->main.w + 5;
	info->layers.y = 0;
	info->layers.w = 500;
	info->layers.h = 1250;
	info->layers.resizeable = 1;
	info->layers.win = ft_create_window("layers", info->layers.x, info->layers.y,
										info->layers.w, info->layers.h, info->main.resizeable);
	info->layers.surface = SDL_GetWindowSurface(info->layers.win);

	while (info->run)
	{
		//input
		check_input(info);
		// This will go into render function
		SDL_UpdateWindowSurface(info->main.win);
		SDL_UpdateWindowSurface(info->toolbox.win);
		SDL_UpdateWindowSurface(info->layers.win);
	}
	return (0);
}
