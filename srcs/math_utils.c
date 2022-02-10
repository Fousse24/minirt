/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 18:44:54 by fousse            #+#    #+#             */
/*   Updated: 2022/02/07 18:25:26 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minirt.h"

float	math_pytha(float x, float y)
{
	return (sqrtf(powf(x, 2.0) + powf(y, 2.0)));
}

float	math_pytha3(float x, float y, float z)
{
	return (sqrtf(powf(x, 2.0) + powf(y, 2.0) + powf(z, 2.0)));
}

/*
*	Return the draw distance based on the player position and rotation.
*	This is used to prevent fish-eye.
*/
// double	get_draw_distance(t_pos pos, double rot, t_pos pixel, double angle)
// {
// 	double	d_x;
// 	double	d_y;
// 	double	sin_result;
// 	double	cos_result;
// 	double	dist;

// 	d_x = (int)fabs(pos.x - pixel.x);
// 	d_y = (int)fabs(pos.y - pixel.y);
// 	cos_result = fabs(cos(deg_to_rad((int)rot)));
// 	sin_result = fabs(sin(deg_to_rad((int)rot)));
// 	dist = d_x * cos_result + d_y * sin_result;
// 	dist = dist * cos((deg_to_rad((int)angle)));
// 	dist = (50 * g_game.res_h) / dist;
// 	return (dist);
// }
