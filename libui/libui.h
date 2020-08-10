/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libui.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 13:04:09 by jsalmi            #+#    #+#             */
/*   Updated: 2020/08/10 14:47:48 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBUI_H
# define LIBUI_H
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <string.h>
# include "../libft/libft.h"
# include "../include/SDL2/SDL.h"
# include "../include/SDL2/SDL_ttf.h"
# include "../include/SDL2/SDL_image.h"

void		ft_test_libui(void);
SDL_Window	*ft_create_window(char *title, int x, int y, int w, int h, int resizeable);

#endif
