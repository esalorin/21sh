/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraydel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenasalorinta <eenasalorinta@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 19:08:00 by eenasalorin       #+#    #+#             */
/*   Updated: 2020/04/30 16:59:55 by eenasalorin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_arraydel(char **array)
{
	int	i;

	i = 0;
	while (array && array[i])
		ft_strdel(&array[i++]);
	if (array)
	{
		free(array);
		array = NULL;
	}
}
