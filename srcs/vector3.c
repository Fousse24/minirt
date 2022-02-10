/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 09:35:03 by fousse            #+#    #+#             */
/*   Updated: 2022/02/10 13:45:37 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minirt.h"

t_vec3	new_vec3(float x, float y, float z)
{
	t_vec3	vect;

	vect.x = x;
	vect.y = y;
	vect.z = z;
	return (vect);
}

t_vec3	move_vec3(t_vec3 base, t_vec3 dir, float dist)
{
	// t_pos	new_pos;

	// if (dir)
	// 	rot += 90;
	// new_pos.x = pos.x + dist * cos(deg_to_rad(rot));
	// new_pos.y = pos.y + dist * -sin(deg_to_rad(rot));
	// new_pos.z = pos.z + 0;
	// return (new_pos);
}

// int	change_player_pos(t_plyr *player, double vel, int dir)
// {
// 	t_pos	pos;
// 	t_pos	new_pos;

// 	pos.x = player->pos.x;
// 	pos.y = player->pos.y;
// 	new_pos = move_pos(pos, player->rot, vel, dir);
// 	player->pos.x = new_pos.x;
// 	player->pos.y = new_pos.y;
// 	return (0);
// }

// void	move_player(void)
// {
// 	t_plyr	*p;

// 	p = &g_game.player;
// 	if (p->vel_u + p->vel_d && p->vel_r + p->vel_l)
// 	{
// 		change_player_pos(p, (p->vel_u + p->vel_d) * 0.707, 0);
// 		change_player_pos(p, (p->vel_r + p->vel_l) * 0.707, 1);
// 	}
// 	else
// 	{
// 		if (p->vel_u + p->vel_d)
// 			change_player_pos(p, p->vel_u + p->vel_d, 0);
// 		if (p->vel_r + p->vel_l)
// 			change_player_pos(p, p->vel_r + p->vel_l, 1);
// 	}
// 	if (p->turn_l + p->turn_r)
// 		rotate_player(p, p->turn_l + p->turn_r);
// }
