/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 19:17:29 by fousse            #+#    #+#             */
/*   Updated: 2022/02/11 10:32:23 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minirt.h"

void	init_light(t_light *light)
{
	light->obj = new_obj();
	light->color = 0;
	light->force = 0;
	light->radius = 0;
	light->type = 0;
}

t_light	*new_light(int type, int color, float force, float rad)
{
	t_light	*light;

	light = (t_light *)ft_calloc(1, sizeof(t_light));
	init_light(light);
	light->type = type;
	light->color = color;
	light->force = force;
	light->radius = rad;
	return (light);
}

int	is_in_light(t_light *light, t_vec3 pos)
{
	float	rad;
	t_vec3	center;

	rad = light->radius;
	center = light->obj->pos;
	if (vec3_len_nosqr(vec3_sub(pos, center)) <= 2)
	{
		return (TRUE);
	}
	return (FALSE);
}

int get_light_roots(double *t0, double *t1, t_ray3 r, t_light s)
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

int	intersect_light(t_ray3 ray, t_light light, double *dist)
{
	*dist = vec3_len_nosqr(vec3_sub(light.obj->pos, ray.ori));

	if (*dist < powf(light.radius, 2))
		return (1);
	return (0);
	// double t0;
    // double t1;

    // if (get_light_roots(&t0, &t1, ray, light) == 0)
    //     return (0);
    // if (t0 < 0)
    // {
    //     t0 = t1;
    //     if (t0 < 0)
    //         return (FALSE);
    // }
    // *dist = t0;
    // return (TRUE);
}
