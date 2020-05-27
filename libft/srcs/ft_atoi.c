/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenasalorinta <eenasalorinta@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 18:50:37 by esalorin          #+#    #+#             */
/*   Updated: 2020/05/02 14:57:12 by eenasalorin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int i;
	int res;
	int sign;

	i = 0;
	res = 0;
	sign = 1;
	while (str && (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' ||
		str[i] == '\f' || str[i] == '\r' || str[i] == '\v'))
		i++;
	if (str && str[i] == '-')
	{
		sign = -sign;
		i++;
	}
	else if (str && str[i] == '+')
		i++;
	while (str && str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - 48);
		i++;
	}
	return (res * sign);
}
