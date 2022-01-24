/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcollet <gcollet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 19:41:15 by fousse            #+#    #+#             */
/*   Updated: 2022/01/24 15:35:46 by gcollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"cub3d.h"

/* int	mouse_handler(int x, int y)
{
	static int	mouse_x = INT_MIN;
	static int	mouse_y = INT_MIN;

	mlx_mouse_get_pos(get_mlx()->win, &x, &y);
	if (mouse_x != x && mouse_x != INT_MIN)
		rotate_player(&g_game.player, (mouse_x - x) * MOUSE_TURN);
	if (mouse_y != y && mouse_y != INT_MIN)
		g_game.player.pos.z += (double)(mouse_y - y) * 1;
	mouse_x = x;
	mouse_y = y;
	return (0);
} */

int	key_press(int key)
{
	double	modifier;

	modifier = ((double)WIN_H * (double)WIN_W) / 1000000.0;
	if (key == SPACE_KEY)
		g_game.ui_elems[UI_GUN].sprite.active = 1;
	if (key == LEFT_KEY)
		g_game.player.turn_l = TURN_SPEED * modifier;
	if (key == RIGHT_KEY)
		g_game.player.turn_r = -TURN_SPEED * modifier;
	if (key == W_KEY)
		g_game.player.vel_u = SPEED * modifier;
	if (key == S_KEY)
		g_game.player.vel_d = -SPEED * modifier;
	if (key == A_KEY)
		g_game.player.vel_l = SPEED * modifier;
	if (key == D_KEY)
		g_game.player.vel_r = -SPEED * modifier;
	if (key == DOWN_KEY)
		g_game.player.vel_z = -25;
	if (key == UP_KEY)
		g_game.player.vel_z = 25;
	if (key == SHIFT_KEY)
		g_game.player.vel_z += JUMP_FORCE;
	if (key == E_KEY)
		interact_door();
	return (key);
}

int	key_release(int key)
{
	if (key == SPACE_KEY)
        start_animation(&g_game.ui_elems[UI_GUN].sprite);
	if (key == W_KEY)
		g_game.player.vel_u = 0;
	if (key == A_KEY)
		g_game.player.vel_l = 0;
	if (key == S_KEY)
		g_game.player.vel_d = 0;
	if (key == D_KEY)
		g_game.player.vel_r = 0;
	if (key == LEFT_KEY)
		g_game.player.turn_l = 0;
	if (key == RIGHT_KEY)
		g_game.player.turn_r = 0;
	if (key == DOWN_KEY)
		g_game.player.vel_z += 25;
	if (key == UP_KEY)
		g_game.player.vel_z -= 25;
	if (key == ESC)
		exit_game(&g_game, 0);
	if (key == M_KEY)
		g_game.toggle_map *= -1;
	return (key);
}

int	quit_handler(void)
{
	exit_game(&g_game, 0);
	return (0);
}
