/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraydup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenasalorinta <eenasalorinta@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 20:26:19 by eenasalorin       #+#    #+#             */
/*   Updated: 2020/04/30 17:00:08 by eenasalorin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_arraydup(char **array)
{
	char	**des;
	int		i;

	i = 0;
	while (array && array[i])
		i++;
	des = (char**)malloc(sizeof(char*) * (i + 1));
	i = 0;
	while (array && array[i])
	{
		des[i] = ft_strdup(array[i]);
		i++;
	}
	des[i] = 0;
	return (des);
}
