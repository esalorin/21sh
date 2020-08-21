/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_double.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalorin <esalorin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 14:29:31 by esalorin          #+#    #+#             */
/*   Updated: 2020/08/21 14:51:54 by esalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_print_more(char *s, t_data d, int res)
{
	int i;

	i = 0;
	if (d.minus)
		ft_putstr_fd(s, d.fd);
	if (d.zero && !d.minus)
	{
		if (s[i] == '-' || s[i] == '+' || s[i] == ' ')
			ft_putchar_fd(s[i++], d.fd);
		while (d.width > res++)
			write(d.fd, "0", 1);
		ft_putstr_fd(&s[i], d.fd);
	}
	if (!d.zero || d.minus)
	{
		while (d.width > res++)
			write(d.fd, " ", 1);
		if (!d.minus)
			ft_putstr_fd(s, d.fd);
	}
	return (res);
}

static int	ft_checkf(char *s, t_data d, int res)
{
	char	*s1;
	char	*s2;

	res = ft_strlen(s);
	s2 = NULL;
	s1 = NULL;
	if (d.plus&& s[0] != '-' && res++)
		s1 = ft_strjoin("+", s);
	else if (d.space && !d.plus && s[0] != '-' && res++)
		s1 = ft_strjoin(" ", s);
	s1 = (s1 == NULL) ? ft_strdup(s) : s1;
	if (d.hash && !(ft_strchr(s1, '.')) && res++)
		s2 = ft_strjoin(s1, ".");
	if (s2 == NULL)
		s2 = ft_strdup(s1);
	if (d.width <= res)
		ft_putstr_fd(s2, d.fd);
	if (d.width > res)
		res = ft_print_more(s2, d, res);
	free(s1);
	free(s2);
	return (res);
}

int			double_flags(t_data d, int i, va_list ap)
{
	d.prec = 6;
	check_flags(&d);
	check_width(&d);
	while (i-- > 0)
	{
		if (d.sub[i] == 'l' || d.sub[i] == 'L')
		{
			d.l = (d.sub[i] == 'l' && !d.ll) ? 1 : 0;
			d.ll = (d.sub[i] == 'L' && !d.l) ? 1 : 0;
		}
		if (d.sub[i] == '.')
			check_precision(&d, i + 1);
	}
	return (print_double(d, ap));
}

int			print_double(t_data d, va_list ap)
{
	long double	f;
	char		*s;
	int			res;

	res = 0;
	if (d.l || (!d.l && !d.ll))
	{
		f = va_arg(ap, double);
		s = ft_ftoa(f, d.prec);
	}
	else
	{
		f = va_arg(ap, long double);
		s = ft_ftoa(f, d.prec);
	}
	if (!d.hash && !d.zero && !d.plus && !d.minus && !d.space && !d.width &&
	d.prec == -1)
	{
		ft_putstr_fd(s, d.fd);
		res = ft_strlen(s);
	}
	else
		res = ft_checkf(s, d, res);
	free(s);
	return (res);
}
