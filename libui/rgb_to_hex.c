/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_to_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 16:03:13 by jsalmi            #+#    #+#             */
/*   Updated: 2020/09/09 17:53:22 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

int		rgb_to_hex(int r, int g, int b, int a)
{
	return ((r & 0xFF) << 16 | (g & 0xFF) << 8 | (b & 0xFF) | (a & 0xFF) << 24);
}
