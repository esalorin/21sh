/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalorin <esalorin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 17:38:44 by esalorin          #+#    #+#             */
/*   Updated: 2020/08/21 14:43:45 by esalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_skip(const char *f)
{
	int	skip;

	skip = 1;
	while (*f != '\0' && (*f != 'd' && *f != 'i' && *f != 'o' && *f != 'u'
		&& *f != 'x' && *f != 'X' && *f != 'f' && *f != 'c' && *f != 's'
		&& *f != 'p' && *f != '%'))
	{
		skip++;
		f++;
	}
	return ((*f == '\0') ? skip - 1 : skip);
}
