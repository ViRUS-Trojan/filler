/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdelsie <vdelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 03:47:01 by vdelsie           #+#    #+#             */
/*   Updated: 2020/02/02 17:51:48 by vdelsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	ft_get_coin(t_game *game)
{
    char	*line;

    get_next_line(0, &line);
    if (ft_strequ("$$$ exec p1 : [./vdelsie.filler]", line))
    //if (game->player_position == 1)
    {
        game->my_coin = 'O';
        game->opp_coin = 'X';
    }
    else if (ft_strequ("$$$ exec p2 : [./vdelsie.filler]", line))
    {
        game->my_coin = 'X';
        game->opp_coin = 'O';
    }
    else
    {
        ft_strdel(&line);
        return (-1);
    }
    ft_strdel(&line);
    return (0);
}

static int	ft_get_map_size(t_game *game)
{
	char	*start;
	char	*middle;
	char	*end;
	char	*nbr;
	char	*line;

	if (get_next_line(0, &line) == -1 || !line || ft_strncmp(line, BOARD, 7))
	{
		ft_strdel(&line);
		return (-1);
	}
	if (init_start_middle_end(line, &start, &middle, &end) == -1)
	{
		ft_strdel(&line);
		return (-1);
	}
	nbr = ft_strsub(start + 1, 0, middle - start + 1);
	game->h_map = ft_atoi(nbr);
	ft_strdel(&nbr);
	nbr = ft_strsub(middle + 1, 0, end - middle + 1);
	game->w_map = ft_atoi(nbr);
	ft_strdel(&nbr);
	ft_strdel(&line);
	return (0);
}

static void	ft_first_init_strat_map(t_game *game)
{
	int		i;

	game->strat_map = ft_memalloc(sizeof(*game->strat_map) * game->h_map);
	i = 0;
	while (i < game->h_map)
	{
		game->strat_map[i] = ft_memalloc(sizeof(**game->strat_map)
											* game->w_map);
		i++;
	}
}

int			ft_first_init(t_game *game)
{
	ft_bzero(game, sizeof(game));
	if (ft_get_coin(game) == -1)
		return (-1);
	if (ft_get_map_size(game) == -1)
		return (-1);
	game->gross_map = ft_memalloc(sizeof(*game->gross_map) *
				(game->h_map * game->w_map + game->h_map + 1));
	ft_first_init_strat_map(game);
	ft_init_debug(*game);
	return (0);
}
