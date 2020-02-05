/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countwords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdelsie <vdelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 03:37:55 by vdelsie           #+#    #+#             */
/*   Updated: 2020/01/30 03:37:56 by vdelsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_countwords(char const *s, char c)
{
	int		cpt;

	cpt = 0;
	if (!s)
		return (cpt);
	while (*s)
	{
		if (*s != c)
		{
			cpt++;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	return (cpt);
}
