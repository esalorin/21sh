/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalorin <esalorin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 20:32:53 by eenasalorin       #+#    #+#             */
/*   Updated: 2020/08/21 14:43:08 by esalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	check_precision(t_data *d, int i)
{
	if (d->sub[i] >= '0' && d->sub[i] <= '9')
		d->prec = ft_atoi(&d->sub[i]);
	else
		d->prec = 0;
}
