/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_pop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 11:24:35 by jsalmi            #+#    #+#             */
/*   Updated: 2020/08/25 15:12:39 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	dummy(void *dum, size_t dom)
{
}

void	push_list(t_list **lst, void *content, size_t content_size)
{
	t_list *new;

	new = ft_lstnew(content, content_size);
	if (lst)
		ft_lstadd(lst,  new);
	else
		*lst = new;
//	printf("c2: %d %d\n", ((t_coords *)content)->x, ((t_coords *)content)->y);
//	printf("p2: %d %d\n", ((t_coords *)new->content)->x, ((t_coords *)new->content)->y);
//	printf("l: %d %d %zu\n", ((t_coords *)(*lst)->content)->x, ((t_coords *)(*lst)->content)->y, (*lst)->content_size);
}

void	*pop_list(t_list **lst)
{
	void	*content;
	t_list *temp;
	
	if (!(content = (void *)malloc(sizeof((*lst)->content_size))))
		exit (0);
//	printf("pop: %d %d %zu\n", ((t_coords *)(*lst)->content)->x, ((t_coords *)(*lst)->content)->y, (*lst)->content_size);
	content = ft_memcpy(content, (*lst)->content, (*lst)->content_size);
//	printf("%d %d\n", ((t_coords *)content)->x, ((t_coords *)content)->y);
	temp = (*lst)->next;
	ft_lstdelone(lst, &dummy);
	*lst = temp;
	return (content);
}
