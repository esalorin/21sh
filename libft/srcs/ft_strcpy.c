/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenasalorinta <eenasalorinta@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 13:56:06 by esalorin          #+#    #+#             */
/*   Updated: 2020/05/02 16:46:21 by eenasalorin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dst, const char *src)
{
	int i;

	i = 0;
	while (src && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst ? dst[i] = '\0' : 0;
	return (dst);
}
