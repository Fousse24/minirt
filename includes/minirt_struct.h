/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_struct.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 12:07:49 by sfournie          #+#    #+#             */
/*   Updated: 2022/02/10 15:16:43 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_STRUCT_BONUS_H
# define CUB3D_STRUCT_BONUS_H
# define UI_ELEMS	2
# define MAX_ENEMY	300
# define MAX_DOOR	200

# include	"libft.h"

/* Typedefs */
typedef struct s_mlx		t_mlx;
typedef struct s_settings	t_sett;
typedef struct s_img		t_img;

typedef struct s_scene		t_scene;
typedef struct s_camera		t_cam;
typedef struct s_light		t_light;

typedef struct s_obj		t_obj;
typedef struct s_shape		t_shape;
typedef struct s_sphere		t_sp;
typedef struct s_cylinder	t_cyl;
typedef struct s_rectancle	t_rect;

typedef struct s_material	t_mat;

typedef struct s_vec3		t_vec3;
typedef struct s_ray3		t_ray3;
typedef struct s_coll		t_coll;

typedef struct s_rgb		t_rgb;

/* Enums definition*/
enum e_obj_type
{
	NONE = 0,
	SHAPE,
	LIGHT,
	CAMERA
};

enum e_shape
{
	SPHERE = 0,
	CYLINDER,
	RECTANGLE,
	PLANE
};

enum e_light
{
	AMBIANT = 0,
	DIFFUSE,
	HARD
};

/* Structures definition */
struct s_vec3
{
	float	x;
	float	y;
	float	z;
};

struct s_ray3
{
	t_vec3	ori;
	t_vec3	dir;
	float	len;
};

struct s_rgb
{
	int		r;
	int		g;
	int		b;
};

struct s_coll
{
	t_vec3	pos;
	void	*obj;
};

struct s_img
{
	void	*ptr;
	char	*addr;
	int		bpp;
	int		bytes;
	int		data_w;
	int		width;
	int		endian;
	int		height;
};

struct s_mlx
{
	void	*mlx;
	void	*win;
	t_img	img;
	int		init;
};

struct s_obj
{
	int			type;
	int			enabled;
	t_vec3		pos;
	t_vec3		orient;
};

struct s_shape
{
	t_obj		*obj;
	int			type;
	float		radius;
	t_vec3		size;
	int			color;
	int			(*is_in_bound)(void *obj, t_vec3 point);
	t_vec3		(*get_intersection)(void *obj, t_vec3 p1, t_vec3 p2);
};

struct s_light
{
	t_obj	*obj;
	int		type;
	float	force;
	float	radius;
	int		color;
};

struct s_scene
{
	t_light	*light_amb;
	t_dlst	*lights;
	t_dlst	*shapes;
	t_cam	*camera;
	t_shape	*selection;
};

struct s_camera
{
	t_vec3	pos;
	int		hp;
	float	rot;
	float	vel_r;
	float	vel_l;
	float	vel_u;
	float	vel_d;
	float	vel_z;
	float	turn_l;
	float	turn_r;
};

struct s_sett
{
	int			mouse_x;
	int			mouse_y;
};

#endif