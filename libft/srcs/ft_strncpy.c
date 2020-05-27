/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenasalorinta <eenasalorinta@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 14:41:32 by esalorin          #+#    #+#             */
/*   Updated: 2020/04/30 17:22:22 by eenasalorin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t i;

	i = 0;
	while (i < len && dst && src && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	while (dst && i < len)
	{
		dst[i] = '\0';
		i++;
	}
	return (dst);
}
