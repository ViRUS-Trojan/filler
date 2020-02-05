/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   border_calc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdelsie <vdelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 17:33:23 by vdelsie           #+#    #+#             */
/*   Updated: 2020/02/05 21:59:24 by vdelsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_border_weight_from_down(t_game *game)
{
	int		i;
	int		j;
	int		value;
	int		max_border;

	max_border = ft_max(game->h_map, game->w_map);
	i = game->h_map - 1;
	value = max_border;
	while (i >= 0)
	{
		j = 0;
		while (j < game->w_map)
		{
			game->strat_map[i][j].border = value;
			j++;
		}
		i--;
		value--;
	}
}

void	ft_border_weight_from_right(t_game *game)
{
	int		i;
	int		j;
	int		value;
	int		max_border;

	max_border = ft_max(game->h_map, game->w_map);
	j = game->w_map - 1;
	value = max_border;
	while (j >= 0)
	{
		i = 0;
		while (i < game->h_map)
		{
			game->strat_map[i][j].border = value;
			i++;
		}
		j--;
		value--;
	}
}

void	ft_border_weight_from_left(t_game *game)
{
	int		i;
	int		j;
	int		value;
	int		max_border;

	max_border = ft_max(game->h_map, game->w_map);
	j = 0;
	value = max_border;
	while (j < game->w_map)
	{
		i = 0;
		while (i < game->h_map)
		{
			game->strat_map[i][j].border = value;
			i++;
		}
		j++;
		value--;
	}
}

void	ft_border_weight_from_up(t_game *game)
{
	int		i;
	int		j;
	int		value;
	int		max_border;

	max_border = ft_max(game->h_map, game->w_map);
	i = 0;
	value = max_border;
	while (i < game->h_map)
	{
		j = 0;
		while (j < game->w_map)
		{
			game->strat_map[i][j].border = value;
			j++;
		}
		i++;
		value--;
	}
}