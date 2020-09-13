/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 14:00:26 by jsalmi            #+#    #+#             */
/*   Updated: 2020/09/12 14:04:46 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

int		ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int		ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}