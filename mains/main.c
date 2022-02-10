/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 09:06:09 by gcollet           #+#    #+#             */
/*   Updated: 2022/02/10 15:44:01 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "mlx.h"

int	update(t_mlx *mlx)
{
	raytracing(new_vec3(0, 0, 0), *get_scene(), mlx);
	
	return (0);
}

int	main(int argc, char **argv)
{
	t_mlx	*mlx;
	t_scene	*scene;

	mlx = get_mlx();
	scene = get_scene();
	scene->light_amb = new_light(AMBIANT, 0x0000FF, 0.2, 1000);
	ft_dlst_add_front(&scene->shapes, ft_dlst_new_node(new_sphere(new_vec3(200, 100, 100), 100, 0xFFFFFF)));
	ft_dlst_add_front(&scene->lights, ft_dlst_new_node(new_light(DIFFUSE, 0xFFFFFF, 1, 200)));
	((t_light *)scene->lights->content)->obj->pos = new_vec3(50, 100, 100);
	//ft_dlst_add_front(&scene->shapes, ft_dlst_new_node(new_sphere(new_vec3(150, 120, 50), 30, 0xFF00FF)));
	//ft_dlst_add_front(&scene->shapes, ft_dlst_new_node(new_sphere(new_vec3(130, 170, 15), 50, 0x00FFFF)));
	//ft_dlst_add_front(&scene->shapes, ft_dlst_new_node(new_sphere(new_vec3(350, 350, 50), 100, 0xFFFF00)));
	fill_img(mlx->img, 0x0000FF);
	mlx_hook(mlx->win, 2, 1L << 0, key_press, mlx);
	mlx_hook(mlx->win, 3, 1L << 1, key_release, mlx);
	mlx_hook(mlx->win, 17, 0, quit_handler, NULL);
	mlx_mouse_hook(mlx->win, mouse_handler, NULL);
	mlx_loop_hook (mlx->mlx, update, mlx);

	// t_vec3	vec1 = new_vec3(10, 8, 6);
	// t_vec3	vec2 = new_vec3(15, 12, 1);
	// t_vec3	sub = vec3_sub(vec2, vec1);
	// t_vec3	norm = vec3_normalize(sub);

	// printf("sub %f %f %f norm %f %f %f", sub.x, sub.y, sub.z , norm.x, norm.y, norm.z);
	mlx_loop (mlx->mlx);
	return (0);
}

// int	update(t_mlx *mlx)
// {
// 	t_light	*light;
// 	float	x;
// 	float	y;
// 	t_vec3	vect;
// 	int		color;
// 	float	max_dist;
// 	t_dlst	*temp;
// 	t_scene	*scene;

// 	max_dist = 300;
// 	vect = new_vec3(0, 0, 0);
// 	y = 0;
// 	scene = get_scene();

// 	while (y < WIN_H)
// 	{
// 		x = 0;
// 		while (x < WIN_W)
// 		{
// 			vect.x = x;
// 			vect.y = y;
// 			vect.z = 0;
// 			color = 0;
// 			while (vect.z < max_dist)
// 			{
// 				temp = scene->shapes;
// 				while (temp != NULL)
// 				{
// 					if (is_in_bound((t_shape *)temp->content, vect))
// 					{
// 						color = ((t_shape *)temp->content)->color;
// 						color = color_shift_int(color, 0, vect.z / 200.0);
// 						break;
// 					}
// 					temp = temp->next;
// 				}
// 				vect.z = vect.z + 5;
// 			}
// 			img_pixel_put(mlx->img, x, y, color);
			
// 			x++;
// 		}
// 		y++;
// 	}
// 	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.ptr, 0, 0);
// 	return (0);
// }
