/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 19:57:26 by fousse            #+#    #+#             */
/*   Updated: 2022/02/07 16:58:29 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minirt.h"

int	color_get(t_img img, int x, int y)
{
	int	color;

	if (x + (y * img.width) >= img.width * img.height)
		return (0);
	color = *((unsigned int *)(img.addr
				+ y * img.width + x * (img.bpp / 8)));
	return (color);
}

int	color_valid_rgb(t_rgb rgb)
{
	if (rgb.r > 255 || rgb.r < 0)
		return (0);
	if (rgb.g > 255 || rgb.g < 0)
		return (0);
	if (rgb.b > 255 || rgb.b < 0)
		return (0);
	return (1);
}
