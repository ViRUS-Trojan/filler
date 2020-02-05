/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strat_argument.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdelsie <vdelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 16:38:52 by vdelsie           #+#    #+#             */
/*   Updated: 2020/02/05 21:55:47 by vdelsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	ft_top_player_adjustment(t_game *game)
{
	if (game->border.down == 1 && ft_check_the_down(*game))
	{
		game->border.up = 1;
		game->border.down = 0;
		ft_border_weight_from_up(game);
	}
	if (game->border.up == 1)
	{
		if (ft_check_the_up(*game) == 1)
		{
			ft_desactivate_border(game);
			game->border.up = 0;
		}
		else if (ft_check_the_up(*game) == -1)
		{
			game->border.up = 0;
			game->border.left = 1;
			ft_border_weight_from_left(game);
		}
	}
	if (game->border.left == 1 && ft_check_the_left(*game))
	{
		ft_desactivate_border(game);
		game->border.left = 0;
	}
}

static void	ft_down_player_adjustment(t_game *game)
{
	if (game->border.up == 1 && ft_check_the_up(*game))
	{
		game->border.down = 1;
		game->border.up = 0;
		ft_border_weight_from_down(game);
	}
	if (game->border.down == 1)
	{
		if (ft_check_the_down(*game) == 1)
		{
			ft_desactivate_border(game);
			game->border.down = 0;
		}
		else if (ft_check_the_down(*game) == -1)
		{
			game->border.down = 0;
			game->border.right = 1;
			ft_border_weight_from_right(game);
		}
	}
	if (game->border.right == 1 && ft_check_the_right(*game))
	{
		ft_desactivate_border(game);
		game->border.right = 0;
	}
}

void		ft_strat_adjustment(t_game *game)
{
	if (ft_border_is_activate(*game))
	{
		if (ft_is_top_player(*game))
			ft_top_player_adjustment(game);
		else
			ft_down_player_adjustment(game);
	}
}
