/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdelsie <vdelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 03:44:59 by vdelsie           #+#    #+#             */
/*   Updated: 2020/01/30 03:45:16 by vdelsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


/*
** strdup используется для возврата цепочки malloc
*/

char	*ft_strtrim(char const *s)
{
	int		i;
	int		start;
	int		end;

	i = 0;
	start = 0;
	end = 0;
	if (!s)
		return (NULL);
	while (s[i] && (s[i] == '\n' || s[i] == ' ' || s[i] == '\t'))
		i++;
	if ((unsigned int)i == ft_strlen(s))
		return (ft_strdup("\0"));
	start = i;
	i = ft_strlen(s) - 1;
	while (i >= 0 && (s[i] == '\n' || s[i] == ' ' || s[i] == '\t'))
		i--;
	end = i;
	return (ft_strsub(s, start, end - start + 1));
}
