/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_shape.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdelsie <vdelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 14:52:30 by vdelsie           #+#    #+#             */
/*   Updated: 2020/01/22 12:53:11 by vdelsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void    mini_shape(t_shape *shape)
{
    shape->width_r = shape->width;
    shape->height_r = shape->height;
    shape->x_offset = 0;
    shape->y_offset = 0;
    while(last_col_is_empty(shape))
        shape->width_r--;
    while(last_row_is_empty(shape))
        shape->height_r--;
    while(first_col_is_empty(shape))
    {
        shift_left(shape);
        shape->width_r--;
        shape->x_offset--;
    }
    while(first_row_is_empty(shape))
    {
        shift_up(shape);
        shape->height_r--;
        shape->y_offset--;
    }
    
}

int     last_row_is_empty(t_shape *shape)
{
    int i;

    i = -1;
    while(++i < shape->width)
    {
        if (shape->array[shape->height_r - 1][i] == '*')
        return(0);
    }
    return(1);
}

int     last_col_is_empty(t_shape *shape)
{
    int j;

    j = -1;
    while(++j < shape->height)
    {
        if(shape->array[j][shape->width_r - 1] == '*')
        return(0);
    }
    return(1);
}