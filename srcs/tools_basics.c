/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_basics.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdelsie <vdelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 15:02:04 by vdelsie           #+#    #+#             */
/*   Updated: 2020/02/01 15:02:05 by vdelsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		ft_min(int a, int b)
{
	return (a <= b ? a : b);
}

int		ft_max(int a, int b)
{
	return (a >= b ? a : b);
}
