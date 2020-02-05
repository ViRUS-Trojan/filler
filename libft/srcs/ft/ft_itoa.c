/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdelsie <vdelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 03:40:06 by vdelsie           #+#    #+#             */
/*   Updated: 2020/01/30 03:40:20 by vdelsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Si n est nul, ne pas renvoyer juste "0" sinon le char* retourné ne sera pas
** mallocé
*/

char			*ft_itoa(int n)
{
	char	*str;
	int		size;

	size = ft_intlen(n);
	str = ft_strnew(size);
	size--;
	str[0] = '0';
	if (n < 0)
		*str = '-';
	while (n != 0)
	{
		if (n < 0)
			str[size--] = '0' - n % 10;
		else
			str[size--] = '0' + n % 10;
		n = n / 10;
	}
	return (str);
}
