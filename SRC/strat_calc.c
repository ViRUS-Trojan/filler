/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strat_calc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdelsie <vdelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 13:06:48 by vdelsie           #+#    #+#             */
/*   Updated: 2020/02/04 13:26:42 by vdelsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	ft_calc_global_weight(t_map *point, t_game game)
{
	int		max_heat;
	int		max_border;

	max_heat = ft_max(game.h_map, game.w_map) * 4;//// примерное значение 
	max_border = ft_max(game.h_map, game.w_map);
	point->weight = (game.coef_heat * point->heat / max_heat /////ТЕСТ проверим
					+ game.coef_border * point->border / max_border)
					* 100;
}

static void	ft_init_coef(t_game *game)
{
	if (ft_is_top_player(*game))
	{
		if (game->h_map <= SMALL_MAP_MAX_H || game->w_map <= SMALL_MAP_MAX_W)
			ft_activate_heat(game);
		else
		{
			game->border.down = 1;
			//ft_border_weight_from_down(game);
			ft_activate_border(game);
		}
	}
	else
	{
		game->border.up = 1;
		//ft_border_weight_from_up(game);
		ft_activate_border(game);
	}
}

static void	ft_get_position(t_game *game)
{
	char	*tmp;

	tmp = game->gross_map;
	while (*tmp)
	{
		if (ft_is_me(*game, *tmp))
		{
			game->player_position = 1;
			break ;
		}
		if (ft_is_opp(*game, *tmp))
		{
			game->player_position = -1;
			break ;
		}
		tmp++;
	}
}

void		ft_strat_map_calc(t_game *game)
{
	int		i;
	int		j;

	if (!game->player_position)
	{
		ft_get_position(game);
		ft_init_coef(game);
	}
	if (ft_heat_is_activate(*game))
		ft_calc_heat_weight(game);
	i = 0;
	while (i < game->h_map)
	{
		j = 0;
		while (j < game->w_map)
		{
			if (!ft_is_opp(*game, game->strat_map[i][j].value))
				ft_calc_global_weight(&game->strat_map[i][j], *game);
			j++;
		}
		i++;
	}
}