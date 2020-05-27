/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenasalorinta <eenasalorinta@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 17:38:35 by esalorin          #+#    #+#             */
/*   Updated: 2020/05/02 14:57:42 by eenasalorin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		a;
	int		len;
	char	*str;

	i = 0;
	a = 0;
	len = ft_strlen(s) - 1;
	while (s && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		i++;
	while (s && (s[len] == ' ' || s[len] == '\n' || s[len] == '\t'))
		len--;
	len++;
	if (s && s[i] == '\0')
		len = i;
	str = (char *)malloc(sizeof(char) * (len - i + 1));
	if (str == NULL)
		return (NULL);
	while (s && i < len)
		str[a++] = s[i++];
	str[a] = '\0';
	return (str);
}
