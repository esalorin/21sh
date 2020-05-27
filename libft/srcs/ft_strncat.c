/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenasalorinta <eenasalorinta@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 11:43:50 by esalorin          #+#    #+#             */
/*   Updated: 2020/05/02 16:46:59 by eenasalorin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (s1 && s1[i] != '\0')
		i++;
	while (j < n && s2 && s2[j] != '\0')
	{
		s1[i] = s2[j];
		i++;
		j++;
	}
	s1 ? s1[i] = '\0' : 0;
	return (s1);
}
