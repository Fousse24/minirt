/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 09:06:09 by gcollet           #+#    #+#             */
/*   Updated: 2022/02/11 10:33:34 by sfournie         ###   ########.fr       */
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
	double fov = 60 * M_PI / 180;

	ray.len = 300;
	ray.ori = ori;
	pos.y = 0;
	while (pos.y < WIN_H)
	{
		pos.x = 0;
		while (pos.x < WIN_W)
		{
			ray.dir = new_vec3(pos.x - WIN_W / 2, pos.y - WIN_H / 2, (WIN_W) / (2.0 * tan(fov / 2)));
			ray.dir = vec3_normalize(ray.dir);
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
	t_vec3	unit;
	t_dlst	*temp;
	t_shape	shape;
	double	dist;
	int		color;

	unit = new_vec3(ray.dir.x * ratio, ray.dir.y * ratio, ray.dir.z * ratio);
	color = 0;
	temp = scene.shapes;
	while (temp != NULL)
	{
		shape = *(t_shape *)temp->content;
		if (is_intersecting(ray, *(t_shape *)temp->content, &dist))
		{
			color = shape.color;
			ray.ori = vec3_add(ray.ori, vec3_prod_n(ray.dir, dist));
			shadowtracing(ray, 1, scene, &color);
			color = color_shift_int(color, shape.color, scene.light_amb->force);
			return (color);
		}
		temp = temp->next;
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
	t_dlst	*lights;
	double	dist;
	float	i;
	
	lights = scene.lights;
	while (lights)
	{
		i = 0;
		light = (t_light *)lights->content;
		ray.dir = vec3_normalize(vec3_sub(light->obj->pos, ray.ori));
		unit = new_vec3(ray.dir.x * ratio, ray.dir.y * ratio, ray.dir.z * ratio);
		vect = vec3_add(ray.ori, unit);
		temp = scene.shapes;
		dist = 0;
		while (temp != NULL)
		{
			if (is_intersecting(ray, *(t_shape *)temp->content, &dist))
			{
				dist = -1;
				break;
			}
			temp = temp->next;
		}
		if (dist != -1 && intersect_light(ray, *light, &dist) && dist <= powf(light->radius, 2))
		{
			*color = color_shift_int(*color, light->color, 1.0 - (dist / powf(light->radius, 2)));
		}
		// while (i <= ray.len)
		// {
		// 	if (is_in_light(light, vect) && i <= light->radius && dist != -1)
		// 	{
		// 		*color = color_shift_int(*color, light->color, 1.0 - i / light->radius);
		// 		break;
		// 	}
		// 	vect = vec3_add(vect, unit);
		// 	i += ratio;
		// }
		lights = lights->next;
	}
	return ;
} 

int get_roots(double *t0, double *t1, t_ray3 r, t_shape s)
{
    t_vec3 v;
    double a;
    double b;
    double c;

    v = vec3_sub(r.ori, s.obj->pos);
    a = vec3_dot_product(r.dir, r.dir);
    b = 2.0 * vec3_dot_product(r.dir, v);
    c = vec3_dot_product(v, v) - (s.radius * s.radius);
    if (solve_quadra(a, b, c, t0, t1) == 0)
        return (0);
    return (1);
}

int    solve_quadra(double a, double b, double c, double *t0, double *t1)
{
    double delta;
    double q;
    double buffer;

    delta = b * b - 4*a*c;
    if (delta < 0)
        return (0);
    else if (delta == 0)
    {
        *t0 = -0.5 * b / a;
        *t1 = -0.5 * b / a;
    }
    else
    {
        if (b > 0)
            q = -1 * (b + sqrtf(delta)) / 2;
        else
        q = -1 * (b - sqrtf(delta)) / 2;
        *t0 = q / a;
        *t1 = c / q;
    }
    if (*t0 > *t1)
    {
        buffer = *t0;
        *t0 = *t1;
        *t1 = buffer;
    }
    return (1);
}



/* 
* Trace a single ray. Return a int color.
* (ratio) is the unit ratio at which it will check collisions.
*/
// int	raytrace(t_ray3	ray, float ratio, t_scene scene)
// {
// 	t_vec3	vect;
// 	t_vec3	unit;
// 	t_dlst	*temp;
// 	float	i;
// 	int		color;

// 	vect = new_vec3(ray.ori.x, ray.ori.y, ray.ori.z);
// 	unit = new_vec3(ray.dir.x * ratio, ray.dir.y * ratio, ray.dir.z * ratio);
// 	color = 0;
// 	i = 0;
// 	while (i <= ray.len)
// 	{
// 		temp = scene.shapes;
// 		while (temp != NULL)
// 		{
// 			if (is_in_bound((t_shape *)temp->content, vect))
// 			{
// 				color = ((t_shape *)temp->content)->color;
// 				ray.ori = vect;
// 				shadowtracing(ray, 1, scene, &color);
// 				color = color_shift_int(color, scene.light_amb->color, scene.light_amb->force);
// 				return (color);
// 			}
// 			temp = temp->next;
// 		}
// 		vect = vec3_add(vect, unit);
// 		i += ratio;
// 	}
// 	return (color);
// } 

/* 
*
*
*/
// void	shadowtracing(t_ray3 ray, float ratio, t_scene scene, int *color)
// {
// 	t_vec3	vect;
// 	t_vec3	unit;
// 	t_light	*light;
// 	t_dlst	*temp;
// 	t_dlst	*lights;
// 	float	i;
	
// 	lights = scene.lights;
// 	light = (t_light *)scene.lights->content;
// 	vect = ray.ori;
// 	ray.dir = vec3_normalize(vec3_sub(light->obj->pos, vect));
// 	unit = new_vec3(ray.dir.x * ratio, ray.dir.y * ratio, ray.dir.z * ratio);
// 	vect = vec3_add(ray.ori, unit);
// 	i = 0;
// 	while (i <= ray.len)
// 	{
// 		temp = scene.shapes;
// 		// while (temp != NULL)
// 		// {
// 		// 	if (is_in_bound((t_shape *)temp->content, vect))
// 		// 	{
// 		// 		*color = 0;
// 		// 		return ;
// 		// 	}
// 		// 	temp = temp->next;
// 		// }
// 		temp = scene.lights;
// 		if (is_in_light(light, vect) && i < light->radius)
// 		{
// 			*color = color_shift_int(*color, light->color, 1.0 - i / light->radius);
// 			return ;
// 		}
// 		vect = vec3_add(vect, unit);
// 		i += ratio;
// 	}
// 	return ;
// } 
