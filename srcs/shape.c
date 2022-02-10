/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 19:17:29 by fousse            #+#    #+#             */
/*   Updated: 2022/02/10 13:45:37 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minirt.h"

void	init_shape(t_shape *shape)
{
	shape->obj = new_obj();
	shape->is_in_bound = NULL;
	shape->get_intersection = NULL;
	shape->radius = 0;
	shape->size = new_vec3(0, 0, 0);
	shape->color = 0;
	shape->type = NONE;
}

t_shape	*new_shape(void)
{
	t_shape	*shape;

	shape = (t_shape *)ft_calloc(1, sizeof(t_shape));
	init_shape(shape);
	return (shape);
}

t_shape	*new_sphere(t_vec3 origin, float radius, int color)
{
	t_shape	*shape;

	shape = new_shape();
	init_shape(shape);
	shape->obj->pos = origin;
	shape->radius = radius;
	shape->type = SPHERE;
	shape->color = color;
	return (shape);
}
