/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_state_list_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdelsie <vdelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 17:20:01 by vdelsie           #+#    #+#             */
/*   Updated: 2020/02/09 17:21:48 by vdelsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include "filler_vizual.h"

t_gslst	*gs_lstnew(t_game *game, int turn_switch)
{
	t_gslst *new;

	if ((new = (t_gslst *)malloc(sizeof(*new))) == NULL)
		return (NULL);
	new->flags = 0;
	new->flags |= (turn_switch) ? TURN_SWITCH : 0;
	new->piece_w = 0;
	new->piece_h = 0;
	new->piece_x = 0;
	new->piece_y = 0;
	new->turn = 0;
	new->board = NULL;
	new->color_tab = NULL;
	new->piece = NULL;
	new->prev = NULL;
	new->next = NULL;
	new->p1_pts = game->p1_rt;
	new->p2_pts = game->p2_rt;
	if (turn_switch == 0)
	{
		new->board = (char **)malloc((game->h + 1) * sizeof(char *));
		new->color_tab = (short *)malloc((game->h * game->w) * sizeof(short));
		ft_bzero(new->color_tab, (game->h * game->w) * sizeof(short));
	}
	return (new);
}

void	gs_lstadd(t_gslst **gss, t_gslst *new)
{
	if (gss && new)
	{
		if (*gss)
		{
			(*gss)->next = new;
			new->prev = *gss;
		}
		*gss = new;
	}
}
