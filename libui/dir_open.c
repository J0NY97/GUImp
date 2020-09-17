/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_explorer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 13:34:38 by nneronin          #+#    #+#             */
/*   Updated: 2020/09/17 16:48:59 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"
#include <dirent.h>

void	add_to_list(t_list **list, char *file)
{
	t_list *lst;

	lst = ft_lstnew(0, 0);
	lst->content = ft_strdup(file);
	lst->content_size = 0;
	if (list == NULL)
		(*list) = lst;
	else
		ft_lstadd(&(*list), lst);
}

t_list 		*dir_open(char *folder_path, unsigned char type, int *size)
{
	t_list			*list;
	DIR				*dir;
	struct	dirent	*file;

	*size = 0;
	list = NULL;
	if (!(dir = opendir(folder_path)))
		return (NULL);
	while ((file = readdir(dir)))
	{
		if (file->d_type == type && file->d_name[0] != '.')
		{
			add_to_list(&list, file->d_name);
			*size += 1;
		}
	}
	closedir(dir);
	return (list);
}
