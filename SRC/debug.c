/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdelsie <vdelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 14:55:39 by vdelsie           #+#    #+#             */
/*   Updated: 2020/01/23 15:06:26 by vdelsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void    printf_map(t_map *map)
{
    int i;

    ft_printf("MAP height=%d width=%d\n", map->height, map->width);
    i = -1;
    while(++i < map->height)
    {
        ft_printf("%s\n", map->array[i]);
    }
    print_heatmap(map);
}

void    printf_player_info(t_ginfo *ginfo)
{
    ft_printf("{robot} I'm a player %d\n", ginfo->player);
    ft_printf("{robot} This is my cell %d\n", ginfo->me);
    ft_printf("{robot} Enemy cell %d\n,", ginfo->enemy);
    ft_printf("\n");
}

void		print_shape(t_shape *shape)
{
	int		i;

	ft_printf("{yellow}SHAPE: height=%d, width=%d\n",
		shape->height, shape->width);
	ft_printf("height_r=%d, width_r=%d, x_offset=%d, y_offset=%d\n",
		shape->height_r, shape->width_r, shape->x_offset, shape->y_offset);
	i = -1;
	while (++i < shape->height)
	{
		ft_printf("%s\n", shape->array[i]);
	}
	ft_printf("{reset}\n");
}

void		print_heatmap(t_map *map)
{
	int		i;
	int		j;

	ft_printf("{red}HEAT MAP\n");
	j = -1;
	while (++j < map->height)
	{
		i = -1;
		while (++i < map->width)
		{
			ft_printf("%d ", map->heat[j][i]);
		}
		ft_printf("\n");
	}
	ft_printf("{reset}\n");
}
