/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcollet <gcollet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 12:07:49 by sfournie          #+#    #+#             */
/*   Updated: 2021/12/23 18:54:36 by gcollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include	<stdarg.h>
# include	<stdio.h>
# include	<limits.h>
# include	<stddef.h>
# include	<stdlib.h>
# include	<unistd.h>
# include	<math.h>
# include	<complex.h>
# include	<mlx.h>
# include	"../libft/libft.h"

# define WIN_W 		1000
# define WIN_H		500
# define FPS		30
# define MLX_CD		10000

# define ESC 			65307
# define SPACE_KEY 		49
# define W_KEY			119
# define A_KEY			97
# define S_KEY			115
# define D_KEY			100
# define SPEED			0.4
# define TURN_SPEED		5.0
# define MOUSE_TURN		0.5
# define VIEW			90
# define TILE_SIZE		50

# define WHITE			0xffffff
# define BLACK			0x000000
# define RED			0xFF0000
# define FLOOR_C		0x888888
# define CEILING_C		0x222222
# define WALL_C_NO		0x00aa50
# define WALL_C_SO		0x005090
# define WALL_C_WE		0x0020bb
# define WALL_C_EA		0x0000ff
# define YELLOW			0xf0de18



typedef struct s_mlx	t_mlx;
typedef struct s_img	t_img;

typedef struct s_game	t_game;
typedef struct s_map	t_map;

typedef struct s_wall	t_wall;
typedef struct s_player	t_player;
typedef struct s_cam	t_cam;
typedef struct s_obj	t_obj;

typedef struct s_vect	t_vect;

typedef struct s_coll	t_coll;

typedef struct s_pos	t_pos;
typedef struct s_size	t_size;

typedef struct s_rgb	t_rgb;

enum e_obj_type
{
	WALL,
	PLAYER,
	FLOOR,
	CEILING
};

enum e_dir
{
	NORTH,
	SOUTH,
	WEST,
	EAST
};

struct s_pos
{
	double	x;
	double	y;
	double	z;
};

struct s_size
{
	double	x;
	double	y;
	double	z;
};

struct s_rgb
{
	int	r;
	int	g;
	int	b;
};

struct s_coll
{
	t_pos	pos;
	int		type;
};

struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
};

struct s_vect
{
	double	x;
	double	y;
	double	z;
};

struct s_mlx
{
	void	*mlx;
	void	*win;
	t_img	img;
	int		init;
};

struct s_map
{
	int	width;
	int	height;
	int *map;
};

struct s_obj
{

};

struct s_player
{
	t_pos	pos;
	int		hp;
	double	rot;
	double	vel;
};

struct s_game
{
	t_map		map;
	t_player	player;
	t_mlx		*mlx;
	int			screen_x;
	int			screen_y;
};

t_game	g_game;

/* Generic structure creator */
t_pos	new_pos(double x, double y, double z);
t_size	new_size(double x, double y, double z);
t_vect	new_vect(double x, double y, double z);
t_coll	new_collider(t_pos pos, int type);

/* MLX */
t_mlx	*get_mlx(void);

/* Image and draw */
void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color);
void	mlx_clear_img(t_mlx *mlx);
int 	raycast_draw(t_pos pos, double rot, double dist);
int 	raycast_draw_all(t_pos pos, double rot, double dist, double view);

/* Color */
int	get_t(int trgb);
int	get_r(int trgb);
int	get_g(int trgb);
int	get_b(int trgb);

t_rgb	color_int_to_rgb(int color);
int		color_rgb_to_int(t_rgb rgb);
t_rgb	color_shift_rgb(t_rgb base, t_rgb shift, double force);
int		color_shift_int(int base, int shift, double force);

/* Inputs */
int		key_press(int key, t_mlx *mlx);
int		key_release(int key, t_mlx *mlx);
int		mouse_handler(int x, int y);
int		mouse_move(int x, int y, t_mlx *mlx);


/* Position and movement */
t_pos	move_pos(t_pos pos, double rot, double dist);
int		rotate_player(t_player *player, double rot);
int		change_player_pos(t_player *player);

/* Collision */
int		check_collision_y(int x, int y, int size);
int		check_collision_x(int x, int y, int size);
t_pos	check_collisions(int x, int y, int size);

/* Math */
double	deg_to_rad(double angle);

#endif