/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalorin <esalorin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 16:33:22 by esalorin          #+#    #+#             */
/*   Updated: 2020/08/21 14:43:24 by esalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_printf(const char *format, ...)
{
	va_list ap;
	int		i;
	int		ret;
	int		skip;
	int		temp;

	skip = 0;
	i = 0;
	ret = 0;
	va_start(ap, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			temp = (format[++i]) ? ft_skip(&format[i]) : 0;
			ret = ret + make_struct(format, 1, i, ap);
			i = i + temp;
			skip = skip + 1 + temp;
		}
		else if (format[i])
			ft_putchar(format[i++]);
	}
	va_end(ap);
	return (((ret + i) - skip));
}
