/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalorin <esalorin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 17:37:15 by esalorin          #+#    #+#             */
/*   Updated: 2020/08/21 14:43:45 by esalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	printf_flags(t_data d, va_list ap)
{
	int i;
	int res;

	res = 0;
	i = ft_strlen(d.sub) - 1;
	if (d.sub[i] == 'd' || d.sub[i] == 'i' || d.sub[i] == 'o' || d.sub[i] == 'u'
		|| d.sub[i] == 'x' || d.sub[i] == 'X')
		res = dioux_flags(d, i, ap);
	else if (d.sub[i] == 'f')
		res = double_flags(d, i, ap);
	else if (d.sub[i] == 'c' || d.sub[i] == '%' || d.sub[i] == 's' || d.sub[i] == 'p')
		res = csp_flags(d, i, ap);
	return (res);
}
