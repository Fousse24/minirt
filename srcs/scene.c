/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 19:17:29 by fousse            #+#    #+#             */
/*   Updated: 2022/02/07 17:56:08 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minirt.h"

void	init_scene(t_scene *scene)
{
	scene->camera = NULL;
	scene->light_amb = NULL;
	scene->lights = NULL;
	scene->shapes = NULL;
	scene->selection = NULL;
}

t_scene	*get_scene(void)
{
	static t_scene	*scene;

	if (!scene)
	{
		scene = (t_scene *)ft_calloc(1, sizeof(t_scene));
		if (!scene)
			return (NULL);
		init_scene(scene);
	}
	return (scene);
}
