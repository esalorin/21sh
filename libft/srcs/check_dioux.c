/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dioux.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalorin <esalorin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 18:46:16 by esalorin          #+#    #+#             */
/*   Updated: 2020/08/21 14:48:39 by esalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_dioux(char *s, t_data d)
{
	int res;
	int	i;

	i = 0;
	res = ft_strlen(s);
	if (d.minus)
		ft_putstr_fd(s, d.fd);
	if (d.zero && !d.minus && d.prec == -1)
	{
		if (s[i] == ' ' || s[i] == '+' || s[i] == '-' || s[1] == 'x' || s[1]
		== 'X')
			ft_putchar_fd(s[i++], d.fd);
		(s[1] == 'x' || s[1] == 'X') ? ft_putchar_fd(s[i++], d.fd) : 1;
		while (d.width > res++)
			write(d.fd, "0", 1);
	}
	if (!d.zero || d.minus || d.prec > 0)
	{
		while (d.width > res++)
			write(d.fd, " ", 1);
	}
	if (!d.minus)
		ft_putstr_fd(&s[i], d.fd);
	free(s);
	return (res - 1);
}

static char	*ft_maketemp(int n, int i)
{
	char	*s;
	int		len;

	len = n + i;
	s = ft_strnew(len);
	while (len-- > i)
		s[len] = '0';
	if (i == 1)
		s[0] = '-';
	return (s);
}

int			check_oux(char *s, t_data d)
{
	char	*s1;
	char	*s2;
	char	*temp;
	int		len;

	s1 = NULL;
	s2 = NULL;
	if (!d.prec && s[0] == '0')
		s[0] = '\0';
	if (d.hash && d.conv == 'o' && s[0] != '0')
		s1 = ft_strjoin("0", s);
	s1 = (s1 == NULL) ? ft_strdup(s) : s1;
	if (d.prec > (len = ft_strlen(s1)))
	{
		temp = ft_maketemp(d.prec - len, 0);
		s2 = ft_strjoin(temp, s1);
		ft_strdel(&temp);
	}
	s2 = (s2 == NULL) ? ft_strdup(s1) : s2;
	if (d.hash && (d.conv == 'x' || d.conv == 'X') && s1[0] != '0' && s1[0] != '\0')
		temp = ft_strjoin(((d.conv == 'x') ? "0x" : "0X"), s2);
	temp = (temp == NULL) ? ft_strdup(s2) : temp;
	free(s1);
	free(s2);
	return (ft_check_dioux(temp, d));
}

int			check_di(char *s, t_data d)
{
	char	*s1;
	char	*temp;
	int		len;
	int		i;

	s1 = NULL;
	if (!d.prec && s[0] == '0')
		s[0] = '\0';
	i = (s[0] == '-') ? 1 : 0;
	if (d.prec > (len = ft_strlen(&s[i])))
	{
		temp = ft_maketemp(d.prec - len, i);
		s1 = ft_strjoin(temp, &s[i]);
		free(temp);
	}
	temp = NULL;
	s1 = (s1 == NULL) ? ft_strdup(s) : s1;
	if (d.plus && s[0] != '-')
		temp = ft_strjoin("+", s1);
	if (d.space && !d.plus && s[0] != '-')
		temp = ft_strjoin(" ", s1);
	temp = (temp == NULL) ? ft_strdup(s1) : temp;
	free(s1);
	return (ft_check_dioux(temp, d));
}
