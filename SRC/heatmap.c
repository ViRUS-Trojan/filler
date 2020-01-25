/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heatmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdelsie <vdelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 14:51:07 by vdelsie           #+#    #+#             */
/*   Updated: 2020/01/25 17:55:08 by cyuriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "filler.h"

void     build_heatmap(t_map *map, t_ginfo *ginfo)
{
    int i;
    int j;
    int c;

    map->heat = (int**)ft_memalloc(sizeof(int *) * map->height);
    j = -1;
    while (++j < map->height)
    {
        map->heat[j] = (int*)ft_memalloc(sizeof(int) * map->width);
        i = -1;
        while(++i < map->width)
		{
			map->heat[j][i] = (map->array[j][i] == ginfo->enemy) ? -1 : 0;
			c = map->heat[j][i];///////////не забудь убрать эту хуйню
		}

    }
    populate_heat(map, ginfo, 0);
}

void    populate_heat(t_map *map, t_ginfo *ginfo, int current)
{
    int reapet;
    int i;
    int j;

    reapet = 0;/////////что за хак
    j = -1;
    while(++j < map->height)
    {
        i = -1;
        while(++i < map->height)
        {
            if (map->heat[j][i] == -1)
            reapet = 1;
            if (map->heat [j][i] == current)
            set_neighbors(map, i, j, current + 1);
        }
    }
    if (reapet)
        populate_heat(map, ginfo, current + 1);
    print_output(map);
}

void    set_neighbors(t_map *map, int i, int j, int new_val)
{
	if (j && j < map->height && i && i < map->width)
	{
		if (0 <= j - 1 && map->heat[j - 1][i] == - 1)
			map->heat[j - 1][i] = new_val;
	}
	if (j && j < map->height && i && i < map->width)
	{
		if (j + 1 < map->height &&  map->heat[j + 1][i] == - 1)
			map->heat[j + 1][i] = new_val;
	}
	if (j && j < map->height && i && i < map->width)
	{
		if (0 <= j - 1 && map->heat[j][i + 1] == - 1)
			map->heat[j][i + 1] = new_val;
	}

}