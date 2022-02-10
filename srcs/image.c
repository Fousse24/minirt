/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 18:51:46 by fousse            #+#    #+#             */
/*   Updated: 2022/02/07 14:15:35 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/* Create a new MLX image */
void	new_img(void *mlx, t_img *img, int width, int height)
{
	img->ptr = mlx_new_image(mlx, width, height);
	img->addr = mlx_get_data_addr(img->ptr, &img->bpp,
			&img->data_w, &img->endian);
	img->bytes = img->bpp / 8;
	img->width = img->data_w / img->bytes;
	img->height = height;
	
}

/* Put the color in the specified location */
void	img_pixel_put(t_img img, int x, int y, int color)
{
	char	*dst;

	if (x > WIN_W || y > WIN_H || x <= 0 || y <= 0)
		return ;
	if (x + (y * img.width) >= img.width * img.height)
		return ;
	dst = img.addr + (y * img.data_w + x * img.bytes);
	*(unsigned int *)dst = color;
}

/* Fill all pixel to color in a given image */
void	fill_img(t_img img, int color)
{
	char	*dst;
	int		i;

	i = 0;
	while (i < WIN_W * WIN_H)
	{
		dst = img.addr + (i * img.bytes);
		*(unsigned int *)dst = color;
		i++;
	}
}
