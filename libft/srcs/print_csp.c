/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_csp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalorin <esalorin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 18:45:08 by esalorin          #+#    #+#             */
/*   Updated: 2020/08/21 14:47:37 by esalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_sp(char *s, t_data d)
{
	int		len;
	char	*s1;

	s1 = NULL;
	len = ft_strlen(s);
	if (len == 0 && !d.width)
		return (0);
	if ((d.prec > 0 || d.prec == -1) && len > d.prec)
	{
		if (d.prec == -1)
			s1 = ft_strnew(0);
		else
			s1 = ft_strsub(s, 0, d.prec);
		len = (d.prec == -1) ? 0 : d.prec;
	}
	s1 = (s1 == NULL) ? ft_strdup(s) : s1;
	if (d.minus)
		ft_putstr_fd(s1, d.fd);
	while (d.width > len++)
		write(d.fd, " ", 1);
	if (!d.minus)
		ft_putstr_fd(s1, d.fd);
	free(s1);
	return (len - 1);
}

static int	check_c(t_data d)
{
	int min2;

	min2 = (d.width == 0) ? 1 : d.width;
	if (d.width == 1 || d.width == 0)
		write(d.fd, &d.conv, 1);
	else
	{
		if (d.minus)
			write(d.fd, &d.conv, 1);
		while (--d.width > 0)
			write(d.fd, " ", 1);
		if (!d.minus)
			write(d.fd, &d.conv, 1);
	}
	return (min2);
}

int			csp_flags(t_data d, int l, va_list ap)
{
	d.prec = -2;
	d.conv = d.sub[l];
	while (l-- > 0)
	{
		if (d.sub[l] == '.')
		{
			check_precision(&d, l + 1);
			if (!d.prec)
				d.prec = -1;
		}
		else if (d.sub[l] == '-')
			d.minus = 1;
	}
	check_width(&d);
	if (d.conv == '%')
		return (check_c(d));
	return (print_csp(d, ap));
}

int			print_csp(t_data d, va_list ap)
{
	long long	res;
	char		*temp;
	char		*s;

	if (d.conv == 'c')
	{
		d.conv = va_arg(ap, int);
		res = check_c(d);
	}
	else if (d.conv == 's')
	{
		s = va_arg(ap, char*);
		s = (s == NULL) ? "(null)" : s;
		res = check_sp(s, d);
	}
	else
	{
		res = va_arg(ap, long long);
		temp = ft_itoa_base(res, 16, d.conv);
		s = ft_strjoin("0x", temp);
		res = check_sp(s, d);
		free(s);
		free(temp);
	}
	return (res);
}
