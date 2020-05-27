/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rmescapes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenasalorinta <eenasalorinta@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/28 14:49:31 by eenasalorin       #+#    #+#             */
/*   Updated: 2020/04/30 17:13:05 by eenasalorin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_rmescapes(char *s)
{
	char	*des;
	int		i;
	int		j;

	i = -1;
	j = 0;
	while (s && s[++i])
		j += (s[i] == 92 && s[i + 1] != 92) ? 1 : 0;
	if (!(des = (char*)malloc(sizeof(char) * (ft_strlen(s) - j))))
		return (NULL);
	i = 0;
	j = 0;
	while (s && s[i])
	{
		if (s[i] != 92 || (s[i] == 92 && s[i + 1] == 92))
			des[j++] = s[i];
		i += (s[i] == 92 && s[i + 1] == 92) ? 2 : 1;
	}
	des[j] = '\0';
	return (des);
}
