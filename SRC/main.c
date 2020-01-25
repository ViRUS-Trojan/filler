/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdelsie <vdelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 14:47:26 by vdelsie           #+#    #+#             */
/*   Updated: 2020/01/25 17:58:35 by cyuriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "filler.h"

void		print_output(t_map *map)
{
	int height = -1;
	int width = -1;
	while (++height < map->height)
	{
		width = -1;
		while (++width < map->width)
			ft_putnbr(map->heat[height][width]);
		ft_putchar('\n');
	}
}

int			main(void)
{
	t_ginfo	ginfo;

	ft_bzero(&ginfo, sizeof(t_ginfo));
	get_player_info(&ginfo);
	while (make_my_move(&ginfo));
	return (0);
}

int			make_my_move(t_ginfo *ginfo)
{
	char	*line;

	line = 0;
	get_next_line(0, &line);
	if (!ft_strnequ(line, "Plateau", 7))
	{
		ft_strdel(&line);
		return (0);
	}
	read_map(&(ginfo->map), line, ginfo);
	mini_shape(&(ginfo->shape));
	give_answer(ginfo);
	free_all(ginfo);
	return (1);
}

void		give_answer(t_ginfo *ginfo)
{
	t_pos	pos;
	t_pos	champ;

	champ.value = MAX_VALUE;
	champ.y = 0;
	champ.x = 0;
	pos.y = -1;
	while (++pos.y + ginfo->shape.height_r <= ginfo->map.height)
	{
		pos.x = -1;
		while (++pos.x + ginfo->shape.width_r <= ginfo->map.width)
		{
			if (try_this_pos(&pos, ginfo) && pos.value < champ.value)
				ft_memcpy(&champ, &pos, sizeof(t_pos));
		}
	}
	ft_printf("%d %d\n", champ.y + ginfo->shape.y_offset,
		champ.x + ginfo->shape.x_offset);
}

int			try_this_pos(t_pos *pos, t_ginfo *ginfo)
{
	int		overlap;
	int		i;
	int		j;

	pos->value = 0;
	overlap = 0;
	j = -1;
	while (++j < ginfo->shape.height_r)
	{
		i = -1;
		while (++i < ginfo->shape.width_r)
		{
			if (ginfo->shape.array[j][i] == '*')
			{
				if (ginfo->map.array[j + pos->y][i + pos->x] == ginfo->enemy)
					return (0);
				pos->value += ginfo->map.heat[j + pos->y][i + pos->x];
				if (ginfo->map.array[j + pos->y][i + pos->x] == ginfo->me)
					overlap++;
				if (overlap > 1)
					return (0);
			}
		}
	}
	return ((overlap == 1) ? 1 : 0);
}