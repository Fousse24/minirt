/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 19:41:15 by fousse            #+#    #+#             */
/*   Updated: 2022/02/10 18:29:23 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minirt.h"

int	key_press(int key)
{
	double	modifier;

	modifier = ((double)WIN_H * (double)WIN_W) / 1000000.0;
	// if (key == LEFT_KEY)
	// 	g_game.player.turn_l = TURN_SPEED * modifier;
	// if (key == RIGHT_KEY)
	// 	g_game.player.turn_r = -TURN_SPEED * modifier;
	// if (key == W_KEY)
	// 	g_game.player.vel_u = SPEED * modifier;
	// if (key == S_KEY)
	// 	g_game.player.vel_d = -SPEED * modifier;
	// if (key == A_KEY)
	// 	g_game.player.vel_l = SPEED * modifier;
	// if (key == D_KEY)
	// 	g_game.player.vel_r = -SPEED * modifier;
	return (key);
}

int	key_release(int key)
{
	if (key == W_KEY)
	{
		if (get_scene()->selection != NULL)
		{
			get_scene()->selection->obj->pos.y -= 5;
		}
	}
	if (key == S_KEY)
	{
		if (get_scene()->selection != NULL)
		{
			get_scene()->selection->obj->pos.y += 5;
		}
	}
	if (key == A_KEY)
	{
		if (get_scene()->selection != NULL)
		{
			get_scene()->selection->obj->pos.x -= 5;
		}
	}
	if (key == D_KEY)
	{
		if (get_scene()->selection != NULL)
		{
			get_scene()->selection->obj->pos.x += 5;
		}
	}
	// if (key == A_KEY)
	// 	g_game.player.vel_l = 0;
	// if (key == S_KEY)
	// 	g_game.player.vel_d = 0;
	// if (key == D_KEY)
	// 	g_game.player.vel_r = 0;
	// if (key == LEFT_KEY)
	// 	g_game.player.turn_l = 0;
	// if (key == RIGHT_KEY)
	// 	g_game.player.turn_r = 0;
	if (key == ESC)
		quit_handler();
	return (key);
}

int	mouse_handler(int keycode, int x, int y)
{	
	t_dlst	*temp;
	t_vec3	vect;

	vect = new_vec3(x, y, 0);
	if (keycode == 1)
	{
		vect.z = 0;
		while (vect.z < 300)
		{
			temp = get_scene()->shapes;
			while (temp != NULL)
			{
				if (is_in_sphere((t_shape *)temp->content, vect))
				{
					get_scene()->selection = (t_shape *)temp->content;
					break;
				}
				temp = temp->next;				
			}
			vect.z++;
		}
		//ft_dlst_add_front(&get_scene()->shapes, ft_dlst_new_node(new_sphere(new_vec3(x, y, 100), 50, 0xFFFFFF)));
	}
	get_scene()->selection = (t_shape *)get_scene()->shapes->content;
	if (keycode == 4 && get_scene()->selection)
		get_scene()->selection->obj->pos.z += 5;
	if (keycode == 5 && get_scene()->selection)
		get_scene()->selection->obj->pos.z -= 5;
	return (1);
}

int	quit_handler(void)
{
	exit(0);
	return (0);
}
