/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalorin <esalorin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 19:22:15 by eenasalorin       #+#    #+#             */
/*   Updated: 2020/08/21 14:43:45 by esalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	make_struct(const char *f, int fd, int i, va_list ap)
{
	t_data	d;
	int		j;

	j = i;
	ft_bzero((void*)&d, sizeof(t_data));
	d.fd = fd;
	d.prec = -1;
	while (f[j] && f[j] != 'd' && f[j] != 'i' && f[j] != 'o' && f[j] != 'u' &&
	f[j] != '%' && f[j] != 'x' && f[j] != 'X' && f[j] != 'f' && f[j] != 'c' &&
	f[j] != 's' && f[j] != 'p')
		j++;
	if (!f[j])
		return (0);
	d.sub = ft_strsub(f, i, (j - i + 1));
	j = conversion(d, ap);
	ft_strdel(&d.sub);
	return (j);
}
