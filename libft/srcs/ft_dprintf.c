/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalorin <esalorin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 17:50:25 by esalorin          #+#    #+#             */
/*   Updated: 2020/08/21 14:43:19 by esalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_dprintf(int fd, const char *format, ...)
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
			ret = ret + make_struct(format, fd, i, ap);
			i = i + temp;
			skip = skip + 1 + temp;
		}
		else if (format[i])
			ft_putchar_fd(format[i++], fd);
	}
	va_end(ap);
	return (((ret + i) - skip));
}
