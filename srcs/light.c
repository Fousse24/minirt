/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 19:17:29 by fousse            #+#    #+#             */
/*   Updated: 2022/02/10 15:24:01 by sfournie         ###   ########.fr       */
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
