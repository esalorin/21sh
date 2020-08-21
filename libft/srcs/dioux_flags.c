/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dioux_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalorin <esalorin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 14:22:59 by esalorin          #+#    #+#             */
/*   Updated: 2020/08/21 14:43:08 by esalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			dioux_flags(t_data d, int i, va_list ap)
{
	int	l;
	int	h;

	l = 0;
	h = 0;
	d.conv = d.sub[i];
	check_flags(&d);
	check_width(&d);
	while (i-- > 0)
	{
		if (d.sub[i] == '.')
			check_precision(&d, i + 1);
		else if (d.sub[i] == 'l' && !h)
			l++;
		else if (d.sub[i] == 'h' && !l)
			h++;
	}
	d.l = (l == 1) ? 1 : 0;
	d.ll = (l > 1) ? 1 : 0;
	d.h = (h == 1) ? 1 : 0;
	d.hh = (h > 1) ? 1 : 0;
	return (print_dioux(d, ap));
}
