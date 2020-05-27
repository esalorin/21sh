/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/27 15:15:46 by eenasalorin       #+#    #+#             */
/*   Updated: 2020/05/27 18:09:08 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

char	*ft_rmescapes_inquotes(char *s, char c)
{
	char	*des;
	int		i;
	int		j;

	if (!(des = ft_strnew(ft_strlen(s))))
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == BSLASH && (!count_slash(s, i) || (s[i + 1] == DQUOTE
		&& c == DQUOTE)))
			i++;
		else
			des[j++] = s[i++];
	}
	des[j] = '\0';
	ft_strdel(&s);
	return (des);
}

int		if_escape(char *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c && i > 0)
			count += (s[i - 1] == BSLASH) ? 1 : 0;
		i++;
	}
	return (count);
}

int		count_slash(char *s, int i)
{
	int	count;

	count = 0;
	while (i-- != 0 && s[i] == BSLASH)
		count++;
	return ((count % 2 == 0) ? 1 : 0);
}

int		quote_match(char *s)
{
	int		i;
	int		quotes;
	char	c;

	i = 0;
	quotes = 0;
	while (s[i])
	{
		if ((s[i] == DQUOTE || s[i] == SQUOTE) && count_slash(s, i))
		{
			c = s[i];
			quotes = 1;
			while (s[++i])
			{
				if (s[i] == c && (c == SQUOTE || (c == DQUOTE &&
				count_slash(s, i))))
				{
					quotes = 2;
					break ;
				}
			}
		}
		i += s[i] ? 1 : 0;
	}
	return ((quotes == 1) ? c : quotes);
}
