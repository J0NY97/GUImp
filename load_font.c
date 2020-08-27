/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_font.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 16:01:27 by nneronin          #+#    #+#             */
/*   Updated: 2020/08/27 16:20:28 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guimp.h"

int		load_font(char *file, TTF_Font *font)
{
	int i;
	int k;
	char *ttf;

	k = 0;
	ttf = ft_strdup(".ttf");
	i = ft_strlen(file);
	while (k < 4)
	{
		if (ttf[k] != file[k + i - 4])
		{
			free(ttf);
			return (0);
		}
		k++;
	}
	free(ttf);
	return (1);
}
