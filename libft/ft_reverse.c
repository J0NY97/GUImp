/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 14:53:02 by jsalmi            #+#    #+#             */
/*   Updated: 2019/10/29 13:38:51 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	ft_reverse(char *s)
{
	int		i;
	int		j;
	char	temp;

	j = 0;
	i = ft_strlen(s);
	while (i > j)
	{
		temp = s[j];
		s[j] = s[i - 1];
		s[i - 1] = temp;
		i--;
		j++;
	}
}
