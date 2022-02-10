/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_bound.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 19:17:29 by fousse            #+#    #+#             */
/*   Updated: 2022/02/10 14:57:37 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minirt.h"

int	is_in_bound(t_shape *shape, t_vec3 pos)
{
	if (shape->type == SPHERE)
		return (is_in_sphere(shape, pos));
	return (FALSE);
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
