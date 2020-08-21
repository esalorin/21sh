/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dioux.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalorin <esalorin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 22:05:01 by eenasalorin       #+#    #+#             */
/*   Updated: 2020/08/21 14:47:58 by esalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_base(char c)
{
	if (c == 'u')
		return (10);
	else if (c == 'o')
		return (8);
	else
		return (16);
}

static int	ft_print_oux(unsigned long long u, t_data d)
{
	char	*s;
	int		b;

	b = ft_check_base(d.conv);
	if (d.l == 1)
		s = ft_itoa_unsigned((unsigned long)u, b, d.conv);
	else if (d.ll == 1)
		s = ft_itoa_unsigned(u, b, d.conv);
	else if (d.h == 1)
		s = ft_itoa_base((unsigned short)u, b, d.conv);
	else if (d.hh == 1)
		s = ft_itoa_base((unsigned char)u, b, d.conv);
	else
		s = ft_itoa_unsigned((unsigned int)u, b, d.conv);
	if (!d.hash && !d.zero && !d.plus && !d.minus && !d.space && d.width == 1 &&
	(d.prec == -1 || (d.prec == 0 && s[0] != '0')))
	{
		ft_putstr_fd(s, d.fd);
		b = ft_strlen(s);
	}
	else
		b = check_oux(s, d);
	free(s);
	return (b);
}

static int	ft_print_di(long long n, t_data d)
{
	char	*s;
	int		res;

	if (d.l == 1)
		s = ft_itoa_base((long)n, 10, d.conv);
	else if (d.ll == 1)
		s = ft_itoa_base(n, 10, d.conv);
	else if (d.h == 1)
		s = ft_itoa_base((short)n, 10, d.conv);
	else if (d.hh == 1)
		s = ft_itoa_base((char)n, 10, d.conv);
	else
		s = ft_itoa_base((int)n, 10, d.conv);
	if (!d.hash && !d.zero && !d.plus && !d.minus && !d.space && d.width <= 1 &&
	(d.prec == -1 || (d.prec == 0 && s[0] != '0')))
	{
		ft_putstr_fd(s, d.fd);
		res = ft_strlen(s);
		free(s);
		return (res);
	}
	res = check_di(s, d);
	free(s);
	return (res);
}

int			print_dioux(t_data d, va_list ap)
{
	int					res;
	long long			n;
	unsigned long long	u;

	res = 0;
	if (d.conv == 'u' || d.conv == 'o' || d.conv == 'x' || d.conv == 'X')
	{
		u = va_arg(ap, unsigned long long);
		if (u == 0 && (d.hash == 1 && (d.conv == 'x' || d.conv == 'X')) &&
		d.width <= 1 && !d.prec)
			return (0);
		res = ft_print_oux(u, d);
	}
	else
	{
		n = va_arg(ap, long long);
		if (n == 0 && !d.plus && d.width <= 1 && !d.prec)
			return (0);
		res = ft_print_di(n, d);
	}
	return (res);
}
