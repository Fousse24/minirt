/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3_math.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 09:35:03 by fousse            #+#    #+#             */
/*   Updated: 2022/02/10 14:32:47 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minirt.h"

float	vec3_len_nosqr(t_vec3 vect)
{
	float	len;

	len = powf(vect.x, 2) + powf(vect.y, 2) + powf(vect.z, 2);
	return (len);
}

float	vec3_len(t_vec3 vect)
{
	float	len;

	len = sqrtf(powf(vect.x, 2) + powf(vect.y, 2) + powf(vect.z, 2));
	return (len);
}

t_vec3	vec3_add(t_vec3 vect1, t_vec3 vect2)
{
	t_vec3	result;

	result.x = vect1.x + vect2.x;
	result.y = vect1.y + vect2.y;
	result.z = vect1.z + vect2.z;
	return (result);
}

t_vec3	vec3_sub(t_vec3 vect1, t_vec3 vect2)
{
	t_vec3	result;

	result.x = vect1.x - vect2.x;
	result.y = vect1.y - vect2.y;
	result.z = vect1.z - vect2.z;
	return (result);
}

t_vec3	vec3_normalize(t_vec3 vect)
{
	t_vec3	norm;
	float	len;

	len = vec3_len(vect);
	norm.x = vect.x/len;
	norm.y = vect.y/len;
	norm.z = vect.z/len;
	return (norm);
}
