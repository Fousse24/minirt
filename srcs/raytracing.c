/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 09:06:09 by gcollet           #+#    #+#             */
/*   Updated: 2022/02/10 16:51:50 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// int	raytracing(t_vec3 ori, t_scene scene, t_mlx	*mlx)
// {
// 	t_vec3	pos;
// 	t_ray3	ray;
// 	int		color;

// 	ray.len = 300;
// 	pos.y = 0;
// 	while (pos.y < WIN_H)
// 	{
// 		pos.x = 0;
// 		while (pos.x < WIN_W)
// 		{
// 			ray.ori = new_vec3(pos.x, pos.y, 0);
// 			ray.dir = new_vec3(0, 0, 1);
// 			color = raytrace(ray, 2, scene);
// 			img_pixel_put(mlx->img, pos.x, pos.y, color);
			
// 			pos.x++;
// 		}
// 		pos.y++;
// 	}
// 	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.ptr, 0, 0);
// 	return (0);
// }

int	raytracing(t_vec3 ori, t_scene scene, t_mlx	*mlx)
{
	t_vec3	pos;
	t_ray3	ray;
	int		color;

	ray.len = 300;
	pos.y = 0;
	while (pos.y < WIN_H)
	{
		pos.x = 0;
		while (pos.x < WIN_W)
		{
			ray.ori = new_vec3(pos.x, pos.y, 0);
			ray.dir = new_vec3(0, 0, 1);
			color = raytrace(ray, 2, scene);
			img_pixel_put(mlx->img, pos.x, pos.y, color);
			
			pos.x++;
		}
		pos.y++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.ptr, 0, 0);
	return (0);
}

/* 
* Trace a single ray. Return a int color.
* (ratio) is the unit ratio at which it will check collisions.
*/
int	raytrace(t_ray3	ray, float ratio, t_scene scene)
{
	t_vec3	vect;
	t_vec3	unit;
	t_dlst	*temp;
	float	i;
	int		color;
	double fov = 60 * M_PI / 180;

	vect = new_vec3(ray.ori.x, ray.ori.y, ray.ori.z);
	unit = new_vec3(ray.dir.x * ratio, ray.dir.y * ratio, ray.dir.z * ratio);
	color = 0;
	i = 0;
	while (i <= ray.len)
	{
		temp = scene.shapes;
		while (temp != NULL)
		{
			if (is_in_bound((t_shape *)temp->content, vect))
			{
				color = ((t_shape *)temp->content)->color;
				ray.ori = vect;
				shadowtracing(ray, 1, scene, &color);
				color = color_shift_int(color, scene.light_amb->color, scene.light_amb->force);
				return (color);
			}
			temp = temp->next;
		}
		vect = vec3_add(vect, unit);
		i += ratio;
	}
	return (color);
} 

/* 
*
*
*/
void	shadowtracing(t_ray3 ray, float ratio, t_scene scene, int *color)
{
	t_vec3	vect;
	t_vec3	unit;
	t_light	*light;
	t_dlst	*temp;
	float	i;
	
	light = (t_light *)scene.lights->content;
	vect = ray.ori;
	ray.dir = vec3_normalize(vec3_sub(light->obj->pos, vect));
	unit = new_vec3(ray.dir.x * ratio, ray.dir.y * ratio, ray.dir.z * ratio);
	vect = vec3_add(ray.ori, ray.dir);
	i = 0;
	while (i <= ray.len)
	{
		temp = scene.shapes;
		while (temp != NULL)
		{
			if (is_in_bound((t_shape *)temp->content, vect))
			{
				*color = 0;
				return ;
			}
			temp = temp->next;
		}
		if (is_in_light(light, vect))
		{
			*color = color_shift_int(*color, light->color, 1 / i);
			return ;
		}
		vect = vec3_add(vect, unit);
		i += ratio;
	}
	return ;
} 


