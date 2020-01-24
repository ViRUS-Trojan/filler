/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdelsie <vdelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 14:31:57 by vdelsie           #+#    #+#             */
/*   Updated: 2020/01/24 15:01:02 by vdelsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libft/libft.h"

# define MAX_VALUE 2147483647

typedef struct	s_map
{
	int			width;
	int			height;
	char		**array;
	int			**heat;
}				t_map;

typedef struct	s_shape
{
	int			width;
	int			height;
	char		**array;
	int			width_r;
	int			height_r;
	int			x_offset;
	int			y_offset;
}				t_shape;

typedef struct	s_pos
{
	int			x;
	int			y;
	int			value;
}				t_pos;

typedef struct	s_ginfo
{
	int			player;
	char		me;
	char		enemy;
	t_map		map;
	t_shape		shape;
}				t_ginfo;

/*
** main.c
*/
int				main(void);
int				make_my_move(t_ginfo *ginfo);
void			give_answer(t_ginfo *ginfo);
int				try_this_pos(t_pos *pos, t_ginfo *ginfo);

/*
** read_input.c
*/
int				get_player_info(t_ginfo *ginfo);
int				read_map(t_map *map, char *line, t_ginfo *ginfo);
void			read_map_dimen(t_map *map, char *line);
int				read_shape(t_shape *shape);
void			read_shape_dimen(t_shape *shape);

/*
** heatmap.c
*/
void			build_heatmap(t_map *map, t_ginfo *ginfo);
void			populate_heat(t_map *map, t_ginfo *ginfo, int current);
void			set_neighbors(t_map *map, int i, int j, int new_val);

/*
** mini_shape.c
*/
void			mini_shape(t_shape *shape);
int				last_row_is_empty(t_shape *shape);
int				last_col_is_empty(t_shape *shape);

/*
** mini_shape_helper.c
*/
int				first_row_is_empty(t_shape *shape);
void			shift_up(t_shape *shape);
int				first_col_is_empty(t_shape *shape);
void			shift_left(t_shape *shape);
void			shift_down(t_shape *shape);

/*
** freedom.c
*/
void			free_all(t_ginfo *ginfo);
void			free_map(t_map *map);
void			free_shape(t_shape *shape);

/*
** debug.c
*/
void			print_player_info(t_ginfo *ginfo);
void			print_map(t_map *map);
void			print_heatmap(t_map *map);
void			print_shape(t_shape *shape);

#endif