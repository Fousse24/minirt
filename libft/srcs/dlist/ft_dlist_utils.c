/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 16:25:11 by sfournie          #+#    #+#             */
/*   Updated: 2021/11/24 16:25:15 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"dlist.h"

// Return the amount of nodes in $dlst
int	ft_dlst_size(t_dlst *dlst)
{
	size_t	size;
	t_dlst	*temp;

	size = 0;
	temp = dlst;
	while (temp != 0)
	{
		temp = temp->next;
		size++;
	}
	return (size);
}
