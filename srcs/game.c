/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fousse <fousse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 18:53:35 by fousse            #+#    #+#             */
/*   Updated: 2022/01/04 17:16:15 by fousse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"cub3d.h"

void	init_game(t_game *game)
{	
	int i;
	int tiles[64] = {
		1,1,1,1,1,1,1,1, 
		1,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,1,
		1,0,1,0,1,0,0,1,
		1,0,0,0,0,0,0,1,
		1,0,1,0,1,0,0,1,
		1,0,0,0,0,0,0,1,
		1,1,1,1,1,1,1,1,
	};
	int tiles_coll[64] = {
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
	};
	static char *TEXTURE[4] = {"textures/T_1.xpm", "textures/T_2.xpm",\
							"textures/T_3.xpm", "textures/T_4.xpm"};

	i = 0;
	game->player.pos.x = 190;
	game->player.pos.y = 121;
	game->player.rot = 270;
	game->player.hp = 100;
	game->map.width = 8;
	game->map.size = 64;
	game->map.height = 8;
	game->map.tiles = copy_map(tiles, 64);
	game->map.tiles_coll = copy_map(tiles_coll, 64);
	game->mlx = get_mlx();
	mlx_get_screen_size(game->mlx->mlx, &game->screen_x, &game->screen_y);
	mlx_mouse_hide(game->mlx->mlx, game->mlx->win);
	while (i < 4)
	{
		game->texture[i].img = mlx_xpm_file_to_image(game->mlx->mlx, TEXTURE[i], &game->texture[i].width, &game->texture[i].height);
		game->texture[i].addr = mlx_get_data_addr(game->texture[i].img, &game->texture[i].bpp,
					&game->texture[i].width, &game->texture[i].endian);
		i++;
	}
}

// for my parsing
void	init_game_new(t_game *game)
{
	game->player.pos.x = 0;
	game->player.pos.y = 0;
	game->player.rot = 0;
	game->player.hp = 0;
	game->map.width = 0;
	game->map.size = 0;
	game->map.height = 0;
	game->map.tiles = NULL;
	game->map.tiles_coll = NULL;
	game->mlx = get_mlx();
	mlx_get_screen_size(game->mlx->mlx, &game->screen_x, &game->screen_y);
	mlx_mouse_hide(game->mlx->mlx, game->mlx->win);
}

void	exit_game(t_game *game, int exit_code)
{
	game = NULL;
	exit(exit_code);
}
