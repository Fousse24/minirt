/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 12:07:49 by sfournie          #+#    #+#             */
/*   Updated: 2022/02/10 18:53:54 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H
# include	<stdarg.h>
# include	<stdio.h>
# include	<limits.h>
# include	<stddef.h>
# include	<stdlib.h>
# include	<unistd.h>
# include	<math.h>
# include	<fcntl.h>
# include	<mlx.h>
# include	"libft.h"
# include	"minirt_struct.h"

# define FALSE		0
# define TRUE		1

# define WIN_W 		400
# define WIN_H		400
# define RENDER_W	1720
# define RENDER_H	880

/* Key for mac */
# define ESC 			53
# define SPACE_KEY 		49
# define A_KEY			0
# define D_KEY			2
# define E_KEY			14
# define M_KEY			46
# define R_KEY	 		15
# define S_KEY			1
# define W_KEY			13
# define SHIFT_KEY		257
# define RIGHT_KEY		124
# define LEFT_KEY		123
# define UP_KEY			126
# define DOWN_KEY		125

/* MLX */
t_mlx	*get_mlx(void);

/* Scene */
t_scene	*get_scene(void);

/* Object */
t_obj	*new_obj(void);

/* Image */
void	new_img(void *mlx, t_img *img, int width, int height);
void	fill_img(t_img img, int color);
void	img_pixel_put(t_img img, int x, int y, int color);

/* Vector 3D */
t_vec3	new_vec3(float x, float y, float z);
t_vec3	move_vec3(t_vec3 base, t_vec3 dir, float dist);
t_vec3	vec3_normalize(t_vec3 vect);
float	vec3_len(t_vec3 vect);
float	vec3_len_nosqr(t_vec3 vect);
t_vec3	vec3_add(t_vec3 vect1, t_vec3 vect2);
t_vec3	vec3_sub(t_vec3 vect1, t_vec3 vect2);
t_vec3	vec3_prod(t_vec3 vect1, t_vec3 vect2);
t_vec3	vec3_prod_n(t_vec3 vect1, double n);
float	vec3_dot_product(t_vec3 vec1, t_vec3 vec2);

/* Raytracing */
int		raytracing(t_vec3 ori, t_scene scene, t_mlx	*mlx);
int		raytrace(t_ray3	ray, float ratio, t_scene scene);
void	shadowtracing(t_ray3 ray, float ratio, t_scene scene, int *color);

/* Light */
t_light	*new_light(int type, int color, float force, float rad);
t_light	*new_diffuse_light(void);
t_light	*new_ambiant_light(void);

/* Shape */
t_shape	*new_shape(void);
t_shape	*new_sphere(t_vec3 origin, float radius, int color);
void	*new_cylinder();
void	*new_rectangle();
void	*new_plane();
int		is_in_bound(t_shape *shape, t_vec3 pos);
int		is_in_sphere(t_shape *shape, t_vec3 pos);
int		is_in_light(t_light *light, t_vec3 pos);

int		is_intersecting(t_ray3 ray, t_shape shape, double *dist);
int		intersect_sphere(t_ray3 ray, t_shape shape, double *dist);
int	intersect_light(t_ray3 ray, t_light light, double *dist);


/* Color */
int		color_valid_rgb(t_rgb rgb);
int		color_get(t_img img, int x, int y);
t_rgb	new_rgb(int r, int g, int b);
int		get_t(int trgb);
int		get_r(int trgb);
int		get_g(int trgb);
int		get_b(int trgb);
t_rgb	color_int_to_rgb(int color);
int		color_rgb_to_int(t_rgb rgb);
t_rgb	color_shift_rgb(t_rgb base, t_rgb shift, double force);
int		color_shift_int(int base, int shift, double force);

/* Input */
int	key_press(int key);
int	key_release(int key);
int	quit_handler(void);
int	mouse_handler(int keycode, int x, int y);

/* Math */
float	math_pytha(float x, float y);
float	math_pytha3(float x, float y, float z);


int    solve_quadra(double a, double b, double c, double *t0, double *t1);
int get_roots(double *t0, double *t1, t_ray3 r, t_shape s);

#endif