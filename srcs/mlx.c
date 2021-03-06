/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 19:17:29 by fousse            #+#    #+#             */
/*   Updated: 2022/02/07 14:09:17 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minirt.h"

t_mlx	*get_mlx(void)
{
	static t_mlx	mlx;

	if (mlx.init != 1)
	{
		mlx.mlx = mlx_init();
		mlx.win = mlx_new_window(mlx.mlx, WIN_W, WIN_H, "Cub3D");
		new_img(mlx.mlx, &mlx.img, WIN_W, WIN_H);
		mlx.init = 1;
	}
	return (&mlx);
}
