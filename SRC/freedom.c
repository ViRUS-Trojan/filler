/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freedom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdelsie <vdelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 14:55:11 by vdelsie           #+#    #+#             */
/*   Updated: 2020/01/23 14:18:50 by vdelsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	free_all(t_ginfo *ginfo)
{
	free_map(&(ginfo->map));
	free_shape(&(ginfo->shape));
}

void	free_map(t_map *map)
{
	int	i;

	i = -1;
	while (++i < map->height)
	{
		ft_strdel(map->array + i);
		ft_memdel((void **)map->heat + i);
	}
	ft_memdel((void **)&(map->array));
	ft_memdel((void **)&(map->heat));
}

void	free_shape(t_shape *shape)
{
	int	i;

	i = -1;
	while (++i < shape->height)
		ft_strdel(shape->array + i);
	ft_memdel((void **)&(shape->array));
}
