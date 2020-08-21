/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalorin <esalorin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 19:47:54 by eenasalorin       #+#    #+#             */
/*   Updated: 2020/08/21 14:43:08 by esalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	conversion(t_data d, va_list ap)
{
	int		i;

	i = 0;
	if (d.sub[i] == 'c' || d.sub[i] == 's' || d.sub[i] == 'p')
		return (print_csp(d, ap));
	else if (d.sub[i] == 'd' || d.sub[i] == 'i' || d.sub[i] == 'o' ||
	d.sub[i] == 'u' || d.sub[i] == 'x' || d.sub[i] == 'X')
		return (print_dioux(d, ap));
	else if (d.sub[i] == 'f')
		return (print_double(d, ap));
	else
		return (printf_flags(d, ap));
}
