/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing copy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 09:06:09 by gcollet           #+#    #+#             */
/*   Updated: 2022/02/10 16:46:10 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int    solve_quadra(double a, double b, double c, double *t0, double *t1)
{
    double delta;
    double q;
    double buffer;

    delta = b * b - 4*a*c;
    if (delta < 0)
        return (0);
    else if (delta == 0)
    {
        *t0 = -0.5 * b / a;
        *t1 = -0.5 * b / a;
    }
    else
    {
        if (b > 0)
            q = -1 * (b + sqrt(delta)) / 2;
        else
        q = -1 * (b - sqrt(delta)) / 2;
        *t0 = q / a;
        *t1 = c / q;
    }
    if (*t0 > *t1)
    {
        buffer = *t0;
        *t0 = *t1;
        *t1 = buffer;
    }
    return (1);
}

int get_roots(double *t0, double *t1, t_ray r, t_sphere s)
{
    t_vec3    v;
    double a;
    double b;
    double c;

    v = new_vec_substract(r.origin, s.origin);
    a = get_dot_product(r.direction, r.direction);
    b = 2.0 * get_dot_product(r.direction, v);
    c = get_dot_product(v, v) - (s.rayon * s.rayon);
    if (solve_quadra(a, b, c, t0, t1) == 0)
        return (0);
    return (1);
}

int    intersect_sphere(t_ray r, t_sphere s, double *t)
{
    double t0;
    double t1;

    if (get_roots(&t0, &t1, r, s) == 0)
        return (0);
    if (t0 < 0)
    {
        t0 = t1;
        if (t0 < 0)
            return (0);
    }
    *t = t0;
    return (1);
}

int    ft_print_circle(t_main *main)
{
    int    i = 0;
    int    j;
    t_mlx *mlx;
    t_ray r;
    double fov = 60 * M_PI / 180;
    t_sphere sphere;
    double t = 0;

    r.origin.x = 600 /2;
    r.origin.y = 300;
    r.origin.z = 300;

    sphere.origin.x = 300;
    sphere.origin.y = 300;
    sphere.origin.z = -55;
    sphere.rayon = 50;

    mlx = get_mlx();
        while (i < mlx->height)
        {
            j = 0;
            while (j < mlx->width)
            {
                r.direction.x = j- mlx->width/2;
                r.direction.y = i - mlx->height /2;
                r.direction.z = -mlx->width / (2 * tan(fov / 2));
                new_vector(r.direction.x, r.direction.y, r.direction.z);
                mod_vec_normalize(r.direction);
                if (intersect_sphere(r, sphere, &t))
                    my_mlx_pixel_put(mlx, i, j, 14651212); // colore le rond en orange
                else
                    my_mlx_pixel_put(mlx, i, j, 0xff00ff); // colore le fonds en rose

                j++;
            }
            i++;
    }
    mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
    return (1);
}
