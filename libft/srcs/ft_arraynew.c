/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraynew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenasalorinta <eenasalorinta@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 19:03:23 by eenasalorin       #+#    #+#             */
/*   Updated: 2020/03/20 19:05:31 by eenasalorin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_arraynew(size_t size)
{
	char	**array;
	size_t	i;

	i = 0;
	if (!(array = (char**)malloc(sizeof(char*) * (size + 1))))
		return (NULL);
	while (i < size)
		array[i++] = 0;
	array[i] = 0;
	return (array);
}
