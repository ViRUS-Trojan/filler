/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   border_clear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdelsie <vdelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 03:46:07 by vdelsie           #+#    #+#             */
/*   Updated: 2020/01/30 03:46:08 by vdelsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_clear_border_weight(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	while (i < game->h_map)
	{
		j = 0;
		while (j < game->w_map)
		{
			game->strat_map[i][j].border = 0;
			j++;
		}
		i++;
	}
}
