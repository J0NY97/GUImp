/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_x_to_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 14:55:22 by jsalmi            #+#    #+#             */
/*   Updated: 2020/09/02 15:01:07 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ft_add_x_to_list(t_list *old, void *content, size_t content_size)
{
	t_list *lst;

	lst = ft_lstnew(0, 0);
	lst->content = content;
	lst->content_size = content_size;
	if (old == NULL)
		old = lst;
	else
		ft_lstadd(&old, lst);
}
