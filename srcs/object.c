/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 19:17:29 by fousse            #+#    #+#             */
/*   Updated: 2022/02/10 13:45:37 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minirt.h"

void	init_obj(t_obj *obj)
{
	obj->enabled = FALSE;
	obj->orient = new_vec3(0, 0, 0);
	obj->pos = new_vec3(0, 0, 0);
	obj->type = NONE;
}

t_obj	*new_obj(void)
{
	t_obj	*obj;

	obj = (t_obj *)ft_calloc(1, sizeof(t_obj));
	init_obj(obj);
	return (obj);
}
