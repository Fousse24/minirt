/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_bound.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 19:17:29 by fousse            #+#    #+#             */
/*   Updated: 2022/02/10 17:28:43 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minirt.h"

int	is_in_bound(t_shape *shape, t_vec3 pos)
{
	if (shape->type == SPHERE)
		return (is_in_sphere(shape, pos));
	return (FALSE);
}

int	is_intersecting(t_ray3 ray, t_shape shape, double *dist)
{
	if (shape.type == SPHERE)
		return (intersect_sphere(ray, shape, dist));
	return (FALSE);
}

int	intersect_sphere(t_ray3 ray, t_shape shape, double *dist)
{
	double t0;
    double t1;

    if (get_roots(&t0, &t1, ray, shape) == 0)
        return (0);
    if (t0 < 0)
    {
        t0 = t1;
        if (t0 < 0)
            return (FALSE);
    }
    *dist = t0;
    return (TRUE);
}

int	is_in_sphere(t_shape *shape, t_vec3 pos)
{
	float	rad;
	t_vec3	center;

	rad = shape->radius;
	center = shape->obj->pos;
	if (vec3_len_nosqr(vec3_sub(pos, center)) <= powf(rad, 2))
	{
		return (TRUE);
	}
	return (FALSE);
}
